// *** PLACA LHIR - Coontrole Infra Vermelho de equipamentos com sensor de movimento Ar Condicionado***
//************** VERSÃO 1.0 *********************
// ********* PRODUÇÃO - ATUALIZAÇÃO 23/04/18 **************

// --------------LIGAÇÕES-------------------
// Emissor IR:              GPIO D2        |
// Sensor de Moviemnto:     GPIO D5        |
//------------------------------------------

#include <ESP8266WiFi.h>
#include <SPI.h>
#include "ModbusTCP.h"
#include <IRremoteESP8266.h>
#include <IRsend.h>

// Register map for this example
#define S1_FloatConstant 40001 

IRsend irsend(04); //GPIO D2 - Emissor IR

ModbusTCP m;
unsigned int cmdIR;

//======================   S E T U P    ====================================

void setup(void)
{
  Serial.begin(115200);
  Serial.println(); Serial.println("Ola, seja bem vindo!");
  delay(1000); 
  Serial.println("Conectando a rede wifi...");

//Conexão Rede Internet
  m.begin("LiveHomeAutomacao", "Patricia26#");      //""      LiveHomeAutomacao", "LHPatricia# / LiveHomeAutomacao-DiFratelli, df12345678   / Marcela: "Autom402", "LH242604#"
  irsend.begin();
//fim conexão rede internet

while (WiFi.status() != WL_CONNECTED) { 
 delay(500); 
 Serial.print("."); 
}

  Serial.println();                                                 //Imprime uma linha em branco
  Serial.println("Conectado ao Roteador");             // Imprime na Serial
  Serial.println();
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());                                   //Imprime o Endereço IP Local do ESP8266
  delay(1000);                                                      // aguarda 1 segundo
  Serial.println();
  Serial.println("Inicializando o fvm leaning, obtendo endereço mac da placa... ");
  Serial.print("Mac Address AP: "); 
  Serial.println(WiFi.softAPmacAddress());
  Serial.print("Mac Address STA: "); 
  Serial.println(WiFi.macAddress());

}


//=======================   L O O P   ======================================

void loop(void)
{//inicio LOOP
  
  //Verifica Conexção com a Internet
  while (WiFi.status() != WL_CONNECTED) { 
  delay(500); 
  ESP.restart();
  }
  
  // Process MODBUS requests on every scan
  m.run();
  delay(10);

  //ATIVAÇÃO DOS MODULOS
     monitoringTV_SAM();
     monitoringAR_LG();
     monitoringTVLG();

 {
    switch (m.getU32(40001))
      {//inicio switch




       }//fim switch
   }
}//fim do loop
