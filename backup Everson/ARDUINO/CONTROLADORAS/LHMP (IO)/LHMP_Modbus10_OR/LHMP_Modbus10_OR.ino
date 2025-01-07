// *** PLACA LHMP - Coontrole de Iluminação ***
//************** VERSÃO 1.0 *********************
// ********* ATUALIZAÇÃO 03/11/16 **************



#include <SPI.h>
#include <SD.h>
#include <TimerOne.h>
#include <Ethernet.h>
#include "MgsModbus.h"



// INICIO: Variaveis usadas na rotina modbus
MgsModbus Mb;
// FIM: Variaveis usadas na rotina modbus


// INICIO: Variaveis usadas para ethernet
uint8_t mac[] = { 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x2A };
uint8_t ip[] = { 192, 168, 11, 202 };
uint8_t subnet[] = { 255, 255, 255, 0 };
uint8_t gateway[] = { 192, 168, 11, 1 };
uint8_t dns_server[] = { 192, 168, 11, 1 };
// FIM: Variaveis usadas para ethernet


// INICIO: Variaveis para trigger
word Trigger_ed;
word memTrigger_ed;
word Trigger_edv;
word memTrigger_edv;
word Trigger1;
word Trigger_Trigger1;
word memTrigger_Trigger1;
// FIM: Variaveis para trigger


// INICIO: Variaveis usadas na rotina de disparo do dimmer
int dimmer_preset[16];
int dimmer_atual[16];
int dimmer_acc;
#define dimmer_Scan 417
//#define dimmer_Scan 209
#define dimmer_max round((8333.0/dimmer_Scan)*05/100) // disparo maximo a partir de 10% do inicio da onda
#define dimmer_min round((8333.0/dimmer_Scan)*85/100) // disparo minimo ate 85% do inicio da onda
// FIM: Variaveis usadas na rotina de disparo do dimmer


// INICIO: Variaveis diversas
word bit_mask1[16] = { 0x0001, 0x0002, 0x0004, 0x0008, 0x0010, 0x0020, 0x0040, 0x0080, 0x0100, 0x0200, 0x0400, 0x0800, 0x1000, 0x2000, 0x4000, 0x8000 };
word bit_mask2[16] = { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 };
#define pre_tmr10ms_acc round(10000.0/dimmer_Scan)
int tmr10ms_acc = pre_tmr10ms_acc; // 24 * 417 = ~10ms   417 vem do Timer1
bool clock_10ms;
bool mem;
struct dt_timer
{
	int preset;
	int efetivo;
	bool enable;
	bool done;
	bool timing;
	bool reset;
};
dt_timer timer[32];
// FIM: Variaveis diversas


// Atalho para os registros do modbus

// Regiao de leitura
#define modbus_ed            Mb.MbData[0]   // R
#define modbus_sd            Mb.MbData[1]   // RW
#define modbus_edv           Mb.MbData[2]   // W
#define modbus_efeDimmerS01  Mb.MbData[3]   // RW
#define modbus_efeDimmerS02  Mb.MbData[4]   // RW
#define modbus_efeDimmerS03  Mb.MbData[5]   // RW
#define modbus_efeDimmerS04  Mb.MbData[6]   // RW
#define modbus_efeDimmerS05  Mb.MbData[7]   // RW
#define modbus_efeDimmerS06  Mb.MbData[8]   // RW
#define modbus_efeDimmerS07  Mb.MbData[9]   // RW
#define modbus_efeDimmerS08  Mb.MbData[10]   // RW
#define modbus_efeDimmerS09  Mb.MbData[11]   // RW
#define modbus_efeDimmerS10  Mb.MbData[12]   // RW
#define modbus_efeDimmerS11  Mb.MbData[13]   // RW
#define modbus_efeDimmerS12  Mb.MbData[14]   // RW
#define modbus_efeDimmerS13  Mb.MbData[15]   // RW
#define modbus_efeDimmerS14  Mb.MbData[16]   // RW
#define modbus_efeDimmerS15  Mb.MbData[17]   // RW
#define modbus_efeDimmerS16  Mb.MbData[18]   // RW
#define modbus_cmdAuxiliar1  Mb.MbData[19]   // W
#define modbus_cmdAuxiliar2  Mb.MbData[20]   // W
#define modbus_cmdAuxiliar3  Mb.MbData[21]   // W
#define modbus_cmdAuxiliar4  Mb.MbData[22]   // W
#define modbus_cfgLinkIO     Mb.MbData[23]   // R
#define modbus_cfgNobreak    Mb.MbData[24]   // R
#define modbus_cfgDimmer     Mb.MbData[25]   // R

