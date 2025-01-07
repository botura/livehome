
//CONFIGURAÇÕES DOS INTERRUTPORES DAS VENEZIANAS

          unsigned long tempoInicio01 = 0;
          unsigned long tempoInicio02 = 0;
          unsigned long tempoInicio03 = 0;
          unsigned long tempoInicio04 = 0;

          unsigned long tempoBotao01 = 0;
          unsigned long tempoBotao02 = 0;
          unsigned long tempoBotao03 = 0;
          unsigned long tempoBotao04 = 0;

          bool estadoBotao01;
          bool estadoBotao01Ant;
          bool estadoBotao02;
          bool estadoBotao02Ant;
          bool estadoBotao03;
          bool estadoBotao03Ant;
          bool estadoBotao04;
          bool estadoBotao04Ant;
//====================================================================================================================



void prepareVENEZIANAs(){

//Ao Reiniciar o sistema desliga automaticamente os relés:
        digitalWrite(VENEZIANA01SOBE, HIGH); //
        digitalWrite(VENEZIANA01DESCE, HIGH); //
        digitalWrite(VENEZIANA02SOBE, HIGH); //
        digitalWrite(VENEZIANA02DESCE, HIGH); //
//        digitalWrite(VENEZIANA03SOBE, HIGH); //
//        digitalWrite(VENEZIANA03DESCE, HIGH); //
//        digitalWrite(VENEZIANA04SOBE, HIGH); //
//        digitalWrite(VENEZIANA04DESCE, HIGH); //
        
//CONFIGURAÇÕES DOS PINOS DE ENTRADA/SAÍDA        
        pinMode(VENEZIANA01SOBE, OUTPUT);// define LED como saida
        pinMode(VENEZIANA01DESCE, OUTPUT);// define LED como saida
        pinMode(VENEZIANA02SOBE, OUTPUT);// define LED como saida
        pinMode(VENEZIANA02DESCE, OUTPUT);// define LED como saida
//        pinMode(VENEZIANA03SOBE, OUTPUT);// define LED como saida
//        pinMode(VENEZIANA03DESCE, OUTPUT);// define LED como saida
//        pinMode(VENEZIANA04SOBE, OUTPUT);// define LED como saida
//        pinMode(VENEZIANA04DESCE, OUTPUT);// define LED como saida

}//fim do setup
//====================================================================================================================



void prepareINTVENEZ(){

  pinMode(INTVENEZIANA01, INPUT_PULLUP);
  pinMode(INTVENEZIANA02, INPUT_PULLUP);
//  pinMode(INTVENEZIANA03, INPUT_PULLUP);
//  pinMode(INTVENEZIANA04, INPUT_PULLUP);

  pinMode(pinLED9, OUTPUT);


}//fim do setup
//====================================================================================================================



