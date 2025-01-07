#define pinBotao 39  //tecla interruptor

#define pinLED0 8   
#define pinLED1 12
#define pinLED2 11
//#define pinLED3 9
#define pinLED9 13  //pino de led indicador

unsigned long tempoInicio = 0;
unsigned long tempoBotao = 0;

bool estadoBotao;
bool estadoBotaoAnt;

void prepareInterruptorMax() {
  pinMode(pinBotao, INPUT_PULLUP);
  pinMode(pinLED0, OUTPUT);
  pinMode(pinLED1, OUTPUT);
  pinMode(pinLED2, OUTPUT);
  pinMode(pinLED9, OUTPUT);
  

}

void monitoringInterruptorMax() {
  estadoBotao = !digitalRead(pinBotao);

  //Ao apertar o botão
  if (estadoBotao && !estadoBotaoAnt) {
    if (tempoInicio == 0) {
      tempoInicio = millis();

      digitalWrite(pinLED0, LOW);
      digitalWrite(pinLED1, LOW);
      digitalWrite(pinLED2, LOW);
    }
  }  

  //Ao soltar o botão
  if (tempoInicio > 200) {  //Filtro Debounce
    if (!estadoBotao && estadoBotaoAnt) {
      tempoBotao = millis() - tempoInicio;
      tempoInicio = 0;  
      digitalWrite(pinLED9, LOW);
    }
  }

  //Retorno
  if (tempoInicio > 0) {
     digitalWrite(pinLED9, bitRead(millis(),8)); 
  }

  //Comando 1
  if ((tempoBotao > 0) && (tempoBotao <= 1000)) {
     tempoBotao = 0;
     Serial.println("Comando 1 executado");

     digitalWrite(pinLED0, HIGH);
     digitalWrite(pinLED1, LOW);
     digitalWrite(pinLED2, LOW);
  }

  //Comando 2
  if ((tempoBotao > 1000) && (tempoBotao <= 2000)) {
     tempoBotao = 0;
     Serial.println("Comando 2 executado");

     digitalWrite(pinLED0, LOW);
     digitalWrite(pinLED1, LOW);
     digitalWrite(pinLED2, LOW);
//     digitalWrite(pinLED3, LOW);
  }

  //Comando 3
  if ((tempoBotao > 2000) && (tempoBotao <= 3000)) {
     tempoBotao = 0;
     Serial.println("Comando 2 executado");

     digitalWrite(pinLED0, LOW);
     digitalWrite(pinLED1, HIGH);
     digitalWrite(pinLED2, LOW);
  }

  //Comando 3
  if (tempoBotao > 3000) {
     tempoBotao = 0;
     Serial.println("Comando 3 executado");
  
    digitalWrite(pinLED0, HIGH);
    digitalWrite(pinLED1, HIGH);
    digitalWrite(pinLED2, HIGH);
  }

  estadoBotaoAnt = estadoBotao;
  delay(20);
}
