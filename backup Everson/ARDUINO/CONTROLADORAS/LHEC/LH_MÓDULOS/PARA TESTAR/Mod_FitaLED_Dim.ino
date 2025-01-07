/*
 * Controle fita Led Branca Dimerizada, 
 * conforme muda a intensidade da fita a intensidade é mostrada no monitor serial
 * OK - TESTADA E FUNCIONANDO - 27/03/2023
 * anter portas de saída 6
 */


int FitaLED             = 8;        //Porta Digital para conexão da Fita Led.
int Brilho              = 0;        //Variável para o definição do brilho da FitaLED.
int Quantidade          = 5;        //Variável para a quantidade de brilho.

#define VALOR_MAXIMO 255
#define VALOR_MINIMO 0

void prepareFitaLed()
{
  pinMode(FitaLED, OUTPUT);

  //Ao Reiniciar o sistema aciona automaticamente os relés:
  digitalWrite(FitaLED, LOW); //LUZ HOME THEATER BRANCA
}




void monitoringFitaLed()
{
  analogWrite(FitaLED, Brilho);   //Liga o LED com o brilho definido:

    Mb.Run();                     // Executa comunicacao modbus

      switch (Mb.R[0])            // Verifica o valor da 1a variavel modbus

           {//inicio switch

                //DIMMER FITA LED +
                        case 2044: //Aumenta  Brilho da Fita Led
                                  if(Brilho < VALOR_MAXIMO)
                                  Brilho = Brilho + Quantidade;
                                  Mb.R[0] = 0;    
                                  break;
                                  
                        case 2045: //Diminui o Brilho da Fita Led
                                  if(Brilho > VALOR_MINIMO)
                                  Brilho = Brilho - Quantidade;
                                  Mb.R[0] = 0;    
                                  break; 
                                  
                        case 2046: //Regua a fita em 50%
                                  Brilho = 0;
                                  Mb.R[0] = 0;    
                                  break;   
                                  
                        case 2047: //Regua a fita em 50%
                                  Brilho = 63.75;
                                  Mb.R[0] = 0;    
                                  break;                                           

                        case 2048: //Regua a fita em 50%
                                  Brilho = 127.5;
                                  Mb.R[0] = 0;    
                                  break;   

                        case 2049: //Regua a fita em 50%
                                  Brilho = 191.25;
                                  Mb.R[0] = 0;    
                                  break;
                                                                           
                        case 2050: //Regua a fita em 50%
                                  Brilho = 255;
                                  Mb.R[0] = 0;    
                                  break;
                                
           }//fim switch


            // Mostra dados no serial monitor
            Serial.print("Brilho: ");
            Serial.println(Brilho);
            Mb.R[6]= Brilho;                //Escreve no MdBus o valor da potencia da fita led


  

    //Alterar o brilho do LED:
         //Brilho = Brilho + Quantidade;
    //Se o brilho estiver no mínimo ou no máximo (Min=0 e Max=255):
         //if (Brilho <= 0 || Brilho >= 255){
    //Inverter a quantidade de brilho do LED.
         //Quantidade = - Quantidade;
//  }

//  Serial.println(Brilho);         //Escreve no monitor serial o valor da variável:


}