void monitoringI3PROVen()
{//Inicio Loop
  // Executa comunicacao modbus
        Mb.Run();

  // Verifica o valor da 1a variavel modbus
        switch (Mb.R[0])
           {//inicio switch

                        case 9999: //SENSOR LUMINOSIDADE LDR
//                                voltaraoinicio();
                                break;

                //RELÉ 01
                        case 9101: //RÉGUA ELETROS - INVERTE ESTADO RELÉ
                                  digitalWrite(VENEZIANA01SOBE, 1);
                                  digitalWrite(VENEZIANA01DESCE, 1);
                                   Serial.print("Clicou no botao 9101   ");
                                   Serial.println("VENEZIANA PARA");
                                break;
                        case 9111: //RÉGUA ELETROS - LIGA
                                digitalWrite(VENEZIANA01SOBE, 1);
                                digitalWrite(VENEZIANA01DESCE, 0);
                                  Serial.print("Clicou no botao 9111   ");
                                  Serial.println("VENEZIANA SOBE");
                                break;
                        case 9001: //RÉGUA ELETROS - DESLIGA RELÉ
                                digitalWrite(VENEZIANA01SOBE, 0);
                                digitalWrite(VENEZIANA01DESCE, 1);
                                   Serial.print("Clicou no botao 9001   ");
                                   Serial.println("VENEZIANA DESCE");
                                break;

/*                //RELÉ 02
                        case 9102: //RÉGUA ELETROS - INVERTE ESTADO RELÉ
                                  digitalWrite(VENEZIANA02SOBE, 1);
                                  digitalWrite(VENEZIANA02DESCE, 1);
                                   Serial.print("Clicou no botao 9102   ");
                                   Serial.println("VENEZIANA PARA");
                                break;
                        case 9112: //RÉGUA ELETROS - LIGA
                                digitalWrite(VENEZIANA02SOBE, 1);
                                digitalWrite(VENEZIANA02DESCE, 0);
                                  Serial.print("Clicou no botao 9112   ");
                                  Serial.println("VENEZIANA SOBE");
                                break;
                        case 9002: //RÉGUA ELETROS - DESLIGA RELÉ
                                digitalWrite(VENEZIANA02SOBE, 0);
                                digitalWrite(VENEZIANA02DESCE, 1);
                                   Serial.print("Clicou no botao 9002   ");
                                   Serial.println("VENEZIANA DESCE");
                                break;

                //RELÉ 03
                        case 9103: //RÉGUA ELETROS - INVERTE ESTADO RELÉ
                                  digitalWrite(VENEZIANA03SOBE, 1);
                                  digitalWrite(VENEZIANA03DESCE, 1);
                                   Serial.print("Clicou no botao 9103   ");
                                   Serial.println("VENEZIANA PARA");
                                break;
                        case 9113: //RÉGUA ELETROS - LIGA
                                digitalWrite(VENEZIANA03SOBE, 1);
                                digitalWrite(VENEZIANA03DESCE, 0);
                                  Serial.print("Clicou no botao 9113   ");
                                  Serial.println("VENEZIANA SOBE");
                                break;
                        case 9003: //RÉGUA ELETROS - DESLIGA RELÉ
                                digitalWrite(VENEZIANA03SOBE, 0);
                                digitalWrite(VENEZIANA03DESCE, 1);
                                   Serial.print("Clicou no botao 9003   ");
                                   Serial.println("VENEZIANA DESCE");
                                break;


                //RELÉ 04
                        case 9104: //RÉGUA ELETROS - INVERTE ESTADO RELÉ
                                  digitalWrite(VENEZIANA04SOBE, 1);
                                  digitalWrite(VENEZIANA04DESCE, 1);
                                   Serial.print("Clicou no botao 9104   ");
                                   Serial.println("VENEZIANA PARA");
                                break;
                        case 9114: //RÉGUA ELETROS - LIGA
                                digitalWrite(VENEZIANA04SOBE, 1);
                                digitalWrite(VENEZIANA04DESCE, 0);
                                  Serial.print("Clicou no botao 9114   ");
                                  Serial.println("VENEZIANA SOBE");
                                break;
                        case 9004: //RÉGUA ELETROS - DESLIGA RELÉ
                                digitalWrite(VENEZIANA04SOBE, 0);
                                digitalWrite(VENEZIANA04DESCE, 1);
                                   Serial.print("Clicou no botao 9004   ");
                                   Serial.println("VENEZIANA DESCE");
                                break;
*/
      } // fim switch
} // fim loop
//====================================================================================================================




//CONTROLE INTERRUPTORES 

