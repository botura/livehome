/*******************************************************************************
* Primeiros Passos com a Bomba Peristaltica 
* Projeto Controlador de Nivel Automatico (v1.0)
* 
* Este codigo verifica a presenca de liquido com dois sensores de nivel sem contato.
* A bomba e acionada quando o sensor inferior esta na ausencia de liquido e e
* mantida assim ate que o sensor superior esteja na presenca de liquido.
* Um dos sensores deve ser posicionado no nivel minimo desejado do reservatorio e
* o segundo deve ser posicionado na parte superior, o mais proximo possivel do
* topo do reservatorio.
* 
* Copyright 2020 RoboCore.
* Escrito por Giovanni de Castro (16/10/2020).
* 
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version (<https://www.gnu.org/licenses/>).
*******************************************************************************/
// ORIGEM DO CODIGO: https://www.robocore.net/tutoriais/controle-nivel-arduino


//Declaracao dos pinos conectados aos sensores
const int SENSOR_SUPERIOR01 = 13; //Sensor superior no pino 13
const int SENSOR_INFERIOR01 = 12; //Sensor inferior no pino 12

//Declaracao do pino conectado ao rele
const int SOLENOIDECX01 = 2;

void setup() {

  //Configura os pinos conectados aos sensores como entradas do sistema
  pinMode(SENSOR_SUPERIOR01, INPUT);
  pinMode(SENSOR_INFERIOR01, INPUT);

  //Configura o pino conectado ao rele como uma saida do sistema
  pinMode(SOLENOIDECX01, OUTPUT);

  //Inicia o pino conectado ao rele com um nivel logico baixo
  digitalWrite(SOLENOIDECX01, LOW);

}

void loop() {

  //Realiza as leituras dos sensores e as armazena em duas variaveis
  int leitura_sensor_superior = digitalRead(SENSOR_SUPERIOR01);
  int leitura_sensor_inferior = digitalRead(SENSOR_INFERIOR01);

  //Verifica se o sensor inferior esta na ausencia de liquido
  if(leitura_sensor_inferior == HIGH){
    digitalWrite(SOLENOIDECX01, HIGH); //Se for verdadeiro, aciona o rele
  }

  //Verifica se o sensor superior esta na presenca de liquido
  if(leitura_sensor_superior == LOW){
    digitalWrite(SOLENOIDECX01, LOW); //Se for verdadeiro, desliga o rele
  }

  delay(100); //Aguarda 100 milissegundos para outra leitura

}
