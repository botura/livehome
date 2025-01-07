
#define botao 23
#define botaoreset 22
#define led 13

int contador = 0;


void prepareConsGas() {
Serial.begin(57600);

pinMode(botao, INPUT_PULLUP);
pinMode(botaoreset, INPUT_PULLUP);
pinMode(led, OUTPUT);

  Serial.print("EEPROM: ");      // imprime 
  Serial.println(EEPROM[1]);
  Mb.R[21]=EEPROM[1]; //status do Relé

if(EEPROM[0] != 9){
  EEPROM[0] = 9;
  EEPROM[1] = contador;
} else {
  contador = EEPROM[1];
}

}

void monitoringConsGas () { // contador de pulso
  if (!digitalRead(botao)){
  contador++;
  EEPROM[1] = contador;
  Serial.println(contador);
  delay(1000);
}
 if (digitalRead(botaoreset)==0){ //zerar a memoria eeprom
      for (int i = 0 ; i < EEPROM.length() ; i++) {
    EEPROM.write(i, 0);
  }
}
Mb.R[21]=EEPROM[1]; //status do Relé
}