// INTERRUPTOR 01
          void monitoringINTVENEZ01(){ //INTERRUPTOR VENEZIANA (SUÍTE)

            estadoBotao01 = !digitalRead(INTVENEZIANA01);

        //Ao apertar o botão desliga os relés
            if (estadoBotao01 && !estadoBotao01Ant) {
              if (tempoInicio01 == 0) {
                tempoInicio01 = millis();
                digitalWrite(VENEZIANA01SOBE, HIGH);
                digitalWrite(VENEZIANA01DESCE, HIGH);

              }
            }  

        //Ao soltar o botão 
            if (tempoInicio01 > 200) {  //Filtro Debounce
              if (!estadoBotao01 && estadoBotao01Ant) {
                tempoBotao01 = millis() - tempoInicio01;
                tempoInicio01 = 0;  
                digitalWrite(pinLED9, LOW);
              }
            }

            //Retorno
            if (tempoInicio01 > 0) {
              digitalWrite(pinLED9, bitRead(millis(),8)); 
            }

      //Comando 1 - Pulso rápido desliga os relés
            if ((tempoBotao01 > 0) && (tempoBotao01 <= 1000)) {
              tempoBotao01 = 0;
              Serial.println("Veneziana 01 para");
              digitalWrite(VENEZIANA01SOBE, HIGH);
              digitalWrite(VENEZIANA01DESCE, HIGH);
            }

      //Comando 2 - Pulso de até 2 segundos abre a veneziana
            if ((tempoBotao01 > 1000) && (tempoBotao01 <= 2000)) {
              tempoBotao01 = 0;
              Serial.println("Veneziana 01 Sobe");
              digitalWrite(VENEZIANA01SOBE, HIGH);
              digitalWrite(VENEZIANA01DESCE, LOW);
            }

/*
      //Comando 3 - Pulso de mais de 3 segundos fecha a veneziana
            if ((tempoBotao01 > 3000) && (tempoBotao01 <= 5000)) {
              tempoBotao01 = 0;
              Serial.println("Comando 2 executado");
              digitalWrite(VENEZIANA01SOBE, LOW);
              digitalWrite(VENEZIANA01DESCE, HIGH);
            }
*/

      //Comando 3 - Pulso de mais de 2 segundos fecha a veneziana
            if (tempoBotao01 > 2000) {
              tempoBotao01 = 0;
              Serial.println("Veneziana 01 Desce");
              digitalWrite(VENEZIANA01SOBE, LOW);
              digitalWrite(VENEZIANA01DESCE, HIGH);
              //digitalWrite(pinLED2, HIGH);
              //Mb.R[12]=digitalRead(LEDblue); //status do Relé
              //Mb.R[11]=digitalRead(LEDgreen); //status do Relé
              //Mb.R[10]=digitalRead(LEDred); //status do Relé
              //Mb.R[0] = 0;
            }


            estadoBotao01Ant = estadoBotao01;
            delay(20);


          } //FIM DO INTERRUPTOR 01



// INTERRUPTOR 02
          void monitoringINTVENEZ02(){ //INTERRUPTOR VENEZIANA (SUÍTE)

            estadoBotao02 = !digitalRead(INTVENEZIANA02);

            //Ao apertar o botão
            if (estadoBotao02 && !estadoBotao02Ant) {
              if (tempoInicio02 == 0) {
                tempoInicio02 = millis();

                digitalWrite(VENEZIANA02SOBE, HIGH);
                digitalWrite(VENEZIANA02DESCE, HIGH);
                //digitalWrite(pinLED2, LOW);
              }
            }  

            //Ao soltar o botão
            if (tempoInicio02 > 200) {  //Filtro Debounce
              if (!estadoBotao02 && estadoBotao02Ant) {
                tempoBotao02 = millis() - tempoInicio02;
                tempoInicio02 = 0;  
                digitalWrite(pinLED9, LOW);
              }
            }

            //Retorno
            if (tempoInicio02 > 0) {
              digitalWrite(pinLED9, bitRead(millis(),8)); 
            }

            //Comando 1
            if ((tempoBotao02 > 0) && (tempoBotao02 <= 1000)) {
              tempoBotao02 = 0;
              Serial.println("Veneziana 02 parar - INT 02");

              digitalWrite(VENEZIANA02SOBE, HIGH);
              digitalWrite(VENEZIANA02DESCE, HIGH);
              // digitalWrite(pinLED2, LOW);
              // Mb.R[12]=digitalRead(LEDblue); //status do Relé
              // Mb.R[11]=digitalRead(LEDgreen); //status do Relé
              // Mb.R[10]=digitalRead(LEDred); //status do Relé
            }

            //Comando 2
            if ((tempoBotao02 > 1000) && (tempoBotao02 <= 2000)) {
              tempoBotao02 = 0;
              Serial.println("Veneziana 02 Sobe - INT 02");

              digitalWrite(VENEZIANA02SOBE, HIGH);
              digitalWrite(VENEZIANA02DESCE, LOW);
          //     digitalWrite(pinLED2, LOW);
          //     digitalWrite(pinLED3, LOW);
          //     Mb.R[12]=digitalRead(LEDblue); //status do Relé
          //     Mb.R[11]=digitalRead(LEDgreen); //status do Relé
          //     Mb.R[10]=digitalRead(LEDred); //status do Relé
            }
          
            //Comando 3
//            if ((tempoBotao02 > 3000) && (tempoBotao02 <= 5000)) {
//              tempoBotao02 = 0;
//              Serial.println("Comando 2 executado");

//              digitalWrite(VENEZIANA01SOBE, LOW);
//              digitalWrite(VENEZIANA01DESCE, HIGH);
//              //digitalWrite(pinLED2, LOW);
//              //Mb.R[12]=digitalRead(LEDblue); //status do Relé
//              //Mb.R[11]=digitalRead(LEDgreen); //status do Relé
//              //Mb.R[10]=digitalRead(LEDred); //status do Relé
//            }

          
            //Comando 3
            if (tempoBotao02 > 2000) {
              tempoBotao02 = 0;
              Serial.println("Veneziana 02 Desce - INT 02");
            
              digitalWrite(VENEZIANA02SOBE, LOW);
              digitalWrite(VENEZIANA02DESCE, HIGH);
              //digitalWrite(pinLED2, HIGH);
              //Mb.R[12]=digitalRead(LEDblue); //status do Relé
              //Mb.R[11]=digitalRead(LEDgreen); //status do Relé
              //Mb.R[10]=digitalRead(LEDred); //status do Relé
              //Mb.R[0] = 0;
            }


            estadoBotao02Ant = estadoBotao02;
            delay(20);


          } //FIM DO INTERRUPTOR 02


