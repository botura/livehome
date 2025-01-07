//Programa: Monitoracao de Caixa d´agua usando Arduino
//Autor: Arduino e Cia
//https://www.arduinoecia.com.br/monitore-sua-caixa-dagua-usando-arduino/?srsltid=AfmBOop_P74EFJuG0hYSrHVub6uV2yL5RWU4Vt3PNfihLUotgFLvH4AV

//Controle de Vazamento de caixa d'agua: https://www.robocore.net/tutoriais/usando-sensor-fluxo-de-agua?srsltid=AfmBOoq4gF8w0gppgl937MJsgD91Yr9IASagVcLPxnt4cO8EzW2PJ-99


//===========================================================================================================

//CONFIGURAÇÕES NIVEL DE CAIXA D'AGUA

#include <Wire.h>
int valor_s1 = 1, valor_s2 = 1, valor_s3 = 1;
int nivel_anterior = 0;

//Definições para a leitura do sensor - Função Time
  unsigned long futureTemp06 = {0};
  #define TIME_PAUSE_NIVELCXAGUA    5400  //5400



//==================================================================================================================

//CONFIGURAÇÕES VAZAMENTO DA CAIXA D'AGUA

//definicao do pino do sensor e de interrupcao
const int INTERRUPCAO_SENSOR = 0;               //interrupt = 0 equivale ao pino digital 2

//definicao da variavel de contagem de voltas
unsigned long contador = 0;

//definicao do fator de calibracao para conversao do valor lido
const float FATOR_CALIBRACAO = 4.5;

//definicao das variaveis de fluxo e volume
float fluxo = 0;
float volume = 0;
float volume_total = 0;

//definicao da variavel de intervalo de tempo
unsigned long tempo_antes = 0;

//===================================================================================================================

void prepareCxDagua()
{
          //Define os pinos dos sensores como entrada
          pinMode(sensoragua1, INPUT);
          pinMode(sensoragua2, INPUT);
          pinMode(sensoragua3, INPUT);
          pinMode(solenoidecxdagua,OUTPUT);
        
          Serial.println("Monitoracao de Caixa Dagua Iniciado...");
          Serial.println();
}

//=====================================================================================================================

void prepareCxDaguaVaz(){
  //inicializacao do monitor serial
//  Serial.begin(9600);

  //mensagem de inicializacao
  Serial.println("Sistema Vazamento Água Iniciado... ");
  Serial.println("Medidor de Fluxo e Volume de Liquidos\n");

  //configuracao do pino do sensor como entrada em nivel logico alto
  pinMode(PINO_SENSOR, INPUT_PULLUP);

}

//========================================================================================================================

//MONITORAMENTO NIVEL CAIXA D'AGUA

void monitoringCxDagua(){

        if(timeIsOver(futureTemp06)){
                        
                      
                      //Leitura dos sensores
                      int valor_s1 = digitalRead(sensoragua1);
                      int valor_s2 = digitalRead(sensoragua2);
                      int valor_s3 = digitalRead(sensoragua3);
                    
                      //Mostra valor dos sensores no serial monitor
                      Serial.print("S1: ");
                      Serial.print(valor_s1);
                      Mb.R[41]=digitalRead(valor_s1); //status do Sensor 1
                      Serial.print(" S2: ");
                      Serial.print(valor_s2);
                      Mb.R[42]=digitalRead(valor_s2); //status do Sensor 2
                      Serial.print(" S3: ");
                      Serial.println(valor_s3);
                      Mb.R[43]=digitalRead(valor_s3); //status do Sensor 3
                    
                      //Checa o nivel e atualiza o display
                      
                                  //Se todos os sensores estiverem acionados desliga a solenoide
                                  if ((valor_s1 == 0) && valor_s2 == 0 && valor_s3 == 0)
                                  {
                                    digitalWrite(solenoidecxdagua, HIGH);
                                    Serial.println("Caixa D'água chegia!");
                                    Serial.println("Solenóide Desligada!");
                                  }
                                  //Se o sensor 01 estiver desativado e os sensores 02 e 03 acionados mantem solenoide desligada
                                  if ((valor_s1 == 1) && valor_s2 == 0 && valor_s3 == 0)
                                  {
                                    Serial.println("Caixa D'água em 2/3!");
                                  }
                                  //Se o sensor 01 e 02 estiverem desativados e o sensores 03 acionado mantem solenoide desligada
                                  if ((valor_s1 == 1) && valor_s2 == 1 && valor_s3 == 0)
                                  {
                                    Serial.println("Caixa D'água em 1/3!");
                                  }
                                  //Se todos os sensores estiverem desativados aciona o alarme para encher a caixa
                                  if ((valor_s1 == 1) && valor_s2 == 1 && valor_s3 == 1){
                                    digitalWrite(solenoidecxdagua, LOW);
                                    Serial.println("Caixa D'água ficando vazia!");
                                    Serial.println("Ativando válvula solenóide de emergência!");
                                  }
   
              futureTemp06 = millis() + TIME_PAUSE_NIVELCXAGUA;
                   }  
               }



void mostra_nivel(int nivel)
                    {
                      if (nivel != nivel_anterior)
                      {
                        //Atualiza o nivel no display
                        for (int i = 0; i <= nivel; i++)
                        nivel_anterior = nivel;
                      }
                    }

//=============================================================================================================

//MONITORAÇÃO VAZAMENTO CAIXA D'AGUA

void monitoringCxDaguaVaz() {

                    //executa a contagem de pulsos uma vez por segundo
                    if((millis() - tempo_antes) > 1000){

                      //desabilita a interrupcao para realizar a conversao do valor de pulsos
                      detachInterrupt(INTERRUPCAO_SENSOR);

                      //conversao do valor de pulsos para L/min
                      fluxo = ((1000.0 / (millis() - tempo_antes)) * contador) / FATOR_CALIBRACAO;

                      //exibicao do valor de fluxo
                      Serial.print("Fluxo de: ");
                      Serial.print(fluxo);
                      Serial.println(" L/min");

                      //calculo do volume em L passado pelo sensor
                      volume = fluxo / 60;

                      //armazenamento do volume
                      volume_total += volume;

                      //exibicao do valor de volume
                      Serial.print("Volume: ");
                      Serial.print(volume_total);
                      Serial.println(" L");
                      Serial.println();
                    
                      //reinicializacao do contador de pulsos
                      contador = 0;

                      //atualizacao da variavel tempo_antes
                      tempo_antes = millis();

                      //contagem de pulsos do sensor
                      attachInterrupt(INTERRUPCAO_SENSOR, contador_pulso, FALLING); 
                    }
}

//funcao chamada pela interrupcao para contagem de pulsos
void contador_pulso() {
  contador++;
}
