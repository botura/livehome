// Programa : Sensor de presenca com modulo PIR
// Autor : Arduino e Cia

int pinoledverm = 22; //Pino ligado ao led vermelho
//int pinoledazul = 13; //Pino ligado ao led azul
int pinopir = 30;  //Pino ligado ao sensor PIR
int acionamento;  //Variavel para guardar valor do sensor

void preparePIR()
{
  pinMode(pinoledverm, OUTPUT); //Define pino como saida
//  pinMode(pinoledazul, OUTPUT); //Define pino como saida
  pinMode(pinopir, INPUT);   //Define pino sensor como entrada

}

void monitoringTestePIR()
{
           if(digitalRead(pinopir) == LOW){ //SE A LEITURA DO PINO FOR IGUAL A HIGH, FAZ
           Serial.println("Alarme Disparado");
           digitalWrite(pinoledverm, HIGH); //ACENDE O LED
           Mb.R[5]=digitalRead(pinoledverm); //status do Relé
}
}

/*
 * TESTE DO SENSOR PIR
 */

/*
int ledPin = 22;                          //Pino do LED
int sensorPin = 30;                       //Pino do sensor de presença
int leitura = 0;                          //Variável para armazenar a leitura do sensor
bool estadoSensor = false;                //Variável para armazenar o estado do sensor


void preparePIR() {
//  Serial.begin(57600);                    //Inicializa a comunicação serial
  pinMode(ledPin, OUTPUT);                //Define ledPin como saída
  pinMode(sensorPin, INPUT);              //Define sensorPin como entrada
}


void monitoringTestePIR() {
  leitura = digitalRead(sensorPin);               //Realiza a leitura do sensor de presença
  if (leitura == HIGH) {                          //Se leitura for igual a HIGH, o movimento foi detectado
    digitalWrite(ledPin, HIGH);                   //Aciona o LED
    if (estadoSensor == false) {                  //Compara o valor de estado do LED
      Serial.println("Movimento detectado");      //Imprime a mensagem no monitor serial
      estadoSensor = true;                        //Altera o valor de estadoSensor para HIGH
    }
    delay(5000);                                    //Tempo de LED acionado
  } else {                                          //Se leitura for igual a LOW, não houve movimento detectado
    digitalWrite(ledPin, LOW);                      //Desliga o LED
    if (estadoSensor == true) {                     //Compara o valor de estado do LED
      Serial.println("Sem movimento");              //Imprime a mensagem no monitor serial
      estadoSensor = false;                         //Altera o valor de estadoSensor para HIGH
    }
  }
}
*/



/* 
      
    #define pinoPIR                   38              // Define o pino 8 como "pinoPIR"
    #define pinoRele                  23              // Define o pino 10 como "pinoRele"

     int estadosensorPIR01 ;

//Definições para a leitura do sensor - Função Time
  unsigned long futurePIR01 = {0};
  #define TIME_PAUSE_PIR01_1    10000                                  //900000 A cada 15 minutos o sistema fará leitura da temperatura





void preparePIR()
//void setup() 
            {

//              Serial.begin(9600);                               // Declara o BaundRate em 9600
//              Serial.println("www.usinainfo.com.br");           // Imprime a frase no monitor serial
              pinMode(pinoPIR, INPUT);                          // Declara o pinoPIR como Entrada
              pinMode(pinoRele, OUTPUT);                        // Declara o pinoRele como Saída

            }



void monitoringPIR01()
//void loop() 
            {
                  estadosensorPIR01 = digitalRead(pinoPIR);
                  
              if (digitalRead(pinoPIR) == LOW) {                // Se o Sensor PIR Estiver em nível baixo
                  Serial.print("Estado do Sensor PIR: ");
                  Serial.println(estadosensorPIR01);
                  //digitalWrite (pinoRele, LOW);                   // Módulo Relé permanece desligado
                }

              if (digitalRead(pinoPIR) == HIGH) {               // Se o Sensor PIR estiver em nível Alto
                  digitalWrite (pinoRele, HIGH);                    // Liga o Relé
                  Mb.R[14]=digitalRead(pinoRele); //status do Relé
                  Mb.R[0] = 0;    
//                  Serial.println("Luz Ligada");                     // Imprime a mensagem no monitor serial
                  //delay (10000);                                  // Aguarda 10 segundo
                }
            }


void monitoringPIR02()
            {

              if (digitalRead(pinoPIR) == LOW) {                // Se o Sensor PIR Estiver em nível baixo
                  digitalWrite (pinoRele, LOW);                   // Módulo Relé permanece desligado
                }

              if (digitalRead(pinoPIR) == HIGH) {               // Se o Sensor PIR estiver em nível Alto
                  digitalWrite (pinoRele, HIGH);                    // Liga o Relé
                  Mb.R[14]=digitalRead(pinoRele); //status do Relé
                  Mb.R[0] = 0; 
                  Serial.println("Luz Ligada");                     // Imprime a mensagem no monitor serial
                  delay (10000);                                  // Aguarda 10 segundo
                }
            }


void monitoringPIR03()
            {

              if (digitalRead(pinoPIR) == LOW) {                // Se o Sensor PIR Estiver em nível baixo
                  digitalWrite (pinoRele, HIGH);                   // Módulo Relé permanece desligado
                }

              else if (digitalRead(pinoPIR) == HIGH) {               // Se o Sensor PIR estiver em nível Alto
                  digitalWrite (pinoRele, LOW);                    // Liga o Relé
                  Mb.R[14]=digitalRead(pinoRele); //status do Relé
                  Mb.R[0] = 0; 
                  Serial.println("Luz Ligada");                     // Imprime a mensagem no monitor serial
              
              if(timeIsOver(futurePIR01)){
                          if (digitalRead(pinoPIR) == HIGH) {               // Se o Sensor PIR estiver em nível Alto
                              digitalWrite (pinoRele, LOW);                    // Liga o Relé
                              Mb.R[14]=digitalRead(pinoRele); //status do Relé
                              Mb.R[0] = 0; 
                              Serial.println("Luz Ligada");                     // Imprime a mensagem no monitor serial
             }
                  futureLDR01 = millis() + TIME_PAUSE_PIR01_1;
           }
          }
         }       


              */
