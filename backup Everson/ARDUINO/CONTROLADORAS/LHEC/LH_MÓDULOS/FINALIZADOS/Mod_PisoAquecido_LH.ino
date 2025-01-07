
        boolean pressedSingleButPiso01  = false;     
        boolean pressedSingleButPiso02  = false;     
        boolean pressedSingleButPiso03  = false;     
/*        boolean pressedSingleButPiso04  = false;     
        boolean pressedSingleButPiso05  = false;     
        boolean pressedSingleButPiso06  = false;     
        boolean pressedSingleButPiso07  = false;     
        boolean pressedSingleButPiso08  = false;     
*/
        bool estadoPiso01         = 0; // variavel de controle
        bool estadoPiso02         = 0; // variavel de controle
        bool estadoPiso03         = 0; // variavel de controle
/*        bool estadoPiso04         = 0; // variavel de controle
        bool estadoPiso05         = 0; // variavel de controle
        bool estadoPiso06         = 0; // variavel de controle
        bool estadoPiso07         = 0; // variavel de controle
        bool estadoPiso08         = 0; // variavel de controle
*/


//void setup()
void preparePisoAquec()
     {

//CONFIGURAÇÕES DOS INTERRUPTORES

        pinMode(INTERR_PISO01, INPUT_PULLUP); // define o pino do botao como entrada
        pinMode(INTERR_PISO02, INPUT_PULLUP); // define o pino do botao como entrada
        pinMode(INTERR_PISO03, INPUT_PULLUP); // define o pino do botao como entrada
//        pinMode(INTERR_PISO04, INPUT_PULLUP); // define o pino do botao como entrada
/*        pinMode(INTERR_PISO05, INPUT_PULLUP); // define o pino do botao como entrada
        pinMode(INTERR_PISO06, INPUT_PULLUP); // define o pino do botao como entrada
        pinMode(INTERR_PISO07, INPUT_PULLUP); // define o pino do botao como entrada
        pinMode(INTERR_PISO08, INPUT_PULLUP); // define o pino do botao como entrada
*/

//CONFIGURAÇÕES MÓDULOS RELÉS PARA O PISO

        //Ao Reiniciar o sistema aciona automaticamente os relés:
        digitalWrite(RELE_PISO01, HIGH); //
        digitalWrite(RELE_PISO02, HIGH); //
        digitalWrite(RELE_PISO03, HIGH); //
//        digitalWrite(RELE_PISO04, HIGH); //
//        digitalWrite(RELE_PISO05, LOW); //
//        digitalWrite(RELE_PISO06, HIGH); //
//        digitalWrite(RELE_PISO07, HIGH); //
//        digitalWrite(RELE_PISO08, HIGH); //

        
        
        pinMode(RELE_PISO01, OUTPUT);// define LED como saida
        pinMode(RELE_PISO02, OUTPUT);// define LED como saida
        pinMode(RELE_PISO03, OUTPUT);// define LED como saida
//        pinMode(RELE_PISO04, OUTPUT);// define LED como saida
//        pinMode(RELE_PISO05, OUTPUT);// define LED como saida
//        pinMode(RELE_PISO06, OUTPUT);// define LED como saida
//        pinMode(RELE_PISO07, OUTPUT);// define LED como saida
//        pinMode(RELE_PISO08, OUTPUT);// define LED como saida

}



