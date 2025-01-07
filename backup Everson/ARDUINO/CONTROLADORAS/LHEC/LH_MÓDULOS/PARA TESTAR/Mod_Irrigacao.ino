
// Código de Funcionamento para Sistema de Monitoramento e Irrigação com Arduino
 
#define sensIrrig01 A0                                // Define o pino A0 como "pinoAnalog"
#define sensIrrig02 A0                                // Define o pino A0 como "pinoAnalog"
#define sensIrrig03 A0                                // Define o pino A0 como "pinoAnalog"
#define sensIrrig04 A0                                // Define o pino A0 como "pinoAnalog"
#define pinoRele01 8                                   // Define o pino 8 como "pinoRele"
#define pinoRele02 8                                   // Define o pino 8 como "pinoRele"
#define pinoRele03 8                                   // Define o pino 8 como "pinoRele"
#define pinoRele04 8                                   // Define o pino 8 como "pinoRele"
int ValAnalogIn01;                                     // Introduz o valor analógico ao código
int ValAnalogIn02;                                     // Introduz o valor analógico ao código
int ValAnalogIn03;                                     // Introduz o valor analógico ao código
int ValAnalogIn04;                                     // Introduz o valor analógico ao código
 

//Definições para a leitura do sensor - Função Time
  unsigned long futureTemp04 = {0};
  #define TIME_PAUSE_IRRIG    2000                                //900000 A cada 15 minutos o sistema fará leitura da temperatura




void prepareIrrigacao() {

     Mb.R[51] = 45;                                  // valor da porcentagem inicial de leitura do sensor

     pinMode(pinoRele01, OUTPUT);                      // Declara o pinoRele como Saída
     pinMode(pinoRele02, OUTPUT);                      // Declara o pinoRele como Saída
     pinMode(pinoRele03, OUTPUT);                      // Declara o pinoRele como Saída
     pinMode(pinoRele04, OUTPUT);                      // Declara o pinoRele como Saída

}
 



void monitoringIrrig01() { // inicio do loop

       if(timeIsOver(futureTemp04)){//INICIO TIME

              ValAnalogIn01 = analogRead(sensIrrig01);               // Relaciona o valor analógico com o recebido do sensor
              int Porcento01 = map(ValAnalogIn01, 1023, 0, 0, 100);    // Relaciona o valor analógico à porcentagem
              
              Serial.print(Porcento01);                              // Imprime o valor em Porcento no monitor Serial
              Serial.println("%");                                 // Imprime o símbolo junto ao valor encontrado
              Mb.R[52]=(Porcento01);                                 // Informa % do sensor para o modbus

              if (Porcento01 <= Mb.R[51]) {                                // Se a porcentagem for menor ou igual à
              Serial.println("Irrigando a planta ...");            // Imprime a frase no monitor serial
              digitalWrite(pinoRele01, HIGH);                        // Altera o estado do pinoRele para nível Alto
              }
              
              else { // Se não ...
              Serial.println("Planta Irrigada ...");               // Imprime a frase no monitor serial
              digitalWrite(pinoRele01, LOW);                         // Altera o estado do pinoRele para nível Baixo
              }
//              delay (1000);                                        // Estabelece o tempo de 1s para reinicializar a leitura
        
        futureTemp04 = millis() + TIME_PAUSE_IRRIG;
    }//FIM TIME

} // fim do loop



void monitoringIrrig02() { // inicio do loop

       if(timeIsOver(futureTemp04)){//INICIO TIME

              ValAnalogIn02 = analogRead(sensIrrig02);               // Relaciona o valor analógico com o recebido do sensor
              int Porcento02 = map(ValAnalogIn01, 1023, 0, 0, 100);    // Relaciona o valor analógico à porcentagem
              
              Serial.print(Porcento02);                              // Imprime o valor em Porcento no monitor Serial
              Serial.println("%");                                 // Imprime o símbolo junto ao valor encontrado
              Mb.R[53]=(Porcento02);                                 // Informa % do sensor para o modbus

              if (Porcento02 <= Mb.R[51]) {                                // Se a porcentagem for menor ou igual à
              Serial.println("Irrigando a planta ...");            // Imprime a frase no monitor serial
              digitalWrite(pinoRele02, HIGH);                        // Altera o estado do pinoRele para nível Alto
              }
              
              else { // Se não ...
              Serial.println("Planta Irrigada ...");               // Imprime a frase no monitor serial
              digitalWrite(pinoRele02, LOW);                         // Altera o estado do pinoRele para nível Baixo
              }
//              delay (1000);                                        // Estabelece o tempo de 1s para reinicializar a leitura
        
        futureTemp04 = millis() + TIME_PAUSE_IRRIG;
    }//FIM TIME

} // fim do loop


void monitoringIrrig03() { // inicio do loop

       if(timeIsOver(futureTemp04)){//INICIO TIME

              ValAnalogIn03 = analogRead(sensIrrig03);               // Relaciona o valor analógico com o recebido do sensor
              int Porcento03 = map(ValAnalogIn01, 1023, 0, 0, 100);    // Relaciona o valor analógico à porcentagem
              
              Serial.print(Porcento03);                              // Imprime o valor em Porcento no monitor Serial
              Serial.println("%");                                 // Imprime o símbolo junto ao valor encontrado
              Mb.R[54]=(Porcento03);                                 // Informa % do sensor para o modbus

              if (Porcento03 <= Mb.R[51]) {                                // Se a porcentagem for menor ou igual à
              Serial.println("Irrigando a planta ...");            // Imprime a frase no monitor serial
              digitalWrite(pinoRele03, HIGH);                        // Altera o estado do pinoRele para nível Alto
              }
              
              else { // Se não ...
              Serial.println("Planta Irrigada ...");               // Imprime a frase no monitor serial
              digitalWrite(pinoRele03, LOW);                         // Altera o estado do pinoRele para nível Baixo
              }
//              delay (1000);                                        // Estabelece o tempo de 1s para reinicializar a leitura
        
        futureTemp04 = millis() + TIME_PAUSE_IRRIG;
    }//FIM TIME

} // fim do loop


void monitoringIrrig04() { // inicio do loop

       if(timeIsOver(futureTemp04)){//INICIO TIME

              ValAnalogIn04 = analogRead(sensIrrig04);               // Relaciona o valor analógico com o recebido do sensor
              int Porcento04 = map(ValAnalogIn01, 1023, 0, 0, 100);    // Relaciona o valor analógico à porcentagem
              
              Serial.print(Porcento04);                              // Imprime o valor em Porcento no monitor Serial
              Serial.println("%");                                 // Imprime o símbolo junto ao valor encontrado
              Mb.R[55]=(Porcento04);                                 // Informa % do sensor para o modbus

              if (Porcento04 <= Mb.R[51]) {                                // Se a porcentagem for menor ou igual à
              Serial.println("Irrigando a planta ...");            // Imprime a frase no monitor serial
              digitalWrite(pinoRele04, HIGH);                        // Altera o estado do pinoRele para nível Alto
              }
              
              else { // Se não ...
              Serial.println("Planta Irrigada ...");               // Imprime a frase no monitor serial
              digitalWrite(pinoRele04, LOW);                         // Altera o estado do pinoRele para nível Baixo
              }
//              delay (1000);                                        // Estabelece o tempo de 1s para reinicializar a leitura
        
        futureTemp04 = millis() + TIME_PAUSE_IRRIG;
    }//FIM TIME

} // fim do loop
