/*
 * DESCRIÇÃO DO SISTEMA:
 * Em Monitoring LDR o sistema faz a leitura da intensidade de iluminação no ambiente e mostra no painel de controle
 * Em Monitoring LDR 01 o sistema faz a leitura do ambiente e faz o controle automatico para ligar e desligar uma 
 
 
 
 
 
 
 
  enquanto continua monitorando o sistema
 */
 
int LDR01 =         A15;                                                // Pino analógico que o sensor LDR está conectado
int relpulso =       14;                                              // Pino Referente ao rele de pulso
int vlrsensLDR01;                                                     // valor que sera armazenado o valor do LDR
int statuscort01 = 28;                                                      // pino digital do sensor de cortina fim de curso reed switch


//Definições para a leitura do sensor - Função Time
  unsigned long futureLDR01 = {0};
  #define TIME_PAUSE_LDR01_1    5001                                  //900000 A cada 15 minutos o sistema fará leitura da temperatura
  #define TIME_PAUSE_LDR01_2    6000                                  //900000 A cada 15 minutos o sistema fará leitura da temperatura



void prepareLDR() {

       Mb.R[46] = 500;                                                //Definição mínima Inicial ao reiniciar o arduino

  
  pinMode(relpulso, OUTPUT);                                          // Coloca variavel relpulso é um sinal de saida
  pinMode(LDR01, INPUT);                                              // Coloca a variavel LDR como entrada
  pinMode(statuscort01, INPUT);                                             // Define o pino do sensor reed switch como entrada

}


void monitoringLDR() {

  if(timeIsOver(futureLDR01)){
    
              
              vlrsensLDR01 = analogRead(LDR01);                       // Faz a leitura do pino analógico LDR e armazena o valor na variavel valorsensor
              
              Serial.print("LDR : " );                                // Mostra o valor no monitor serial
              Serial.println(vlrsensLDR01);
                Mb.R[45]=(vlrsensLDR01);                              //Informa para o Modbus a luminosidade do ambiente

      futureLDR01 = millis() + TIME_PAUSE_LDR01_1;
     }

}





void monitoringLDR_AUT() {

  if(timeIsOver(futureLDR01)){
    
              
              vlrsensLDR01 = analogRead(LDR01);                         // Faz a leitura do pino analógico LDR e armazena o valor na variavel valorsensor
              
              Serial.print("LDR : " );                                  // Escreve a palavra LDR no monitor serial
              Serial.println(vlrsensLDR01);                             // Mostra o valor do sensor no monitor serial
                Mb.R[45]=(vlrsensLDR01);                                // Informa para o Modbus a luminosidade do ambiente, o valor do sensor ldr
            
              if (vlrsensLDR01 > Mb.R[46]) {                            // Se o valor do sensor for maior que a informação do modbus 46 no setup
                digitalWrite(relpulso, HIGH);                            // deixa a luz/relé desligado
                } 
              else if(vlrsensLDR01 <= Mb.R[46]){                        // Se o valor do sensor for menor ou igual a informação do modbus 46 no setup
                digitalWrite(relpulso, LOW);                           // o sensor da um pulso para acionar a cortina
                //delay(1000);             
                //digitalWrite(relpulso, LOW); 
              }

      futureLDR01 = millis() + TIME_PAUSE_LDR01_1;
     }

}


void monitoringLDR_AUT_II() {

  if(timeIsOver(futureLDR01)){
    
              
              vlrsensLDR01 = analogRead(LDR01);                         // Faz a leitura do pino analógico LDR e armazena o valor na variavel valorsensor
              
              Serial.print("LDR : " );                                  // Escreve a palavra LDR no monitor serial
              Serial.println(vlrsensLDR01);                             // Mostra o valor no monitor serial
                Mb.R[45]=(vlrsensLDR01);                                // Informa para o Modbus a luminosidade do ambiente
            
              if (vlrsensLDR01 > Mb.R[46]) {                            // Se o valor do sensor for maior que a informação do modbus 46 no setup
                digitalWrite(relpulso, LOW);                            // deixa a luz/relé desligado
                } 

              else if(vlrsensLDR01 <= Mb.R[46]){                        // Se o valor do sensor for menor ou igual a informação do modbus 46 no setup
                if (digitalRead(statuscort01) == HIGH)                         // e se o sensor de fim de curso da cortina estiver aberto, faça:
                  { 
                        digitalWrite(relpulso, HIGH);                   // o sensor da um pulso para acionar a cortina
                        delay(1000);             
                        digitalWrite(relpulso, LOW); 
                        
                          }
                      else {                                            // Senão:
                     Serial.println("PORTA FECHADA: ");                 // Não faz nada e envia a informação que a Cortina está fechada
                       }
                
              }

      futureLDR01 = millis() + TIME_PAUSE_LDR01_1;
     }

}