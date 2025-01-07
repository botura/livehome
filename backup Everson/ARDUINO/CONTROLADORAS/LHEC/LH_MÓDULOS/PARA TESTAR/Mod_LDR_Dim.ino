//Projeto: Controle de luminosidade de led com LDR  
//Autor: Arduino e Cia  

int pinoledB = 12; //Pino ligado ao anodo do led  
int pinoledR = 8; //Pino ligado ao anodo do led  
int pinoledG = 11; //Pino ligado ao anodo do led  
int pinopot = 14;  //Pino ligado ao LDR  
int valorpot = 0; //Armazena valor lido do LDR, entre 0 e 1023  
float luminosidade = 0; //Valor de luminosidade do led  

     unsigned long futureTemp05 = {0};
     #define TIME_PAUSE_LDR_DIM    5000
   
void prepareLDR_Dim()  
{  
  Serial.begin(57600);    //Inicializa a serial  
  pinMode(pinoledB, OUTPUT); //Define o pino do led como saída  
  pinMode(pinoledR, OUTPUT); //Define o pino do led como saída  
  pinMode(pinoledG, OUTPUT); //Define o pino do led como saída  
  pinMode(pinopot, INPUT);  //Define o pino do LDR como entrada  
}  
   
void monitoringLDR_Dim()  {  

if(timeIsOver(futureTemp05)){

  //Le o valor - analogico - do LDR  
  valorpot = analogRead(pinopot);  
  //Converte o valor lido do LDR
  luminosidade = map(valorpot, 0, 1023, 0, 255); 
  Serial.print("Valor lido do LDR : ");   
  //Mostra o valor lido do LDR no monitor serial  
  Serial.print(valorpot);  
  Serial.print(" = Luminosidade : ");  
  //Mostra o valor da luminosidade no monitor serial  
  Serial.println(luminosidade); 
  
  //Acende o led com luminosidade variável
  analogWrite(pinoledB, luminosidade); 
  analogWrite(pinoledR, luminosidade);
  analogWrite(pinoledG, luminosidade); 
 
    futureTemp05 = millis() + TIME_PAUSE_LDR_DIM;
 }

}  