//void loop()
void monitoringPisoAquec(){


   //INTERR_PISO 01
           if (digitalRead(INTERR_PISO01) == LOW && pressedSingleButPiso01 == false) { // Se o botão for pressionado
                delay(40);
                 if (digitalRead(INTERR_PISO01) == LOW){
                    estadoPiso01 = !estadoPiso01; // troca o estado do LED

                    digitalWrite(RELE_PISO01, estadoPiso01);

                    while (digitalRead(INTERR_PISO01) == LOW);
                    delay(100);
                       //Mb.R[10]=digitalRead(RELE_PISO01); //status do Relé
                       Mb.R[0] = 0;    
                       Serial.print("Clicou no botao 1   ");
                       Serial.print("Estado do RELE_PISO:");
                       Serial.println(estadoPiso01);
            }
           }

   //INTERR_PISO 02
           if (digitalRead(INTERR_PISO02) == LOW && pressedSingleButPiso02 == false) { // Se o botão for pressionado
                delay(40);
                 if (digitalRead(INTERR_PISO02) == LOW){
                    estadoPiso02 = !estadoPiso02; // troca o estado do LED
                    
                    digitalWrite(RELE_PISO02, estadoPiso02);

                    while (digitalRead(INTERR_PISO02) == LOW);
                    delay(100);
                    //   Mb.R[11]=digitalRead(RELE_PISO02); //status do Relé
                       Mb.R[0] = 0;    
                       Serial.print("Clicou no botao 2   ");
                       Serial.print("Estado do RELE_PISO:");
                       Serial.println(estadoPiso02);
            }
           }

   //INTERR_PISO 03
           if (digitalRead(INTERR_PISO03) == LOW && pressedSingleButPiso03 == false) { // Se o botão for pressionado
                delay(40);
                 if (digitalRead(INTERR_PISO03) == LOW){
                    estadoPiso03 = !estadoPiso03; // troca o estado do LED
                    
                    digitalWrite(RELE_PISO03, estadoPiso03);

                    while (digitalRead(INTERR_PISO03) == LOW);
                    delay(100);
                    // Mb.R[12]=digitalRead(RELE_PISO03); //status do Relé
                       Mb.R[0] = 0;    
                       Serial.print("Clicou no botao 3   ");
                       Serial.print("Estado do RELE_PISO:");
                       Serial.println(estadoPiso03);
            }
           }

/*   //INTERR_PISO 04
           if (digitalRead(INTERR_PISO04) == LOW && pressedSingleButPiso04 == false) { // Se o botão for pressionado
                delay(40);
                 if (digitalRead(INTERR_PISO04) == LOW){
                    estadoPiso04 = !estadoPiso04; // troca o estado do LED
                    digitalWrite(RELE_PISO04, estadoPiso04);
                    while (digitalRead(INTERR_PISO04) == LOW);
                    delay(100);
                    //   Mb.R[13]=digitalRead(RELE_PISO04); //status do Relé
                       Mb.R[0] = 0;    
                       Serial.print("Clicou no botao 4   ");
                       Serial.print("Estado do RELE_PISO:");
                       Serial.println(estadoPiso04);
                }
           }
   

   //INTERR_PISO 05
           if (digitalRead(INTERR_PISO05) == LOW && pressedSingleButPiso05 == false) { // Se o botão for pressionado
                delay(40);
                 if (digitalRead(INTERR_PISO05) == LOW){
                    estadoPiso05 = !estadoPiso05; // troca o estado do LED
                    digitalWrite(RELE_PISO05, estadoPiso05);
                    while (digitalRead(INTERR_PISO05) == LOW);
                    delay(100);
                    //   Mb.R[13]=digitalRead(RELE_PISO05); //status do Relé
                       Mb.R[0] = 0;    
                       Serial.print("Clicou no botao 5   ");
                       Serial.print("Estado do RELE_PISO:");
                       Serial.println(estadoPiso05);
                }
           }
            

   //INTERR_PISO 06
           if (digitalRead(INTERR_PISO06) == LOW && pressedSingleButPiso06 == false) { // Se o botão for pressionado
                delay(40);
                 if (digitalRead(INTERR_PISO06) == LOW){
                    estadoPiso06 = !estadoPiso06; // troca o estado do LED
                    digitalWrite(RELE_PISO06, estadoPiso06);
                    while (digitalRead(INTERR_PISO06) == LOW);
                    delay(100);
                    //   Mb.R[12]=digitalRead(RELE_PISO06); //status do Relé
                       Mb.R[0] = 0;    
                       Serial.print("Clicou no botao 6   ");
                       Serial.print("Estado do RELE_PISO:");
                       Serial.println(estadoPiso06);
            }
           }


   //INTERR_PISO 07
           if (digitalRead(INTERR_PISO07) == LOW && pressedSingleButPiso07 == false) { // Se o botão for pressionado
                delay(40);
                 if (digitalRead(INTERR_PISO07) == LOW){
                    estadoPiso07 = !estadoPiso07; // troca o estado do LED
                    digitalWrite(RELE_PISO07, estadoPiso07);
                    while (digitalRead(INTERR_PISO07) == LOW);
                    delay(100);
                    //   Mb.R[12]=digitalRead(RELE_PISO07); //status do Relé
                       Mb.R[0] = 0;    
                       Serial.print("Clicou no botao 7   ");
                       Serial.print("Estado do RELE_PISO:");
                       Serial.println(estadoPiso07);
            }
           }


   //INTERR_PISO 08
           if (digitalRead(INTERR_PISO08) == LOW && pressedSingleButPiso08 == false) { // Se o botão for pressionado
                delay(40);
                 if (digitalRead(INTERR_PISO08) == LOW){
                    estadoPiso08 = !estadoPiso08; // troca o estado do LED
                    digitalWrite(RELE_PISO08, estadoPiso08);
                    while (digitalRead(INTERR_PISO08) == LOW);
                    delay(100);
                    //   Mb.R[12]=digitalRead(RELE_PISO08); //status do Relé
                       Mb.R[0] = 0;    
                       Serial.print("Clicou no botao 8   ");
                       Serial.print("Estado do RELE_PISO:");
                       Serial.println(estadoPiso08);
            }
           }


/*
 * 
   //CENÁRIO 01
           if (digitalRead(INTERR_PISO05) == LOW) // Se o botão for pressionado
              {
                estadoPiso05 = !estadoPiso05; // troca o estado do LED
                digitalWrite(RELE_PISO01, 1);
                digitalWrite(RELE_PISO02, 0);
                digitalWrite(RELE_PISO03, 0);
                digitalWrite(RELE_PISO04, 1);
                while (digitalRead(INTERR_PISO05) == LOW);
                delay(100);
//                  // Mb.R[6]=digitalRead(RELE_PISO04); //status do Relé
                   Mb.R[0] = 0;    
            }*/


}
//===============================================================================================================