/*
// INTERRUPTOR 03
          void monitoringINTVENEZ03(){ //INTERRUPTOR VENEZIANA (SUÍTE)

            estadoBotao03 = !digitalRead(INTVENEZIANA03);

            //Ao apertar o botão
            if (estadoBotao03 && !estadoBotao03Ant) {
              if (tempoInicio03 == 0) {
                tempoInicio03 = millis();

                digitalWrite(VENEZIANA03SOBE, HIGH);
                digitalWrite(VENEZIANA03DESCE, HIGH);
                //digitalWrite(pinLED2, LOW);
              }
            }  

            //Ao soltar o botão
            if (tempoInicio03 > 200) {  //Filtro Debounce
              if (!estadoBotao03 && estadoBotao03Ant) {
                tempoBotao03 = millis() - tempoInicio03;
                tempoInicio03 = 0;  
                digitalWrite(pinLED9, LOW);
              }
            }

            //Retorno
            if (tempoInicio03 > 0) {
              digitalWrite(pinLED9, bitRead(millis(),8)); 
            }

            //Comando 1
            if ((tempoBotao03 > 0) && (tempoBotao03 <= 1000)) {
              tempoBotao03 = 0;
              Serial.println("Veneziana 03 parar - INT 03");

              digitalWrite(VENEZIANA03SOBE, HIGH);
              digitalWrite(VENEZIANA03DESCE, HIGH);
              // digitalWrite(pinLED2, LOW);
              // Mb.R[12]=digitalRead(LEDblue); //status do Relé
              // Mb.R[11]=digitalRead(LEDgreen); //status do Relé
              // Mb.R[10]=digitalRead(LEDred); //status do Relé
            }

            //Comando 2
            if ((tempoBotao03 > 1000) && (tempoBotao03 <= 2000)) {
              tempoBotao03 = 0;
              Serial.println("Veneziana 03 Sobe");

              digitalWrite(VENEZIANA03SOBE, HIGH);
              digitalWrite(VENEZIANA03DESCE, LOW);
          //     digitalWrite(pinLED2, LOW);
          //     digitalWrite(pinLED3, LOW);
          //     Mb.R[12]=digitalRead(LEDblue); //status do Relé
          //     Mb.R[11]=digitalRead(LEDgreen); //status do Relé
          //     Mb.R[10]=digitalRead(LEDred); //status do Relé
            }
          
            //Comando 3
//            if ((tempoBotao03 > 3000) && (tempoBotao03 <= 5000)) {
//              tempoBotao03 = 0;
//              Serial.println("Comando 3 executado");

//              digitalWrite(VENEZIANA03SOBE, LOW);
//              digitalWrite(VENEZIANA03DESCE, HIGH);
//              //digitalWrite(pinLED2, LOW);
//              //Mb.R[12]=digitalRead(LEDblue); //status do Relé
//              //Mb.R[11]=digitalRead(LEDgreen); //status do Relé
//              //Mb.R[10]=digitalRead(LEDred); //status do Relé
 //           }

          
            //Comando 3
            if (tempoBotao03 > 2000) {
              tempoBotao03 = 0;
              Serial.println("Veneziana 03 Desce");
            
              digitalWrite(VENEZIANA03SOBE, LOW);
              digitalWrite(VENEZIANA03DESCE, HIGH);
              //digitalWrite(pinLED2, HIGH);
              //Mb.R[12]=digitalRead(LEDblue); //status do Relé
              //Mb.R[11]=digitalRead(LEDgreen); //status do Relé
              //Mb.R[10]=digitalRead(LEDred); //status do Relé
              //Mb.R[0] = 0;
            }


            estadoBotao03Ant = estadoBotao03;
            delay(20);


          } //FIM DO INTERRUPTOR 03



// INTERRUPTOR 04
          void monitoringINTVENEZ04(){ //INTERRUPTOR VENEZIANA (SUÍTE)

            estadoBotao04 = !digitalRead(INTVENEZIANA04);

            //Ao apertar o botão
            if (estadoBotao04 && !estadoBotao04Ant) {
              if (tempoInicio04 == 0) {
                tempoInicio04 = millis();

                digitalWrite(VENEZIANA04SOBE, HIGH);
                digitalWrite(VENEZIANA04DESCE, HIGH);
                //digitalWrite(pinLED2, LOW);
              }
            }  

            //Ao soltar o botão
            if (tempoInicio04 > 200) {  //Filtro Debounce
              if (!estadoBotao04 && estadoBotao04Ant) {
                tempoBotao04 = millis() - tempoInicio04;
                tempoInicio04 = 0;  
                digitalWrite(pinLED9, LOW);
              }
            }

            //Retorno
            if (tempoInicio04 > 0) {
              digitalWrite(pinLED9, bitRead(millis(),8)); 
            }

            //Comando 1
            if ((tempoBotao04 > 0) && (tempoBotao04 <= 1000)) {
              tempoBotao04 = 0;
              Serial.println("Veneziana 04 parar - INT 04");

              digitalWrite(VENEZIANA04SOBE, HIGH);
              digitalWrite(VENEZIANA04DESCE, HIGH);
              // digitalWrite(pinLED2, LOW);
              // Mb.R[12]=digitalRead(LEDblue); //status do Relé
              // Mb.R[11]=digitalRead(LEDgreen); //status do Relé
              // Mb.R[10]=digitalRead(LEDred); //status do Relé
            }

            //Comando 2
            if ((tempoBotao04 > 1000) && (tempoBotao04 <= 2000)) {
              tempoBotao04 = 0;
              Serial.println("Veneziana 04 Sobe");

              digitalWrite(VENEZIANA04SOBE, HIGH);
              digitalWrite(VENEZIANA04DESCE, LOW);
          //     digitalWrite(pinLED2, LOW);
          //     digitalWrite(pinLED3, LOW);
          //     Mb.R[12]=digitalRead(LEDblue); //status do Relé
          //     Mb.R[11]=digitalRead(LEDgreen); //status do Relé
          //     Mb.R[10]=digitalRead(LEDred); //status do Relé
            }
          
            //Comando 3
//            if ((tempoBotao03 > 3000) && (tempoBotao03 <= 5000)) {
//              tempoBotao03 = 0;
//              Serial.println("Comando 3 executado");

//              digitalWrite(VENEZIANA03SOBE, LOW);
//              digitalWrite(VENEZIANA03DESCE, HIGH);
//              //digitalWrite(pinLED2, LOW);
//              //Mb.R[12]=digitalRead(LEDblue); //status do Relé
//              //Mb.R[11]=digitalRead(LEDgreen); //status do Relé
//              //Mb.R[10]=digitalRead(LEDred); //status do Relé
//            }

          
            //Comando 3
            if (tempoBotao04 > 2000) {
              tempoBotao04 = 0;
              Serial.println("Veneziana 04 Desce");
            
              digitalWrite(VENEZIANA04SOBE, LOW);
              digitalWrite(VENEZIANA04DESCE, HIGH);
              //digitalWrite(pinLED2, HIGH);
              //Mb.R[12]=digitalRead(LEDblue); //status do Relé
              //Mb.R[11]=digitalRead(LEDgreen); //status do Relé
              //Mb.R[10]=digitalRead(LEDred); //status do Relé
              //Mb.R[0] = 0;
            }


            estadoBotao04Ant = estadoBotao04;
            delay(20);


          } //FIM DO INTERRUPTOR 04

          */