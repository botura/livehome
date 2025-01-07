

     unsigned long futureTemp = {0};
     #define TIME_PAUSE_LDR    5000


//SENSOR LDR - ILUMINAÇÃO
     int ledPin       = 12;   //Relé de acionamento LDR
     int ldrPin       = 14;    //LDR no pino ANALÓGICO
     int ldrValor     = 0;    //Valor lido do LDR



void prepareLDR(){
  
  //Ao Reiniciar o sistema aciona automaticamente os relés:
        digitalWrite(ledPin, HIGH); //

   //CONFIGURAÇÃO SAÍDA
        pinMode(ledPin,OUTPUT); //define a porta 7 como saída
  }




void monitoringLDR(){

    if(timeIsOver(futureTemp)){


          //ler o valor do LDR
              ldrValor = analogRead(ldrPin); //O valor lido será entre 0 e 1023
           
              //se o valor lido for maior que 400, liga o led
                  if (ldrValor>= 400) digitalWrite(ledPin,HIGH);
                    // senão, apaga o led
                    else digitalWrite(ledPin,LOW);
                    Mb.R[16]=digitalRead(ledPin); //status do Relé
           
              //imprime o valor lido do LDR no monitor serial
              Serial.println(ldrValor);
//              delay(100);

     futureTemp = millis() + TIME_PAUSE_LDR;
}
            
  }

