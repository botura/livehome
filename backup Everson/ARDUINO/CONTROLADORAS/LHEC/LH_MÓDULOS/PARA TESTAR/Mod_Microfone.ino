/*
 * Controle fita Led RGB POR MICROFONE, 
 * Vários efeitos de cores
 * OK - TESTADA E FUNCIONANDO - 28/03/2023
 * Manter portas de saída 9, 8 e 7
 */



//SENSOR RGB
      int soundSensor     = 31; //PINO DIGITAL UTILIZADO PELO MICROFONE
      int LEDr            = 9;
      int LEDg            = 8;
      int LEDb            = 7;




void prepareMicrofone(){
     pinMode (soundSensor, INPUT); //define Sound Sensor as input

     pinMode (LEDr, OUTPUT);        //define LED Strip as output
     pinMode (LEDg, OUTPUT);        //define LED Strip as output
     pinMode (LEDb, OUTPUT);

}


void monitoringMicrofone(){

           int statusSensor = digitalRead (soundSensor);   //definir variável do status do Sensor de Som
                                                           //e leia o valor do sensor
  
               // Executa comunicacao modbus
               Mb.Run();     
                               
               // Verifica o valor da 1a variavel modbus
               switch (Mb.R[0])            

                       {//inicio switch

                         case 2006: //efeitos branco
    
                                        if (statusSensor == 1)                          //Quando o sensor detecta um sinal
                                            {
                                              digitalWrite(LEDr, LOW);                  //Faixa LED estará ativa
                                              digitalWrite(LEDg, LOW);
                                              digitalWrite(LEDb, LOW);
                                            }
                                      
                                        else                                            //Se nenhum sinal for detectado
                                            {
                                              digitalWrite(LEDr, HIGH);                 //O status da faixa de LED está desativado
                                              digitalWrite(LEDg, HIGH);
                                              digitalWrite(LEDb, HIGH);
                                            } 
                               break;

                         case 2007://efeitos vermelho
                                    digitalWrite(soundSensor, 1);

                                        if (statusSensor == 1)                          //Quando o sensor detecta um sinal
                                            {
                                              digitalWrite(LEDr, LOW);                  //Faixa LED estará ativa
                                              digitalWrite(LEDg, LOW);
                                              digitalWrite(LEDb, LOW);
                                            }
                                      
                                        else                                            //Se nenhum sinal for detectado
                                            {
                                              digitalWrite(LEDr, HIGH);                 //O status da faixa de LED está desativado
                                              digitalWrite(LEDg, LOW);
                                              digitalWrite(LEDb, LOW);
                                            } 

                               break;


                         case 2008: //efeitos verde
                                    digitalWrite(soundSensor, 1);

                                        if (statusSensor == 1)                          //Quando o sensor detecta um sinal
                                            {
                                              digitalWrite(LEDr, LOW);                  //Faixa LED estará ativa
                                              digitalWrite(LEDg, LOW);
                                              digitalWrite(LEDb, LOW);
                                            }
                                      
                                        else                                            //Se nenhum sinal for detectado
                                            {
                                              digitalWrite(LEDr, LOW);                 //O status da faixa de LED está desativado
                                              digitalWrite(LEDg, HIGH);
                                              digitalWrite(LEDb, LOW);
                                            } 

                               break;

                         case 2009: //efeitos azul
                                    digitalWrite(soundSensor, 1);

                                        if (statusSensor == 1)                          //Quando o sensor detecta um sinal
                                            {
                                              digitalWrite(LEDr, LOW);                  //Faixa LED estará ativa
                                              digitalWrite(LEDg, LOW);
                                              digitalWrite(LEDb, LOW);
                                            }
                                      
                                        else                                            //Se nenhum sinal for detectado
                                            {
                                              digitalWrite(LEDr, LOW);                 //O status da faixa de LED está desativado
                                              digitalWrite(LEDg, LOW);
                                              digitalWrite(LEDb, HIGH);
                                            } 

                         break;

                         case 2010: //efeitos sortidos
                                    digitalWrite(soundSensor, 1);

                                        if (statusSensor == 1)                          //Quando o sensor detecta um sinal
                                            {
                                              digitalWrite(LEDr, LOW);                  //Faixa LED estará ativa
                                              digitalWrite(LEDg, LOW);
                                              digitalWrite(LEDb, LOW);
                                            }
                                      
                                        else                                            //Se nenhum sinal for detectado
                                            {
                                              digitalWrite(LEDr, HIGH);                 //O status da faixa de LED está desativado
                                              delay (50);
                                              digitalWrite(LEDg, HIGH);
                                              delay (50);
                                              digitalWrite(LEDb, HIGH);
                                              delay (50);
                                        } 

                         break;

                         case 2011: //DESLIGA
                                    digitalWrite(soundSensor, 0);
                         break;


                         break;                        

                         
                                     }

    
   }
