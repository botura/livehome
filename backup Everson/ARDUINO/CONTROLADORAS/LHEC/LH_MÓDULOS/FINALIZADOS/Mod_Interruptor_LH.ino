
        boolean pressedSingleButton01  = false;     
        boolean pressedSingleButton02  = false;     
        boolean pressedSingleButton03  = false;     
/*        boolean pressedSingleButton04  = false;     
        boolean pressedSingleButton05  = false;     
        boolean pressedSingleButton06  = false;     
        boolean pressedSingleButton07  = false;     
        boolean pressedSingleButton08  = false;     
*/
        bool estadoled01         = 0; // variavel de controle
        bool estadoled02         = 0; // variavel de controle
        bool estadoled03         = 0; // variavel de controle
/*        bool estadoled04         = 0; // variavel de controle
        bool estadoled05         = 0; // variavel de controle
        bool estadoled06         = 0; // variavel de controle
        bool estadoled07         = 0; // variavel de controle
        bool estadoled08         = 0; // variavel de controle
*/


//void setup()
void prepareInterruptor()
     {
// CONFIGURAÇÕES DOS INTERRUPTORES
        pinMode(INTERRUPTOR01, INPUT_PULLUP); // define o pino do botao como entrada
        pinMode(INTERRUPTOR02, INPUT_PULLUP); // define o pino do botao como entrada
        pinMode(INTERRUPTOR03, INPUT_PULLUP); // define o pino do botao como entrada
//        pinMode(INTERRUPTOR04, INPUT_PULLUP); // define o pino do botao como entrada
/*        pinMode(INTERRUPTOR05, INPUT_PULLUP); // define o pino do botao como entrada
        pinMode(INTERRUPTOR06, INPUT_PULLUP); // define o pino do botao como entrada
        pinMode(INTERRUPTOR07, INPUT_PULLUP); // define o pino do botao como entrada
        pinMode(INTERRUPTOR08, INPUT_PULLUP); // define o pino do botao como entrada
*/


// CONFIGURAÇÕES DOS RELÉS DOS INTERRUPTORES
        //Ao Reiniciar o sistema aciona automaticamente os relés:
        digitalWrite(RELE01, HIGH); //
        digitalWrite(RELE02, HIGH); //
        digitalWrite(RELE03, HIGH); //
//        digitalWrite(RELE04, HIGH); //
//        digitalWrite(RELE05, LOW); //
//        digitalWrite(RELE06, HIGH); //
//        digitalWrite(RELE07, HIGH); //
//        digitalWrite(RELE08, HIGH); //

        
        
        pinMode(RELE01, OUTPUT);// define LED como saida
        pinMode(RELE02, OUTPUT);// define LED como saida
        pinMode(RELE03, OUTPUT);// define LED como saida
//        pinMode(RELE04, OUTPUT);// define LED como saida
//        pinMode(RELE05, OUTPUT);// define LED como saida
//        pinMode(RELE06, OUTPUT);// define LED como saida
//        pinMode(RELE07, OUTPUT);// define LED como saida
//        pinMode(RELE08, OUTPUT);// define LED como saida

}



