 
//SENSOR - REED SWITCH
     int r_sw01 = 22; //PINO DIGITAL UTILIZADO PELO SENSOR
     int r_sw02 = 23; //PINO DIGITAL UTILIZADO PELO SENSOR
     int r_sw03 = 24; //PINO DIGITAL UTILIZADO PELO SENSOR
     int r_sw04 = 25; //PINO DIGITAL UTILIZADO PELO SENSOR
     int r_sw05 = 26; //PINO DIGITAL UTILIZADO PELO SENSOR
     int r_sw06 = 27; //PINO DIGITAL UTILIZADO PELO SENSOR
     int r_sw07 = 28; //PINO DIGITAL UTILIZADO PELO SENSOR
     int r_sw08 = 29; //PINO DIGITAL UTILIZADO PELO SENSOR
     int r_sw09 = 30; //PINO DIGITAL UTILIZADO PELO SENSOR
     int r_sw10 = 31; //PINO DIGITAL UTILIZADO PELO SENSOR
     int r_sw11 = 32; //PINO DIGITAL UTILIZADO PELO SENSOR
     int r_sw12 = 33; //PINO DIGITAL UTILIZADO PELO SENSOR
     int r_sw13 = 34; //PINO DIGITAL UTILIZADO PELO SENSOR
     int r_sw14 = 35; //PINO DIGITAL UTILIZADO PELO SENSOR
     int r_sw15 = 36; //PINO DIGITAL UTILIZADO PELO SENSOR
     int r_sw16 = 37; //PINO DIGITAL UTILIZADO PELO SENSOR               
     int r_sw17 = 38; //PINO DIGITAL UTILIZADO PELO SENSOR               
     int r_sw18 = 39; //PINO DIGITAL UTILIZADO PELO SENSOR               
     //int r_sw19 = 14; //PINO DIGITAL UTILIZADO PELO SENSOR               

//     int led = 53; //PINO DIGITAL UTILIZADO PELO RELÉ DA SIRENE



      //Definições para a leitura do sensor - Função Time
        unsigned long futureTemp04 = {0};
        #define TIME_PAUSE_SW01    1000



void prepareReedSwitch(){

  //Ao Reiniciar o sistema aciona automaticamente os relés:
//        digitalWrite(led, HIGH); //

  
  //SENSORES MOVIMENTO - REED SWITCH
        pinMode(r_sw01, INPUT); //DEFINE O PINO COMO ENTRADA
        pinMode(r_sw02, INPUT); //DEFINE O PINO COMO ENTRADA
        pinMode(r_sw03, INPUT); //DEFINE O PINO COMO ENTRADA
        pinMode(r_sw04, INPUT); //DEFINE O PINO COMO ENTRADA                
        pinMode(r_sw05, INPUT); //DEFINE O PINO COMO ENTRADA                
        pinMode(r_sw06, INPUT); //DEFINE O PINO COMO ENTRADA                
        pinMode(r_sw07, INPUT); //DEFINE O PINO COMO ENTRADA                
        pinMode(r_sw08, INPUT); //DEFINE O PINO COMO ENTRADA                
        pinMode(r_sw09, INPUT); //DEFINE O PINO COMO ENTRADA                
        pinMode(r_sw10, INPUT); //DEFINE O PINO COMO ENTRADA                
        pinMode(r_sw11, INPUT); //DEFINE O PINO COMO ENTRADA                
        pinMode(r_sw12, INPUT); //DEFINE O PINO COMO ENTRADA                
        pinMode(r_sw13, INPUT); //DEFINE O PINO COMO ENTRADA                
        pinMode(r_sw14, INPUT); //DEFINE O PINO COMO ENTRADA                
        pinMode(r_sw15, INPUT); //DEFINE O PINO COMO ENTRADA                
        pinMode(r_sw16, INPUT); //DEFINE O PINO COMO ENTRADA                
        pinMode(r_sw17, INPUT); //DEFINE O PINO COMO ENTRADA                
        pinMode(r_sw18, INPUT); //DEFINE O PINO COMO ENTRADA                
//        pinMode(r_sw19, INPUT); //DEFINE O PINO COMO ENTRADA                

//        pinMode(led, OUTPUT); //DEFINE O PINO COMO SAÍDA

}


