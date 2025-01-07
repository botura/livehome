int vlrsensFOTOCEL01;                                                     // valor que sera armazenado o valor do LDR
//int statuscort01 = 28;                                                      // pino digital do sensor de cortina fim de curso reed switch


//Definições para a leitura do sensor - Função Time
  unsigned long futureFOTOCEL01 = {0};
  #define TIME_PAUSE_FOTOCEL01_1    300000                                  //900000 A cada 15 minutos o sistema fará leitura da temperatura
  #define TIME_PAUSE_FOTOCEL01_2    6000                                  //900000 A cada 15 minutos o sistema fará leitura da temperatura



void prepareFOTOCELULA() {

       Mb.R[46] = 700;                                                //Definição mínima Inicial ao reiniciar o arduino

  
  pinMode(RELEXTERNO, OUTPUT);                                          // Coloca variavel RELEXTERNO é um sinal de saida
  pinMode(FOTOCEL01, INPUT);                                              // Coloca a variavel LDR como entrada
//  pinMode(statuscort01, INPUT);                                             // Define o pino do sensor reed switch como entrada

}


void monitoringFOTOCELULA_I() {

  if(timeIsOver(futureFOTOCEL01)){
    
              
              vlrsensFOTOCEL01 = analogRead(FOTOCEL01);                       // Faz a leitura do pino analógico LDR e armazena o valor na variavel valorsensor
              
              Serial.print("LDR : " );                                // Mostra o valor no monitor serial
              Serial.println(vlrsensFOTOCEL01);
                Mb.R[45]=(vlrsensFOTOCEL01);                              //Informa para o Modbus a luminosidade do ambiente

      futureFOTOCEL01 = millis() + TIME_PAUSE_FOTOCEL01_1;
     }

}





void monitoringFOTOCELULA_AUT() {

  if(timeIsOver(futureFOTOCEL01)){
    
              
              vlrsensFOTOCEL01 = analogRead(FOTOCEL01);                         // Faz a leitura do pino analógico LDR e armazena o valor na variavel valorsensor
              
              Serial.print("LDR : " );                                  // Escreve a palavra LDR no monitor serial
              Serial.println(vlrsensFOTOCEL01);                             // Mostra o valor do sensor no monitor serial
                Mb.R[45]=(vlrsensFOTOCEL01);                                // Informa para o Modbus a luminosidade do ambiente, o valor do sensor ldr
            
              if (vlrsensFOTOCEL01 > Mb.R[46]) {                            // Se o valor do sensor for maior que a informação do modbus 46 no setup
                digitalWrite(RELEXTERNO, HIGH);                            // deixa a luz/relé desligado
                Serial.println("Relé Acionado");
                } 
              else if(vlrsensFOTOCEL01 <= Mb.R[46]){                        // Se o valor do sensor for menor ou igual a informação do modbus 46 no setup
                digitalWrite(RELEXTERNO, LOW);                           // o sensor da um pulso para acionar a cortina
                Serial.println("Relé Desligado");
                //delay(1000);             
                //digitalWrite(RELEXTERNO, LOW); 
              }

      futureFOTOCEL01 = millis() + TIME_PAUSE_FOTOCEL01_1;
     }

}