//void loop()
void monitoringInterruptor(){


   //INTERRUPTOR 01
           if (digitalRead(INTERRUPTOR01) == LOW && pressedSingleButton01 == false) { // Se o botão for pressionado
                delay(40);
                 if (digitalRead(INTERRUPTOR01) == LOW){
                    estadoled01 = !estadoled01; // troca o estado do LED

                    digitalWrite(RELE01, estadoled01);

                    while (digitalRead(INTERRUPTOR01) == LOW);
                    delay(100);
//                       Mb.R[10]=digitalRead(RELE01); //status do Relé
                       Mb.R[0] = 0;    
                       Serial.print("Clicou no botao 1   ");
                       Serial.print("Estado do Rele:");
                       Serial.println(estadoled01);
            }
           }

   //INTERRUPTOR 02
           if (digitalRead(INTERRUPTOR02) == LOW && pressedSingleButton02 == false) { // Se o botão for pressionado
                delay(40);
                 if (digitalRead(INTERRUPTOR02) == LOW){
                    estadoled02 = !estadoled02; // troca o estado do LED
                    
                    digitalWrite(RELE02, estadoled02);

                    while (digitalRead(INTERRUPTOR02) == LOW);
                    delay(100);
//                       Mb.R[11]=digitalRead(RELE02); //status do Relé
                       Mb.R[0] = 0;    
                       Serial.print("Clicou no botao 2   ");
                       Serial.print("Estado do Rele:");
                       Serial.println(estadoled02);
            }
           }

   //INTERRUPTOR 03
           if (digitalRead(INTERRUPTOR03) == LOW && pressedSingleButton03 == false) { // Se o botão for pressionado
                delay(40);
                 if (digitalRead(INTERRUPTOR03) == LOW){
                    estadoled03 = !estadoled03; // troca o estado do LED
                    
                    digitalWrite(RELE03, estadoled03);

                    while (digitalRead(INTERRUPTOR03) == LOW);
                    delay(100);
//                       Mb.R[12]=digitalRead(RELE03); //status do Relé
                       Mb.R[0] = 0;    
                       Serial.print("Clicou no botao 3   ");
                       Serial.print("Estado do Rele:");
                       Serial.println(estadoled03);
            }
           }

/*   //INTERRUPTOR 04
           if (digitalRead(INTERRUPTOR04) == LOW && pressedSingleButton04 == false) { // Se o botão for pressionado
                delay(40);
                 if (digitalRead(INTERRUPTOR04) == LOW){
                    estadoled04 = !estadoled04; // troca o estado do LED
                    digitalWrite(RELE04, estadoled04);
                    while (digitalRead(INTERRUPTOR04) == LOW);
                    delay(100);
//                       Mb.R[13]=digitalRead(RELE04); //status do Relé
                       Mb.R[0] = 0;    
                       Serial.print("Clicou no botao 4   ");
                       Serial.print("Estado do Rele:");
                       Serial.println(estadoled04);
                }
           }
   

   //INTERRUPTOR 05
           if (digitalRead(INTERRUPTOR05) == LOW && pressedSingleButton05 == false) { // Se o botão for pressionado
                delay(40);
                 if (digitalRead(INTERRUPTOR05) == LOW){
                    estadoled05 = !estadoled05; // troca o estado do LED
                    digitalWrite(RELE05, estadoled05);
                    while (digitalRead(INTERRUPTOR05) == LOW);
                    delay(100);
//                       Mb.R[13]=digitalRead(RELE05); //status do Relé
                       Mb.R[0] = 0;    
                       Serial.print("Clicou no botao 5   ");
                       Serial.print("Estado do Rele:");
                       Serial.println(estadoled05);
                }
           }
            

   //INTERRUPTOR 06
           if (digitalRead(INTERRUPTOR06) == LOW && pressedSingleButton06 == false) { // Se o botão for pressionado
                delay(40);
                 if (digitalRead(INTERRUPTOR06) == LOW){
                    estadoled06 = !estadoled06; // troca o estado do LED
                    digitalWrite(RELE06, estadoled06);
                    while (digitalRead(INTERRUPTOR06) == LOW);
                    delay(100);
//                       Mb.R[12]=digitalRead(RELE06); //status do Relé
                       Mb.R[0] = 0;    
                       Serial.print("Clicou no botao 6   ");
                       Serial.print("Estado do Rele:");
                       Serial.println(estadoled06);
            }
           }


   //INTERRUPTOR 07
           if (digitalRead(INTERRUPTOR07) == LOW && pressedSingleButton07 == false) { // Se o botão for pressionado
                delay(40);
                 if (digitalRead(INTERRUPTOR07) == LOW){
                    estadoled07 = !estadoled07; // troca o estado do LED
                    digitalWrite(RELE07, estadoled07);
                    while (digitalRead(INTERRUPTOR07) == LOW);
                    delay(100);
//                       Mb.R[12]=digitalRead(RELE07); //status do Relé
                       Mb.R[0] = 0;    
                       Serial.print("Clicou no botao 7   ");
                       Serial.print("Estado do Rele:");
                       Serial.println(estadoled07);
            }
           }


   //INTERRUPTOR 08
           if (digitalRead(INTERRUPTOR08) == LOW && pressedSingleButton08 == false) { // Se o botão for pressionado
                delay(40);
                 if (digitalRead(INTERRUPTOR08) == LOW){
                    estadoled08 = !estadoled08; // troca o estado do LED
                    digitalWrite(RELE08, estadoled08);
                    while (digitalRead(INTERRUPTOR08) == LOW);
                    delay(100);
//                       Mb.R[12]=digitalRead(RELE08); //status do Relé
                       Mb.R[0] = 0;    
                       Serial.print("Clicou no botao 8   ");
                       Serial.print("Estado do Rele:");
                       Serial.println(estadoled08);
            }
           }


/*
 * 
   //CENÁRIO 01
           if (digitalRead(INTERRUPTOR05) == LOW) // Se o botão for pressionado
              {
                estadoled05 = !estadoled05; // troca o estado do LED
                digitalWrite(RELE01, 1);
                digitalWrite(RELE02, 0);
                digitalWrite(RELE03, 0);
                digitalWrite(RELE04, 1);
                while (digitalRead(INTERRUPTOR05) == LOW);
                delay(100);
//                   Mb.R[6]=digitalRead(RELE04); //status do Relé
                   Mb.R[0] = 0;    
            }*/


}
//===============================================================================================================


