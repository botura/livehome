/*
 * Controle fita Led Branca Dimerizada, 
 * conforme muda a intensidade da fita a intensidade é mostrada no monitor serial
 * OK - TESTADA E FUNCIONANDO - 27/03/2023
 * anter portas de saída 6
 */


int LEDred               = 8;        //Porta Digital para conexão da Fita Led.
int LEDgreen             = 11;        //Porta Digital para conexão da Fita Led.
int LEDblue              = 12;        //Porta Digital para conexão da Fita Led.

int Brilho_R              = 0;        //Variável para o definição do brilho da FitaLED.
int Brilho_G              = 0;        //Variável para o definição do brilho da FitaLED.
int Brilho_B              = 0;        //Variável para o definição do brilho da FitaLED.

int Quantidade          = 5;        //Variável para a quantidade de brilho.

//DEFINIÇÕES DIMMER
#define VALOR_MAXIMO 255
#define VALOR_MINIMO 0




void prepareFitaLed()
{
  pinMode(FitaLED, OUTPUT);

  //Ao Reiniciar o sistema aciona automaticamente os relés:
  digitalWrite(LEDred, LOW); //LUZ HOME THEATER BRANCA
  digitalWrite(LEDgreen, LOW); //LUZ HOME THEATER BRANCA
  digitalWrite(LEDblue, LOW); //LUZ HOME THEATER BRANCA
}




void monitoringFitaLed()
{
  analogWrite(LEDred, Brilho_R);   //Liga o LED com o brilho definido:
  analogWrite(LEDgreen, Brilho_G);   //Liga o LED com o brilho definido:
  analogWrite(LEDblue, Brilho_B);   //Liga o LED com o brilho definido:

    Mb.Run();                     // Executa comunicacao modbus

      switch (Mb.R[0])            // Verifica o valor da 1a variavel modbus

           {//inicio switch

                //DIMMER FITA LED R
                        case 2044: //Aumenta  Brilho da Fita Led
                                  if(Brilho_R < VALOR_MAXIMO)
                                  Brilho_R = Brilho_R + Quantidade;
                                  Mb.R[0] = 0;    
                                  break;
                                  
                        case 2045: //Diminui o Brilho da Fita Led
                                  if(Brilho_R > VALOR_MINIMO)
                                  Brilho_R = Brilho_R - Quantidade;
                                  Mb.R[0] = 0;    
                                  break; 

                //DIMMER FITA LED G
                        case 2046: //Aumenta  Brilho da Fita Led
                                  if(Brilho_G < VALOR_MAXIMO)
                                  Brilho_G = Brilho_G + Quantidade;
                                  Mb.R[0] = 0;    
                                  break;
                                  
                        case 2047: //Diminui o Brilho da Fita Led
                                  if(Brilho_G > VALOR_MINIMO)
                                  Brilho_G = Brilho_G - Quantidade;
                                  Mb.R[0] = 0;    
                                  break; 

                //DIMMER FITA LED B
                        case 2048: //Aumenta  Brilho da Fita Led
                                  if(Brilho_B < VALOR_MAXIMO)
                                  Brilho_B = Brilho_B + Quantidade;
                                  Mb.R[0] = 0;    
                                  break;
                                  
                        case 2049: //Diminui o Brilho da Fita Led
                                  if(Brilho_B > VALOR_MINIMO)
                                  Brilho_B = Brilho_B - Quantidade;
                                  Mb.R[0] = 0;    
                                  break; 
                                
           }//fim switch


            // Mostra dados no serial monitor
            //Serial.print("Brilho R: ");
            //Serial.println(Brilho_R);
            //Mb.R[6]= Brilho_R;                //Escreve no MdBus o valor da potencia da fita led


  

    //Alterar o brilho do LED:
         //Brilho = Brilho + Quantidade;
    //Se o brilho estiver no mínimo ou no máximo (Min=0 e Max=255):
         //if (Brilho <= 0 || Brilho >= 255){
    //Inverter a quantidade de brilho do LED.
         //Quantidade = - Quantidade;
//  }

//  Serial.println(Brilho);         //Escreve no monitor serial o valor da variável:


}