void setup()
{
	Serial.begin(9600);


  // Configuracao padrao caso nao consiga ler o cartao SD
  modbus_cfgLinkIO = 0xFFFF;
  modbus_cfgDimmer = 0x0000;  //ORIGINAL: FF00
  modbus_sd = 0x0000;

  
	// Desabilita a ethernet e habilita o cartao SD
	pinMode(10, OUTPUT);
	pinMode(4, OUTPUT);
	digitalWrite(10, HIGH);
	digitalWrite(4, LOW);

	// Le a configuracao no cartao SD
	LerConfiguracao();

	// Desabilita o cartao SD e habilita a ethernet
	digitalWrite(4, HIGH);
	digitalWrite(10, LOW);

	// Inicializa ethernet
	Ethernet.begin(mac, ip, dns_server, gateway, subnet);

	// Configura PORTL.2 como entrada e restante do PORTL como sa�da
	DDRL = B11111011;

	// Configura a interrupcao do pino 2 para Detecao da borda de subida do Zero Crossing
	attachInterrupt(0, zero_cross_detect, RISING);

	// Desabilita interrupcao do Timer0
	TIMSK0 &= ~_BV(TOIE0); 

	// Configura a interrupcao do Timer1 para 417us (~1/60Hz/2/20 = 20 niveis para o dimmer)
	Timer1.attachInterrupt(int_timer);
	Timer1.initialize(dimmer_Scan);



	Serial.print("dimmer_Scan: ");
	Serial.println(dimmer_Scan);

	Serial.print("dimmer_min: ");
	Serial.println(dimmer_min);

	Serial.print("dimmer_max: ");
	Serial.println(dimmer_max);

	Serial.print("pre_tmr10ms_acc: ");
	Serial.println(pre_tmr10ms_acc);

}


