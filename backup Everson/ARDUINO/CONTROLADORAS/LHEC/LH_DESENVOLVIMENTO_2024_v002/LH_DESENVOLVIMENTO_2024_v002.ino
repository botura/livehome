// **** PLACA LHEC - Controle Equipamentos ****
//************** VERSÃO 1.0 *********************
// ********* ATUALIZAÇÃO 04/04/21 **************

//------------------------------------------------

//------------------------------------------------
//BIBLIOTECAS
#include <SPI.h>
#include <Ethernet.h>
#include "Mudbus.h"
//#include <IRremote.h>
//IRsend irsend;
#include <OneWire.h>
#include <DallasTemperature.h>
#include <EEPROM.h>
Mudbus Mb;                                          // INICIO: Variaveis usadas na rotina modbus



//INDICAÇÃO DE PLACA LIGADA E CONFIGURADA
#define LED_ON         13 //






