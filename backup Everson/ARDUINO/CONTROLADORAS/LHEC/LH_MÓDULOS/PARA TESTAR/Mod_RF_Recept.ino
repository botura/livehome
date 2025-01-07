//Programa: Circuito Receptor RF 433 MHz
//Autor: Arduino e Cia

#include <RCSwitch.h>

RCSwitch rfsense = RCSwitch();

void prepareRFRecept()
{
//  Serial.begin(9600);

  //Pino do led
  pinMode(6, OUTPUT);

  //Receptor na interrupção 0 (pino digital 2)
  rfsense.enableReceive(0);

  Serial.println("Receptor RF 433 MHz");
  Serial.println("Iniciando.....................");
//  delay(2000);
}

void monitoringRFRecept()
{
  if (rfsense.available())
  {
    //Verifica o valor recebido pelo receptor
    int valor = rfsense.getReceivedValue();

    //Caso receba o valor 1 liga o led, caso receba 2, desliga
    if (valor == 100110100101010000000001)
    {
      Serial.println("Liga o led");
      digitalWrite(6, HIGH);
    }
    else if (valor == 2)
    {
      Serial.println("Desliga o led");
      digitalWrite(6, LOW);
    }
    rfsense.resetAvailable();
  }
}
