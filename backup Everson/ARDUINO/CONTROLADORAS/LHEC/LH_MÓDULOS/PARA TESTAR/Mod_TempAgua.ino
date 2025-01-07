 
//https://curtocircuito.com.br/blog/Categoria%20Arduino/como-utilizar-o-ds18b20

// Porta do pino de sinal do DS18B20
#define ONE_WIRE_BUS 30
 
// Define uma instancia do oneWire para comunicacao com o sensor
OneWire oneWire(ONE_WIRE_BUS);
 
// Armazena temperaturas minima e maxima
float tempMin = 999;
float tempMax = 0;
 
DallasTemperature sensors(&oneWire);
DeviceAddress sensor1;



      //Definições para a leitura do sensor - Função Time
        unsigned long futureTemp03 = {0};
        #define TIME_PAUSE_TEMPAGUA    5200



 
void prepareTempAgua(void)
{
  Mb.R[58] = 17; //Definição Temperatura Inicial ao reiniciar o arduino
  
//  Serial.begin(9600);
  sensors.begin();
  // Localiza e mostra enderecos dos sensores
  Serial.println("Localizando sensores DS18B20...");
  Serial.print("Foram encontrados ");
  Serial.print(sensors.getDeviceCount(), DEC);
  Serial.println(" sensores.");
  if (!sensors.getAddress(sensor1, 0)) 
     Serial.println("Sensores nao encontrados !"); 
  // Mostra o endereco do sensor encontrado no barramento
  Serial.print("Endereco sensor: ");
  mostra_endereco_sensor(sensor1);
  Serial.println();
  Serial.println();
}
 
void mostra_endereco_sensor(DeviceAddress deviceAddress)
{
  for (uint8_t i = 0; i < 8; i++)
  {
    // Adiciona zeros se necessário
    if (deviceAddress[i] < 16) Serial.print("0");
    Serial.print(deviceAddress[i], HEX);
  }
}
 
void monitoringTempAgua()
{

   if(timeIsOver(futureTemp03)){
    
            // Le a informacao do sensor
            sensors.requestTemperatures();
            float tempC = sensors.getTempC(sensor1);
            // Atualiza temperaturas minima e maxima
            if (tempC < tempMin)
            {
              tempMin = tempC;
            }
            if (tempC > tempMax)
            {
              tempMax = tempC;
            }
            // Mostra dados no serial monitor
            Serial.print("Temp C: ");
            Serial.print(tempC);
            Mb.R[59]=(tempC); //Informa para o Modbus a temperatura ambiente
            Serial.print(" Min : ");
            Serial.print(tempMin);
            Serial.print(" Max : ");
            Serial.println(tempMax);
          
              
            if(tempC < Mb.R[58]){      //se a temperaturaC lida for inferior a 27 °C
              digitalWrite(12, HIGH);            //apaga led da porta 10
              digitalWrite(13, LOW);            //apaga led da porta 11
                  
            }else if(tempC >= Mb.R[58]){  //se a temperaturaC lida estiver entre 27 ºC e 31 ºC
              digitalWrite(12, LOW);           //acende led da porta 10
              digitalWrite(13, HIGH);            //apaga led da porta 11
            
            //delay(1000);
            }

           futureTemp03 = millis() + TIME_PAUSE_TEMPAGUA;
}       

}
