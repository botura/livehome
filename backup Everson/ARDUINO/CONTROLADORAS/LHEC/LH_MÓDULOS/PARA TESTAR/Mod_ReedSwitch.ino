/*
 * Controle fita Led RGB POR MICROFONE, 
 * Vários efeitos de cores
 * OK - TESTADA E FUNCIONANDO - 30/03/2023
 * 
 */

 
//SENSOR - REED SWITCH
     int r_sw01 = 28; //PINO DIGITAL UTILIZADO PELO SENSOR
//     int r_sw02 = 32; //PINO DIGITAL UTILIZADO PELO SENSOR
//     int r_sw03 = 35; //PINO DIGITAL UTILIZADO PELO SENSOR
//     int r_sw04 = 34; //PINO DIGITAL UTILIZADO PELO SENSOR               
//     int led = 53; //PINO DIGITAL UTILIZADO PELO RELÉ DA SIRENE



      //Definições para a leitura do sensor - Função Time
        unsigned long futureTemp04 = {0};
        #define TIME_PAUSE_SW01    1000



void prepareReedSwitch(){

  //Ao Reiniciar o sistema aciona automaticamente os relés:
//        digitalWrite(led, HIGH); //

  
  //SENSORES MOVIMENTO - REED SWITCH
        pinMode(r_sw01, INPUT); //DEFINE O PINO COMO ENTRADA
//        pinMode(r_sw02, INPUT); //DEFINE O PINO COMO ENTRADA
//        pinMode(r_sw03, INPUT); //DEFINE O PINO COMO ENTRADA
//        pinMode(r_sw04, INPUT); //DEFINE O PINO COMO ENTRADA                
//        pinMode(led, OUTPUT); //DEFINE O PINO COMO SAÍDA

  
}

/*
void monitoringReedSwitch01(){ //opção 01

  if(timeIsOver(futureTemp04)){

            // SENSOR 01
              if(digitalRead(r_sw01) == LOW)
              
                {
                    delay(10000);
                    {
                      if (digitalRead(r_sw01) == LOW)
                         { //Se o sensor for acionado, faça:
                      Serial.println("PORTA ABERTA: ");
                     // digitalWrite(led, HIGH);     //Ligue o led
                          }
                      else {                       //Senão:
                     // digitalWrite(led, LOW);    //desligue o led
                       }
                    }   
                }
                else {                       //Senão:
                  Serial.println("PORTA FECHADA: ");
                  //digitalWrite(led, LOW);    //desligue o led
                     }
                     

              Mb.R[50]=digitalRead(r_sw01); //status do Relé
 
           futureTemp04 = millis() + TIME_PAUSE_SW01;
}

}*/

void monitoringReedSwitch01(){ //opção 02 sem temporizador

  if(timeIsOver(futureTemp04)){
    
  
            // SENSOR 01
              if(digitalRead(r_sw01) == LOW)
                  { //Se o sensor for acionado, faça:
                      Serial.println("PORTA ABERTA: ");
                          }
                      else {                       //Senão:
                     Serial.println("PORTA FECHADA: ");                 
                       }
                       
              Mb.R[50]=digitalRead(r_sw01); //status do Relé

            futureTemp04 = millis() + TIME_PAUSE_SW01;
}
}


/*
void monitoringReedSwitch02(){

            // SENSOR 02
              if(digitalRead(r_sw02) == LOW)
             { //Se o sensor for acionado, faça:
                digitalWrite(led, HIGH);     //Ligue o led
                }
                else {                       //Senão:
                  digitalWrite(led, LOW);    //desligue o led
                }
              Mb.R[51]=digitalRead(r_sw02); //status do Relé
}


void monitoringReedSwitch03(){

            // SENSOR 03
              if(digitalRead(r_sw03) == LOW)
             { //Se o sensor for acionado, faça:
                digitalWrite(led, HIGH);     //Ligue o led
                }
                else {                       //Senão:
                  digitalWrite(led, LOW);    //desligue o led
                }
              Mb.R[52]=digitalRead(r_sw03); //status do Relé
}


void monitoringReedSwitch04(){

            // SENSOR 04
              if(digitalRead(r_sw04) == LOW)
             { //Se o sensor for acionado, faça:
                digitalWrite(led, HIGH);     //Ligue o led
                }
                else {                       //Senão:
                  digitalWrite(led, LOW);    //desligue o led
                }
              Mb.R[53]=digitalRead(r_sw04); //status do Relé
}

*/
