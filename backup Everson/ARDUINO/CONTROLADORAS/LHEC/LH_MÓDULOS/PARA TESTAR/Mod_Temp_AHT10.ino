//Bibliotecas são declaradas 
#include <Wire.h>                                                    // Biblioteca para estabelecer comunicação I2C
#include <AHT10.h>                                                   // Biblioteca para usar o sensor AHT10


AHT10 myAHT10(0x38);                                                 // Nome e endereço do sensor



//Definições para a leitura do sensor - Função Time
  unsigned long futureTemp01 = {0};
  #define TIME_PAUSE_TEMP    5000                                //900000 A cada 15 minutos o sistema fará leitura da temperatura



void prepare_tempAHT10()
//void setup() 
{

        Mb.R[58] = 17;                                                       //Definição Temperatura mínima Inicial ao reiniciar o arduino

  
        Wire.begin();                                                        // Função que inicializa a biblioteca Wire
//        Serial.begin(9600);                                                  //A comunicação serial é iniciada 
        Serial.println("Sensor Temperatura Iniciado...");                       // O nome do sensor é impresso
        if (!myAHT10.begin()) {                                              // Se a comunicação com o sensor falhar, uma mensagem de erro será impressa 
        Serial.println("Error no se el sensor!");
        while (1);
        }
}





void monitoring_tempAHT10()
//void loop() 
{

     if(timeIsOver(futureTemp01)){
      
                   
              float temp = myAHT10.readTemperature();                                //A temperatura é lida e "tem" é atribuído
              float hum = myAHT10.readHumidity();                                    //A umidade é lida e "hum" é atribuído 
              Serial.print("Temp: "); Serial.print(temp); Serial.print(" °C");       //O valor da temperatura é impresso 
              Mb.R[59]=(temp);                                                       //Informa para o Modbus a temperatura ambiente
              Serial.print("tt");                                                    // Imprima duas guias para acomodar os valores de temperatura e umidade
              Serial.print("Umidade: "); Serial.print(hum); Serial.println(" %");    //O valor da umidade é impresso
              Mb.R[57]=(hum); 
              //delay(1000);
          
          futureTemp01 = millis() + TIME_PAUSE_TEMP;
          }   
}