void loop()
{
 switch(modbus_cmdAuxiliar1)
  {
    case 1:
      bitClear(modbus_sd, 0);
      break;
    case 2:
      bitClear(modbus_sd, 1);
      break;
    case 3:
      bitClear(modbus_sd, 2);
      break;
    case 4:
      bitClear(modbus_sd, 3);
      break;
    case 5:
      bitClear(modbus_sd, 4);
      break;
    case 6:
      bitClear(modbus_sd, 5);
      break;
    case 7:
      bitClear(modbus_sd, 6);
      break;
    case 8:
      bitClear(modbus_sd, 7);
      break;
    case 9:
      bitClear(modbus_sd, 8);
      break;
    case 10:
      bitClear(modbus_sd, 9);
      break;
    case 11:
      bitClear(modbus_sd, 10);
      break;
    case 12:
      bitClear(modbus_sd, 11);
      break;
    case 13:
      bitClear(modbus_sd, 12);
      break;
    case 14:
      bitClear(modbus_sd, 13);
      break;
    case 15:
      bitClear(modbus_sd, 14);
      break;
    case 16:
      bitClear(modbus_sd, 15);
      break;

    case 101:
      bitSet(modbus_sd, 0);
      break;
    case 102:
      bitSet(modbus_sd, 1);
      break;
    case 103:
      bitSet(modbus_sd, 2);
      break;
    case 104:
      bitSet(modbus_sd, 3);
      break;
    case 105:
      bitSet(modbus_sd, 4);
      break;
    case 106:
      bitSet(modbus_sd, 5);
      break;
    case 107:
      bitSet(modbus_sd, 6);
      break;
    case 108:
      bitSet(modbus_sd, 7);
      break;
    case 109:
      bitSet(modbus_sd, 8);
      break;
    case 110:
      bitSet(modbus_sd, 9);
      break;
    case 111:
      bitSet(modbus_sd, 10);
      break;
    case 112:
      bitSet(modbus_sd, 11);
      break;
    case 113:
      bitSet(modbus_sd, 12);
      break;
    case 114:
      bitSet(modbus_sd, 13);
      break;
    case 115:
      bitSet(modbus_sd, 14);
      break;
    case 116:
      bitSet(modbus_sd, 15);
      break;
  }
    modbus_cmdAuxiliar1 = 0;

// Seta valor do dimmer
 switch(modbus_cmdAuxiliar3)
  {
    case 1:
      modbus_efeDimmerS01 = modbus_cmdAuxiliar4 ;
      break;
    case 2:
      modbus_efeDimmerS02 = modbus_cmdAuxiliar4 ;
      break;
    case 3:
      modbus_efeDimmerS03 = modbus_cmdAuxiliar4 ;
      break;
    case 4:
      modbus_efeDimmerS04 = modbus_cmdAuxiliar4 ;
      break;
    case 5:
      modbus_efeDimmerS05 = modbus_cmdAuxiliar4 ;
      break;
    case 6:
      modbus_efeDimmerS06 = modbus_cmdAuxiliar4 ;
      break;
    case 7:
      modbus_efeDimmerS07 = modbus_cmdAuxiliar4 ;
      break;
    case 8:
      modbus_efeDimmerS08 = modbus_cmdAuxiliar4 ;
      break;
    case 9:
      modbus_efeDimmerS09 = modbus_cmdAuxiliar4 ;
      break;
    case 10:
      modbus_efeDimmerS10 = modbus_cmdAuxiliar4 ;
      break;
    case 11:
      modbus_efeDimmerS11 = modbus_cmdAuxiliar4 ;
      break;
    case 12:
      modbus_efeDimmerS12 = modbus_cmdAuxiliar4 ;
      break;
    case 13:
      modbus_efeDimmerS13 = modbus_cmdAuxiliar4 ;
      break;
    case 14:
      modbus_efeDimmerS14 = modbus_cmdAuxiliar4 ;
      break;
    case 15:
      modbus_efeDimmerS15 = modbus_cmdAuxiliar4 ;
      break;
    case 16:
      modbus_efeDimmerS16 = modbus_cmdAuxiliar4 ;
      break;
                        
  }
//    modbus_cmdAuxiliar3 = 0;
//    modbus_cmdAuxiliar4 = 0;

  
  	// Executa comunicacao modbus
	static int i = 10;
	if (i == 0)
	{
		//bitWrite(PORTL, 7, 1);
		Mb.MbsRun();
		//bitWrite(PORTL, 7, 0);
		i = 10;
	}
	else i--;

	// Atualiza entradas digitais
	modbus_ed = EntradasDigitais();

	// Rotina dos 32 temporizadores auxiliares
	timer_10ms();

	// Rotina do trigger
	Trigger();

	// Ativacao das saidas digitais
	Aticavao();

	// Conversao de escala para dimmer
	static int j = 15;
	//dimmer_preset[j] = int(map(Mb.MbData[j + 6], 0, 100, 20, 0));
	dimmer_preset[j] = int(map(Mb.MbData[j + 3], 0, 100, dimmer_min, dimmer_max));
	if (j == 0) j = 15;
	else j--;


	// Temporizador 50ms
	timer[0].preset = 5;
	timer[0].reset = 0;
	timer[0].enable = !timer[0].done;

	// Rampa do dimmer ao ligar
	if (timer[0].done)
	{
		for (int x = 15; x >= 0; x--)
		{
			if (bitRead(modbus_sd, x))
			{
				if (dimmer_atual[x] < dimmer_preset[x]) dimmer_atual[x]++;
				if (dimmer_atual[x] > dimmer_preset[x]) dimmer_atual[x]--;
			}
			else dimmer_atual[x] = dimmer_min;
		}
	}
}


// ************************************************************************************************
// ************************************* ROTINAS CONSOLIDADAS *************************************
// ************************************************************************************************

void timer_10ms()
{
	for (int i = 31; i >= 0; i--)
	{
		// Efetivo >= Preset
		if (timer[i].efetivo >= timer[i].preset)
		{
			timer[i].done = 1;
			timer[i].timing = 0;
		}
		else
			// Efetivo < Preset
		{
			timer[i].done = 0;
			timer[i].timing = 1;
		}


		// Reset ou sem enable
		if (timer[i].reset || !timer[i].enable)
		{
			timer[i].efetivo = 0;
			timer[i].done = 0;
			timer[i].timing = 0;
		}
	}
}