void monitoringI3PISO()
{//Inicio Loop


  // Executa comunicacao modbus
        Mb.Run();

  // Verifica o valor da 1a variavel modbus
        switch (Mb.R[0])
           {//inicio switch


                //RELÉ 01
                        case 9101: //RÉGUA ELETROS - INVERTE ESTADO RELÉ
                                digitalWrite(RELE_PISO01, !digitalRead(RELE_PISO01));
                                //Mb.R[10]=digitalRead(RELE_PISO01); //status do Relé
                                Mb.R[0] = 0;
                                   Serial.print("Clicou no botao 1   ");
                                   Serial.print("Porta do Rele:");
                                   Serial.println(RELE_PISO01);    
                                break;
                        case 9111: //RÉGUA ELETROS - LIGA
                                digitalWrite(RELE_PISO01, 1);
                                //Mb.R[10]=digitalRead(RELE_PISO01); //status do Relé
                                Mb.R[0] = 0;    
                                break;
                        case 9001: //RÉGUA ELETROS - DESLIGA RELÉ
                                digitalWrite(RELE_PISO01, 0);
                                //Mb.R[10]=digitalRead(RELE_PISO01); //status do Relé
                                Mb.R[0] = 0;  
                                   Serial.print("Clicou no botao 1   ");
                                   Serial.print("Porta do Rele:");
                                   Serial.println(RELE_PISO01);                                  
                                break;

                //RELÉ 02
                        case 9102: //RÉGUA ELETROS - INVERTE ESTADO RELÉ
                                digitalWrite(RELE_PISO02, !digitalRead(RELE_PISO02));
                    //            Mb.R[11]=digitalRead(RELE_PISO02); //status do Relé
                                Mb.R[0] = 0;
                                   Serial.print("Clicou no botao 2   ");
                                   Serial.print("Porta do Rele:");
                                   Serial.println(RELE_PISO02);      
                                break;
                        case 9112: //RÉGUA ELETROS - LIGA
                                digitalWrite(RELE_PISO02, 1);
                    //            Mb.R[11]=digitalRead(RELE_PISO02); //status do Relé
                                Mb.R[0] = 0;    
                                break;
                        case 9002: //RÉGUA ELETROS - DESLIGA RELÉ
                                digitalWrite(RELE_PISO02, 0);
                    //            Mb.R[11]=digitalRead(RELE_PISO02); //status do Relé
                                Mb.R[0] = 0;    
                                break;

                //RELÉ 03
                        case 9103: //RÉGUA ELETROS - INVERTE ESTADO RELÉ
                                digitalWrite(RELE_PISO03, !digitalRead(RELE_PISO03));
                    //            Mb.R[12]=digitalRead(RELE_PISO03); //status do Relé
                                Mb.R[0] = 0;
                                   Serial.print("Clicou no botao 3   ");
                                   Serial.print("Porta do Rele:");
                                   Serial.println(RELE_PISO03);
                                    
                                break;
                        case 9113: //RÉGUA ELETROS - LIGA
                                digitalWrite(RELE_PISO03, 1);
                    //            Mb.R[12]=digitalRead(RELE_PISO03); //status do Relé
                                Mb.R[0] = 0;    
                                break;
                        case 9003: //RÉGUA ELETROS - DESLIGA RELÉ
                                digitalWrite(RELE_PISO03, 0);
                    //            Mb.R[12]=digitalRead(RELE_PISO03); //status do Relé
                                Mb.R[0] = 0;    
                                break;
/*
                //RELÉ 04
                        case 9104: //RÉGUA ELETROS - INVERTE ESTADO RELÉ
                                digitalWrite(RELE_PISO04, !digitalRead(RELE_PISO04));
                    //            Mb.R[13]=digitalRead(RELE04); //status do Relé
                                Mb.R[0] = 0;
                                   Serial.print("Clicou no botao 4   ");
                                   Serial.print("Porta do Rele:");
                                   Serial.println(RELE_PISO04);    
                                break;
                        case 9114: //RÉGUA ELETROS - LIGA
                                digitalWrite(RELE_PISO04, 1);
                    //            Mb.R[13]=digitalRead(RELE_PISO04); //status do Relé
                                Mb.R[0] = 0;    
                                break;
                        case 9004: //RÉGUA ELETROS - DESLIGA RELÉ
                                digitalWrite(RELE_PISO04, 0);
                    //            Mb.R[13]=digitalRead(RELE_PISO04); //status do Relé
                                Mb.R[0] = 0;    
                                break;

                //RELÉ 05
                        case 9105: //RÉGUA ELETROS - INVERTE ESTADO RELÉ
                                digitalWrite(RELE_PISO05, !digitalRead(RELE_PISO05));
                    //            Mb.R[14]=digitalRead(RELE_PISO05); //status do Relé
                                Mb.R[0] = 0;
                                   Serial.print("Clicou no botao 5   ");
                                   Serial.print("Porta do Rele:");
                                   Serial.println(RELE_PISO05);     
                                break;
                        case 9115: //RÉGUA ELETROS - LIGA
                                digitalWrite(RELE_PISO05, 1);
                    //            Mb.R[14]=digitalRead(RELE_PISO05); //status do Relé
                                Mb.R[0] = 0;    
                                break;
                        case 9005: //RÉGUA ELETROS - DESLIGA RELÉ
                                digitalWrite(RELE_PISO05, 0);
                    //            Mb.R[14]=digitalRead(RELE_PISO05); //status do Relé
                                Mb.R[0] = 0;    
                                break;                                

                //RELÉ 06
                        case 9106: //RÉGUA ELETROS - INVERTE ESTADO RELÉ
                                digitalWrite(RELE_PISO06, !digitalRead(RELE_PISO06));
                    //            Mb.R[15]=digitalRead(RELE_PISO06); //status do Relé
                                Mb.R[0] = 0;
                                   Serial.print("Clicou no botao 6   ");
                                   Serial.print("Porta do Rele:");
                                   Serial.println(RELE_PISO06);    
                                break;
                        case 9116: //RÉGUA ELETROS - LIGA
                                digitalWrite(RELE_PISO06, 1);
                    //            Mb.R[15]=digitalRead(RELE_PISO06); //status do Relé
                                Mb.R[0] = 0;    
                                break;
                        case 9006: //RÉGUA ELETROS - DESLIGA RELÉ
                                digitalWrite(RELE_PISO06, 0);
                    //            Mb.R[15]=digitalRead(RELE_PISO06); //status do Relé
                                Mb.R[0] = 0;    
                                break;

                //RELÉ 07
                        case 9107: //RÉGUA ELETROS - INVERTE ESTADO RELÉ
                                digitalWrite(RELE_PISO07, !digitalRead(RELE_PISO07));
                    //            Mb.R[16]=digitalRead(RELE_PISO07); //status do Relé
                                Mb.R[0] = 0;
                                   Serial.print("Clicou no botao 7   ");
                                   Serial.print("Porta do Rele:");
                                   Serial.println(RELE_PISO07);    
                                break;
                        case 9117: //RÉGUA ELETROS - LIGA
                                digitalWrite(RELE_PISO07, 1);
                    //            Mb.R[16]=digitalRead(RELE_PISO07); //status do Relé
                                Mb.R[0] = 0;    
                                break;
                        case 9007: //RÉGUA ELETROS - DESLIGA RELÉ
                                digitalWrite(RELE_PISO07, 0);
                    //            Mb.R[16]=digitalRead(RELE_PISO07); //status do Relé
                                Mb.R[0] = 0;    
                                break;

                //RELÉ 08
                        case 9108: //RÉGUA ELETROS - INVERTE ESTADO RELÉ
                                digitalWrite(RELE_PISO08, !digitalRead(RELE_PISO08));
                    //            Mb.R[17]=digitalRead(RELE_PISO08); //status do Relé
                                Mb.R[0] = 0;
                                   Serial.print("Clicou no botao 8   ");
                                   Serial.print("Porta do Rele:");
                                   Serial.println(RELE_PISO08);    
                                break;
                        case 9118: //RÉGUA ELETROS - LIGA
                                digitalWrite(RELE_PISO08, 1);
                    //            Mb.R[17]=digitalRead(RELE_PISO08); //status do Relé
                                Mb.R[0] = 0;    
                                break;
                        case 9008: //RÉGUA ELETROS - DESLIGA RELÉ
                                digitalWrite(RELE_PISO08, 0);
                    //            Mb.R[17]=digitalRead(RELE_PISO08); //status do Relé
                                Mb.R[0] = 0;    
                                break;

*/
// ---------------------------------   fim RELÉS   ---------------------------------------------
} // fim switch



} // fim loop

