



void prepareI3PRO()
{


     
}//FIM SETUP
//*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,





void monitoringI3PRO()
{//Inicio Loop


  // Executa comunicacao modbus
        Mb.Run();

  // Verifica o valor da 1a variavel modbus
        switch (Mb.R[0])
           {//inicio switch


                //RELÉ 01
                        case 9101: //RÉGUA ELETROS - INVERTE ESTADO RELÉ
                                digitalWrite(LEDred, !digitalRead(LEDred));
                                Mb.R[10]=digitalRead(LEDred); //status do Relé
                                Mb.R[0] = 0;
                                   Serial.print("Clicou no botao 1   ");
                                   Serial.print("Porta do Rele:");
                                   Serial.println(LEDred);    
                                break;
                        case 9111: //RÉGUA ELETROS - LIGA
                                digitalWrite(LEDred, 1);
                                Mb.R[10]=digitalRead(LEDred); //status do Relé
                                Mb.R[0] = 0;    
                                break;
                        case 9001: //RÉGUA ELETROS - DESLIGA RELÉ
                                digitalWrite(LEDred, 0);
                                Mb.R[10]=digitalRead(LEDred); //status do Relé
                                Mb.R[0] = 0;  
                                   Serial.print("Clicou no botao 1   ");
                                   Serial.print("Porta do Rele:");
                                   Serial.println(LEDred);                                  
                                break;

                //RELÉ 02
                        case 9102: //RÉGUA ELETROS - INVERTE ESTADO RELÉ
                                digitalWrite(LEDgreen, !digitalRead(LEDgreen));
                                Mb.R[11]=digitalRead(LEDgreen); //status do Relé
                                Mb.R[0] = 0;
                                   Serial.print("Clicou no botao 2   ");
                                   Serial.print("Porta do Rele:");
                                   Serial.println(LEDgreen);      
                                break;
                        case 9112: //RÉGUA ELETROS - LIGA
                                digitalWrite(LEDgreen, 1);
                                Mb.R[11]=digitalRead(LEDgreen); //status do Relé
                                Mb.R[0] = 0;    
                                break;
                        case 9002: //RÉGUA ELETROS - DESLIGA RELÉ
                                digitalWrite(LEDgreen, 0);
                                Mb.R[11]=digitalRead(LEDgreen); //status do Relé
                                Mb.R[0] = 0;    
                                break;

                //RELÉ 03
                        case 9103: //RÉGUA ELETROS - INVERTE ESTADO RELÉ
                                digitalWrite(LEDblue, !digitalRead(LEDblue));
                                Mb.R[12]=digitalRead(LEDblue); //status do Relé
                                Mb.R[0] = 0;
                                   Serial.print("Clicou no botao 3   ");
                                   Serial.print("Porta do Rele:");
                                   Serial.println(LEDblue);
                                    
                                break;
                        case 9113: //RÉGUA ELETROS - LIGA
                                digitalWrite(LEDblue, 1);
                                Mb.R[12]=digitalRead(LEDblue); //status do Relé
                                Mb.R[0] = 0;    
                                break;
                        case 9003: //RÉGUA ELETROS - DESLIGA RELÉ
                                digitalWrite(LEDblue, 0);
                                Mb.R[12]=digitalRead(LEDblue); //status do Relé
                                Mb.R[0] = 0;    
                                break;

  /*              //RELÉ 04
                        case 9104: //RÉGUA ELETROS - INVERTE ESTADO RELÉ
                                digitalWrite(RELE04, !digitalRead(RELE04));
                                Mb.R[13]=digitalRead(RELE04); //status do Relé
                                Mb.R[0] = 0;
                                   Serial.print("Clicou no botao 4   ");
                                   Serial.print("Porta do Rele:");
                                   Serial.println(RELE04);    
                                break;
                        case 9114: //RÉGUA ELETROS - LIGA
                                digitalWrite(RELE04, 1);
                                Mb.R[13]=digitalRead(RELE04); //status do Relé
                                Mb.R[0] = 0;    
                                break;
                        case 9004: //RÉGUA ELETROS - DESLIGA RELÉ
                                digitalWrite(RELE04, 0);
                                Mb.R[13]=digitalRead(RELE04); //status do Relé
                                Mb.R[0] = 0;    
                                break;
/*
                //RELÉ 05
                        case 9105: //RÉGUA ELETROS - INVERTE ESTADO RELÉ
                                digitalWrite(RELE05, !digitalRead(RELE05));
                                Mb.R[14]=digitalRead(RELE05); //status do Relé
                                Mb.R[0] = 0;
                                   Serial.print("Clicou no botao 5   ");
                                   Serial.print("Porta do Rele:");
                                   Serial.println(RELE05);     
                                break;
                        case 9115: //RÉGUA ELETROS - LIGA
                                digitalWrite(RELE05, 1);
                                Mb.R[14]=digitalRead(RELE05); //status do Relé
                                Mb.R[0] = 0;    
                                break;
                        case 9005: //RÉGUA ELETROS - DESLIGA RELÉ
                                digitalWrite(RELE05, 0);
                                Mb.R[14]=digitalRead(RELE05); //status do Relé
                                Mb.R[0] = 0;    
                                break;                                

                //RELÉ 06
                        case 9106: //RÉGUA ELETROS - INVERTE ESTADO RELÉ
                                digitalWrite(RELE06, !digitalRead(RELE06));
                                Mb.R[15]=digitalRead(RELE06); //status do Relé
                                Mb.R[0] = 0;
                                   Serial.print("Clicou no botao 6   ");
                                   Serial.print("Porta do Rele:");
                                   Serial.println(RELE06);    
                                break;
                        case 9116: //RÉGUA ELETROS - LIGA
                                digitalWrite(RELE06, 1);
                                Mb.R[15]=digitalRead(RELE06); //status do Relé
                                Mb.R[0] = 0;    
                                break;
                        case 9006: //RÉGUA ELETROS - DESLIGA RELÉ
                                digitalWrite(RELE06, 0);
                                Mb.R[15]=digitalRead(RELE06); //status do Relé
                                Mb.R[0] = 0;    
                                break;

                //RELÉ 07
                        case 9107: //RÉGUA ELETROS - INVERTE ESTADO RELÉ
                                digitalWrite(RELE07, !digitalRead(RELE07));
                                Mb.R[16]=digitalRead(RELE07); //status do Relé
                                Mb.R[0] = 0;
                                   Serial.print("Clicou no botao 7   ");
                                   Serial.print("Porta do Rele:");
                                   Serial.println(RELE07);    
                                break;
                        case 9117: //RÉGUA ELETROS - LIGA
                                digitalWrite(RELE07, 1);
                                Mb.R[16]=digitalRead(RELE07); //status do Relé
                                Mb.R[0] = 0;    
                                break;
                        case 9007: //RÉGUA ELETROS - DESLIGA RELÉ
                                digitalWrite(RELE07, 0);
                                Mb.R[16]=digitalRead(RELE07); //status do Relé
                                Mb.R[0] = 0;    
                                break;

                //RELÉ 08
                        case 9108: //RÉGUA ELETROS - INVERTE ESTADO RELÉ
                                digitalWrite(RELE08, !digitalRead(RELE08));
                                Mb.R[17]=digitalRead(RELE08); //status do Relé
                                Mb.R[0] = 0;
                                   Serial.print("Clicou no botao 8   ");
                                   Serial.print("Porta do Rele:");
                                   Serial.println(RELE08);    
                                break;
                        case 9118: //RÉGUA ELETROS - LIGA
                                digitalWrite(RELE08, 1);
                                Mb.R[17]=digitalRead(RELE08); //status do Relé
                                Mb.R[0] = 0;    
                                break;
                        case 9008: //RÉGUA ELETROS - DESLIGA RELÉ
                                digitalWrite(RELE08, 0);
                                Mb.R[17]=digitalRead(RELE08); //status do Relé
                                Mb.R[0] = 0;    
                                break;

*/
// ---------------------------------   fim RELÉS   ---------------------------------------------
} // fim switch



} // fim loop