void monitoringI3PRO()
{//Inicio Loop


  // Executa comunicacao modbus
        Mb.Run();

  // Verifica o valor da 1a variavel modbus
        switch (Mb.R[0])
           {//inicio switch


                //RELÉ 01
                        case 9101: //RÉGUA ELETROS - INVERTE ESTADO RELÉ
                                digitalWrite(RELE01, !digitalRead(RELE01));
                                //Mb.R[10]=digitalRead(RELE01); //status do Relé
                                Mb.R[0] = 0;
                                   Serial.print("Clicou no botao 1   ");
                                   Serial.print("Porta do Rele:");
                                   Serial.println(RELE01);    
                                break;
                        case 9111: //RÉGUA ELETROS - LIGA
                                digitalWrite(RELE01, 1);
                                //Mb.R[10]=digitalRead(RELE01); //status do Relé
                                Mb.R[0] = 0;    
                                break;
                        case 9001: //RÉGUA ELETROS - DESLIGA RELÉ
                                digitalWrite(RELE01, 0);
                                //Mb.R[10]=digitalRead(LEDred); //status do Relé
                                Mb.R[0] = 0;  
                                   Serial.print("Clicou no botao 1   ");
                                   Serial.print("Porta do Rele:");
                                   Serial.println(RELE01);                                  
                                break;

                //RELÉ 02
                        case 9102: //RÉGUA ELETROS - INVERTE ESTADO RELÉ
                                digitalWrite(RELE02, !digitalRead(RELE02));
                                //Mb.R[11]=digitalRead(LEDgreen); //status do Relé
                                Mb.R[0] = 0;
                                   Serial.print("Clicou no botao 2   ");
                                   Serial.print("Porta do Rele:");
                                   Serial.println(RELE02);      
                                break;
                        case 9112: //RÉGUA ELETROS - LIGA
                                digitalWrite(RELE02, 1);
                                //Mb.R[11]=digitalRead(RELE02); //status do Relé
                                Mb.R[0] = 0;    
                                break;
                        case 9002: //RÉGUA ELETROS - DESLIGA RELÉ
                                digitalWrite(RELE02, 0);
                               // Mb.R[11]=digitalRead(LEDgreen); //status do Relé
                                Mb.R[0] = 0;    
                                break;

                //RELÉ 03
                        case 9103: //RÉGUA ELETROS - INVERTE ESTADO RELÉ
                                digitalWrite(RELE03, !digitalRead(RELE03));
                                //Mb.R[12]=digitalRead(LEDblue); //status do Relé
                                Mb.R[0] = 0;
                                   Serial.print("Clicou no botao 3   ");
                                   Serial.print("Porta do Rele:");
                                   Serial.println(RELE03);
                                    
                                break;
                        case 9113: //RÉGUA ELETROS - LIGA
                                digitalWrite(RELE03, 1);
                                //Mb.R[12]=digitalRead(LEDblue); //status do Relé
                                Mb.R[0] = 0;    
                                break;
                        case 9003: //RÉGUA ELETROS - DESLIGA RELÉ
                                digitalWrite(RELE03, 0);
                                //Mb.R[12]=digitalRead(LEDblue); //status do Relé
                                Mb.R[0] = 0;    
                                break;

  /*              //RELÉ 04
                        case 9104: //RÉGUA ELETROS - INVERTE ESTADO RELÉ
                                digitalWrite(RELE04, !digitalRead(RELE04));
                                //Mb.R[13]=digitalRead(RELE04); //status do Relé
                                Mb.R[0] = 0;
                                   Serial.print("Clicou no botao 4   ");
                                   Serial.print("Porta do Rele:");
                                   Serial.println(RELE04);    
                                break;
                        case 9114: //RÉGUA ELETROS - LIGA
                                digitalWrite(RELE04, 1);
                                //Mb.R[13]=digitalRead(RELE04); //status do Relé
                                Mb.R[0] = 0;    
                                break;
                        case 9004: //RÉGUA ELETROS - DESLIGA RELÉ
                                digitalWrite(RELE04, 0);
                                //Mb.R[13]=digitalRead(RELE04); //status do Relé
                                Mb.R[0] = 0;    
                                break;
/*
                //RELÉ 05
                        case 9105: //RÉGUA ELETROS - INVERTE ESTADO RELÉ
                                digitalWrite(RELE05, !digitalRead(RELE05));
                                //Mb.R[14]=digitalRead(RELE05); //status do Relé
                                Mb.R[0] = 0;
                                   Serial.print("Clicou no botao 5   ");
                                   Serial.print("Porta do Rele:");
                                   Serial.println(RELE05);     
                                break;
                        case 9115: //RÉGUA ELETROS - LIGA
                                digitalWrite(RELE05, 1);
                                //Mb.R[14]=digitalRead(RELE05); //status do Relé
                                Mb.R[0] = 0;    
                                break;
                        case 9005: //RÉGUA ELETROS - DESLIGA RELÉ
                                digitalWrite(RELE05, 0);
                                //Mb.R[14]=digitalRead(RELE05); //status do Relé
                                Mb.R[0] = 0;    
                                break;                                

                //RELÉ 06
                        case 9106: //RÉGUA ELETROS - INVERTE ESTADO RELÉ
                                digitalWrite(RELE06, !digitalRead(RELE06));
                                //Mb.R[15]=digitalRead(RELE06); //status do Relé
                                Mb.R[0] = 0;
                                   Serial.print("Clicou no botao 6   ");
                                   Serial.print("Porta do Rele:");
                                   Serial.println(RELE06);    
                                break;
                        case 9116: //RÉGUA ELETROS - LIGA
                                digitalWrite(RELE06, 1);
                                //Mb.R[15]=digitalRead(RELE06); //status do Relé
                                Mb.R[0] = 0;    
                                break;
                        case 9006: //RÉGUA ELETROS - DESLIGA RELÉ
                                digitalWrite(RELE06, 0);
                                //Mb.R[15]=digitalRead(RELE06); //status do Relé
                                Mb.R[0] = 0;    
                                break;

                //RELÉ 07
                        case 9107: //RÉGUA ELETROS - INVERTE ESTADO RELÉ
                                digitalWrite(RELE07, !digitalRead(RELE07));
                                //Mb.R[16]=digitalRead(RELE07); //status do Relé
                                Mb.R[0] = 0;
                                   Serial.print("Clicou no botao 7   ");
                                   Serial.print("Porta do Rele:");
                                   Serial.println(RELE07);    
                                break;
                        case 9117: //RÉGUA ELETROS - LIGA
                                digitalWrite(RELE07, 1);
                                //Mb.R[16]=digitalRead(RELE07); //status do Relé
                                Mb.R[0] = 0;    
                                break;
                        case 9007: //RÉGUA ELETROS - DESLIGA RELÉ
                                digitalWrite(RELE07, 0);
                                //Mb.R[16]=digitalRead(RELE07); //status do Relé
                                Mb.R[0] = 0;    
                                break;

                //RELÉ 08
                        case 9108: //RÉGUA ELETROS - INVERTE ESTADO RELÉ
                                digitalWrite(RELE08, !digitalRead(RELE08));
                                //Mb.R[17]=digitalRead(RELE08); //status do Relé
                                Mb.R[0] = 0;
                                   Serial.print("Clicou no botao 8   ");
                                   Serial.print("Porta do Rele:");
                                   Serial.println(RELE08);    
                                break;
                        case 9118: //RÉGUA ELETROS - LIGA
                                digitalWrite(RELE08, 1);
                                //Mb.R[17]=digitalRead(RELE08); //status do Relé
                                Mb.R[0] = 0;    
                                break;
                        case 9008: //RÉGUA ELETROS - DESLIGA RELÉ
                                digitalWrite(RELE08, 0);
                                //Mb.R[17]=digitalRead(RELE08); //status do Relé
                                Mb.R[0] = 0;    
                                break;

*/
// ---------------------------------   fim RELÉS   ---------------------------------------------
} // fim switch



} // fim loop