void int_timer()
{
	//bitWrite(PORTL, 6, 1);

	word gate = 0x0000;
	for (int i = 15; i >= 0; i--)
	{
		 //Verifica se aciona o gate ('else' apenas para manter repetibilidade, aumenta ~10us o 'for' mas melhora em ~10us a repetibilidade)
		if (dimmer_acc == dimmer_atual[i]) gate |= bit_mask1[i];
		else gate |= bit_mask2[i];
		
	}
	//bitWrite(PORTL, 6, 0);

	// Isola saidas nao dimerizadas que estao ligadas
	word sd_SemDimmerLigadas = ~(modbus_cfgDimmer)& modbus_sd;

	// Isola saidas dimerizadas que estao ligadas
	word sd_ComDimmerLigadas = modbus_cfgDimmer & modbus_sd;

	// Ligas as saidas com dimmer de acordo com o gate
	gate &= sd_ComDimmerLigadas;

	// Atualiza o IO fisico das saidas nao dimerizadas e dimerizadas (de acordo com o gate)
	SaidasDigitais(gate | sd_SemDimmerLigadas);

	// Incrementa contador do dimmer
	dimmer_acc++;

	//bitWrite(PORTL, 6, 0);

	// Temporizador 10ms
	tmr10ms_acc -= 1;
	if (tmr10ms_acc == 0)
	{
		tmr10ms_acc =  pre_tmr10ms_acc;
		clock_10ms = !clock_10ms;

		// Incrementa efetivo dos 32 temporizadores auxiliares
		for (int i = 31; i >= 0; i--) if ((timer[i].enable) && timer[i].timing) timer[i].efetivo += 1;
	}

	//bitWrite(PORTL, 6, 0);
	
}

void zero_cross_detect()
{
	// Inicializa o Timer1
	if (dimmer_acc > 5) // debouncing da detec��o do zero
	{
		//bitWrite(PORTL, 7, 1);
		dimmer_acc = 0;
		Timer1.start();
		//bitWrite(PORTL, 7, 0);
	}
}

bool LerConfiguracao()
{
	if (!SD.begin(4))
	{
		Serial.println("ERRO: SD.begin() falhou.");
		return(0);
	}

	File myFile;
	myFile = SD.open("config.ini", FILE_READ);
	if (!myFile)
	{
		Serial.println("ERRO: Arquivo de inicializacao nao encontrado.");
	}
	else
	{
		String Linha;
		char aux;
		while (myFile.available())
		{
			// Le uma linha inteira
			Linha = myFile.readStringUntil('\n');

			// Interpreta a linha se ela nao for um comentario
			if (Linha[0] != ';')
			{
				// Verifica o numero do parametro
				int par = Linha.substring(3, 5).toInt();
				switch (par)
				{

					// Par01 = ip
				case 01:
					ip[0] = Linha.substring(8, 11).toInt();
					ip[1] = Linha.substring(12, 15).toInt();
					ip[2] = Linha.substring(16, 19).toInt();
					ip[3] = Linha.substring(20, 23).toInt();
					Serial.println(String("Par01-IP=") + ip[0] + "." + ip[1] + "." + ip[2] + "." + ip[3]);
					break;

					// Par02 = subnet
				case 02:
					subnet[0] = Linha.substring(8, 11).toInt();
					subnet[1] = Linha.substring(12, 15).toInt();
					subnet[2] = Linha.substring(16, 19).toInt();
					subnet[3] = Linha.substring(20, 23).toInt();
					Serial.println(String("Par02-Subnet=") + subnet[0] + "." + subnet[1] + "." + subnet[2] + "." + subnet[3]);
					break;

					// Par03 = gateway
				case 03:
					gateway[0] = Linha.substring(8, 11).toInt();
					gateway[1] = Linha.substring(12, 15).toInt();
					gateway[2] = Linha.substring(16, 19).toInt();
					gateway[3] = Linha.substring(20, 23).toInt();
					Serial.println(String("Par03-Gateway=") + gateway[0] + "." + gateway[1] + "." + gateway[2] + "." + gateway[3]);
					break;

					// Par04 = DNS
				case 04:
					dns_server[0] = Linha.substring(8, 11).toInt();
					dns_server[1] = Linha.substring(12, 15).toInt();
					dns_server[2] = Linha.substring(16, 19).toInt();
					dns_server[3] = Linha.substring(20, 23).toInt();
					Serial.println(String("Par04-DNS=") + dns_server[0] + "." + dns_server[1] + "." + dns_server[2] + "." + dns_server[3]);
					break;

					// Par05 = mac address
				case 05:
					mac[0] = Linha.substring(8, 11).toInt();
					mac[1] = Linha.substring(12, 15).toInt();
					mac[2] = Linha.substring(16, 19).toInt();
					mac[3] = Linha.substring(20, 23).toInt();
					mac[4] = Linha.substring(24, 27).toInt();
					mac[5] = Linha.substring(28, 31).toInt();
					Serial.println(String("Par05 - MAC = ") + mac[0] + ":" + mac[1] + ":" + mac[2] + ":" + mac[3] + ":" + mac[4] + ":" + mac[5]);
					break;


					// Par11~26 = configuracao das saidas
				case 11:
				case 12:
				case 13:
				case 14:
				case 15:
				case 16:
				case 17:
				case 18:
				case 19:
				case 20:
				case 21:
				case 22:
				case 23:
				case 24:
				case 25:
				case 26:
					bitWrite(modbus_cfgLinkIO, par - 11, Linha.substring(8, 9).toInt());
					bitWrite(modbus_cfgNobreak, par - 11, Linha.substring(9, 10).toInt());
					bitWrite(modbus_cfgDimmer, par - 11, Linha.substring(10, 11).toInt());
					Serial.println(String("Par") + par + " - cfgSaida" + (par - 11) + " = " + bitRead(modbus_cfgLinkIO, par - 11) + bitRead(modbus_cfgNobreak, par - 11) + bitRead(modbus_cfgDimmer, par - 11));
					break;
				default:
					break;
				}
				//Serial.println(Linha);
			}
		}
	}
	myFile.close();
}