void monitoringReedSwitch01(){ //opção 02 sem temporizador

  if(timeIsOver(futureTemp04)){
    
  
            // SENSOR 01
              if(digitalRead(r_sw01) == HIGH)
                  { //Se o sensor for acionado, faça:
                      Serial.println("PORTA 01 ABERTA: ");
                          }
                      else {                       //Senão:
                     Serial.println("PORTA 01 FECHADA: ");                 
                       }
              Mb.R[22]=digitalRead(r_sw01); //status do Relé

//-------------------------------------------------------------------------------
// SENSOR 02
              if(digitalRead(r_sw02) == HIGH)
                  { //Se o sensor for acionado, faça:
                      Serial.println("PORTA 02 ABERTA: ");
                          }
                      else {                       //Senão:
                     Serial.println("PORTA 02 FECHADA: ");                 
                       }
              Mb.R[23]=digitalRead(r_sw02); //status do Relé
//-------------------------------------------------------------------------------
// SENSOR 03
              if(digitalRead(r_sw03) == HIGH)
                  { //Se o sensor for acionado, faça:
                      Serial.println("PORTA 03 ABERTA: ");
                          }
                      else {                       //Senão:
                     Serial.println("PORTA 03 FECHADA: ");                 
                       }
              Mb.R[24]=digitalRead(r_sw03); //status do Relé
//-------------------------------------------------------------------------------
// SENSOR 04
              if(digitalRead(r_sw04) == HIGH)
                  { //Se o sensor for acionado, faça:
                      Serial.println("PORTA 04 ABERTA: ");
                          }
                      else {                       //Senão:
                     Serial.println("PORTA 04 FECHADA: ");                 
                       }
              Mb.R[25]=digitalRead(r_sw04); //status do Relé
//-------------------------------------------------------------------------------
// SENSOR 05
              if(digitalRead(r_sw05) == HIGH)
                  { //Se o sensor for acionado, faça:
                      Serial.println("PORTA 05 ABERTA: ");
                          }
                      else {                       //Senão:
                     Serial.println("PORTA 05 FECHADA: ");                 
                       }
              Mb.R[26]=digitalRead(r_sw05); //status do Relé
//-------------------------------------------------------------------------------
// SENSOR 06
              if(digitalRead(r_sw06) == HIGH)
                  { //Se o sensor for acionado, faça:
                      Serial.println("PORTA 06 ABERTA: ");
                          }
                      else {                       //Senão:
                     Serial.println("PORTA 06 FECHADA: ");                 
                       }
              Mb.R[27]=digitalRead(r_sw06); //status do Relé
//-------------------------------------------------------------------------------
// SENSOR 07
              if(digitalRead(r_sw07) == HIGH)
                  { //Se o sensor for acionado, faça:
                      Serial.println("PORTA 07 ABERTA: ");
                          }
                      else {                       //Senão:
                     Serial.println("PORTA 07 FECHADA: ");                 
                       }
              Mb.R[28]=digitalRead(r_sw07); //status do Relé
//-------------------------------------------------------------------------------
// SENSOR 08
              if(digitalRead(r_sw08) == HIGH)
                  { //Se o sensor for acionado, faça:
                      Serial.println("PORTA 08 ABERTA: ");
                          }
                      else {                       //Senão:
                     Serial.println("PORTA 08 FECHADA: ");                 
                       }
              Mb.R[29]=digitalRead(r_sw08); //status do Relé
//-------------------------------------------------------------------------------
// SENSOR 09
              if(digitalRead(r_sw09) == HIGH)
                  { //Se o sensor for acionado, faça:
                      Serial.println("PORTA 09 ABERTA: ");
                          }
                      else {                       //Senão:
                     Serial.println("PORTA 09 FECHADA: ");                 
                       }
              Mb.R[30]=digitalRead(r_sw09); //status do Relé
//-------------------------------------------------------------------------------
// SENSOR 10
              if(digitalRead(r_sw10) == HIGH)
                  { //Se o sensor for acionado, faça:
                      Serial.println("PORTA 10 ABERTA: ");
                          }
                      else {                       //Senão:
                     Serial.println("PORTA 10 FECHADA: ");                 
                       }
              Mb.R[31]=digitalRead(r_sw10); //status do Relé
//-------------------------------------------------------------------------------
// SENSOR 11
              if(digitalRead(r_sw11) == HIGH)
                  { //Se o sensor for acionado, faça:
                      Serial.println("PORTA 11 ABERTA: ");
                          }
                      else {                       //Senão:
                     Serial.println("PORTA 11 FECHADA: ");                 
                       }
              Mb.R[32]=digitalRead(r_sw11); //status do Relé
//-------------------------------------------------------------------------------
// SENSOR 12
              if(digitalRead(r_sw12) == HIGH)
                  { //Se o sensor for acionado, faça:
                      Serial.println("PORTA 12 ABERTA: ");
                          }
                      else {                       //Senão:
                     Serial.println("PORTA 12 FECHADA: ");                 
                       }
              Mb.R[33]=digitalRead(r_sw12); //status do Relé
//-------------------------------------------------------------------------------
// SENSOR 13
              if(digitalRead(r_sw13) == HIGH)
                  { //Se o sensor for acionado, faça:
                      Serial.println("PORTA 13 ABERTA: ");
                          }
                      else {                       //Senão:
                     Serial.println("PORTA 13 FECHADA: ");                 
                       }
              Mb.R[34]=digitalRead(r_sw13); //status do Relé
//-------------------------------------------------------------------------------
// SENSOR 14
              if(digitalRead(r_sw14) == HIGH)
                  { //Se o sensor for acionado, faça:
                      Serial.println("PORTA 14 ABERTA: ");
                          }
                      else {                       //Senão:
                     Serial.println("PORTA 14 FECHADA: ");                 
                       }
              Mb.R[35]=digitalRead(r_sw14); //status do Relé
//-------------------------------------------------------------------------------
// SENSOR 15
              if(digitalRead(r_sw15) == HIGH)
                  { //Se o sensor for acionado, faça:
                      Serial.println("PORTA 15 ABERTA: ");
                          }
                      else {                       //Senão:
                     Serial.println("PORTA 15 FECHADA: ");                 
                       }
              Mb.R[36]=digitalRead(r_sw15); //status do Relé
//-------------------------------------------------------------------------------
// SENSOR 16
              if(digitalRead(r_sw16) == HIGH)
                  { //Se o sensor for acionado, faça:
                      Serial.println("PORTA 16 ABERTA: ");
                          }
                      else {                       //Senão:
                     Serial.println("PORTA 16 FECHADA: ");                 
                       }
              Mb.R[37]=digitalRead(r_sw16); //status do Relé
//-------------------------------------------------------------------------------
// SENSOR 17
              if(digitalRead(r_sw17) == HIGH)
                  { //Se o sensor for acionado, faça:
                      Serial.println("PORTA 17 ABERTA: ");
                          }
                      else {                       //Senão:
                     Serial.println("PORTA 17 FECHADA: ");                 
                       }
              Mb.R[38]=digitalRead(r_sw17); //status do Relé
//-------------------------------------------------------------------------------
// SENSOR 18
              if(digitalRead(r_sw18) == HIGH)
                  { //Se o sensor for acionado, faça:
                      Serial.println("PORTA 18 ABERTA: ");
                          }
                      else {                       //Senão:
                     Serial.println("PORTA 18 FECHADA: ");                 
                       }
              Mb.R[39]=digitalRead(r_sw18); //status do Relé
//-------------------------------------------------------------------------------
/*
// SENSOR 19
              if(digitalRead(r_sw19) == HIGH)
                  { //Se o sensor for acionado, faça:
                      Serial.println("PORTA 19 ABERTA: ");
                          }
                      else {                       //Senão:
                     Serial.println("PORTA 19 FECHADA: ");                 
                       }
              Mb.R[40]=digitalRead(r_sw19); //status do Relé


            futureTemp04 = millis() + TIME_PAUSE_SW01;
*/

}
}