void Aticavao()
{
	for (int i = 15; i >= 0; i--)
	{
		// Da um toogle na saida de acordo com edv e ed (verifica cfgLinkIO)
		if (bitRead(Trigger_edv, i) || (bitRead(Trigger_ed, i) && bitRead(modbus_cfgLinkIO, i))) bitWrite(modbus_sd, i, !bitRead(modbus_sd, i));
    bitWrite(modbus_edv, i, false);
    
		// Desliga a saida na falta de ac (verifica cfgNobreak)
		//if (falta_ac && !bitRead(modbus_cfgNobreak, i)) bitWrite(modbus_sd, i, false);
	}
}

void Trigger()
{
	// Trigger na ed e edv
	for (int i = 15; i >= 0; i--)
	{
		// Trigger ed
		if ((bitRead(modbus_ed, i)) && (!bitRead(memTrigger_ed, i))) bitWrite(Trigger_ed, i, true);
		else bitWrite(Trigger_ed, i, false);

		// Trigger edv
		if ((bitRead(modbus_edv, i)) && (!bitRead(memTrigger_edv, i))) bitWrite(Trigger_edv, i, true);
		else bitWrite(Trigger_edv, i, false);

		// Trigger auxiliar
		if ((bitRead( Trigger1, i)) && (!bitRead(memTrigger_Trigger1, i))) bitWrite(Trigger_Trigger1, i, true);
		else bitWrite(Trigger_Trigger1, i, false);
	}
	memTrigger_ed = modbus_ed;
	memTrigger_edv = modbus_edv;
	memTrigger_Trigger1 = Trigger1;
}

void SaidasDigitais(word saidas)
{
	// Q1 = PORTL.3
	// Q2 = PORTL.4
	// Q3 = PORTL.5

	// Desliga Clock e Enable
	//bitWrite(saidas, 8, bitRead(saidas, 9));
	//bitWrite(saidas, 0, bitRead(saidas, 1));
	bitWrite(PORTL, 3, 0);
	bitWrite(PORTL, 4, 0);
  	for (int i = 15; i >= 0; i--)
	{
		// Atualiza Out
		bitWrite(PORTL, 5, (saidas & bit_mask1[i]));

		// Liga Clock
		bitWrite(PORTL, 4, 1);

		// Desliga Clock
		bitWrite(PORTL, 4, 0);

	}

	// Liga Enable
	bitWrite(PORTL, 3, 1);

}

word EntradasDigitais()
{
	// I1 = PORTL.0
	// I2 = PORTL.1
	// I3 = PORTL.2

	static word entradas;
	static int filtro;
	static word ed_SemFiltroMemorizada;
	word ed_SemFiltro = 0;
	// Liga o enable
	bitWrite(PORTL, 0, 1);

	for (int i = 15; i >= 0; i--)
	{
		// Atualiza entrada
		if (!bitRead(PINL, 2)) ed_SemFiltro |= bit_mask1[i];

		// Desliga o clock
		bitWrite(PORTL, 1, 0);

		// Liga o clock
		bitWrite(PORTL, 1, 1);
	}

	//// Desliga o enable
	bitWrite(PORTL, 0, 0);

	//Filtro 
	if (ed_SemFiltro == ed_SemFiltroMemorizada) filtro -= 1;
	else filtro = 100;
	ed_SemFiltroMemorizada = ed_SemFiltro;
	if (filtro == 0) entradas = ed_SemFiltro;
	return entradas;
}
