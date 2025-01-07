 /* Código Fonte */
 
int pinSensor01 = A7;                 //Pino Sensor
int pinSensor02 = A8;                 //Pino Sensor
int pinSensor03 = A9;                 //Pino Sensor
int pinSensor04 = A10;                 //Pino Sensor

//int Rele = 30;                    //Pino Relé
int buzzer = 8;                     //Pino Buzzer
int var = 0;
int ValDesarm = 30;                 //Variável para selecionar a quantidade de Gás/Fumaça detectada
int valorgas01 = 0;
int valorgas02 = 0;
int valorgas03 = 0;
int valorgas04 = 0;


//Definições para a leitura do sensor - Função Time
  unsigned long futureTemp03 = {0};
  #define TIME_PAUSE_GAS    2000                                //900000 A cada 15 minutos o sistema fará leitura da temperatura


void prepareGas()
{

         Mb.R[46] = 30;

  //Serial.begin(57600); //Inicia porta Serial em 9600 baud
 //pinMode (Rele, OUTPUT);
 pinMode(buzzer, OUTPUT);
 Serial.println("www.usinainfo.com.br");
}
 
void monitoringGas01()
{//INICIO LOOP
  if(timeIsOver(futureTemp03)){//INICIO TIME

          valorgas01 = analogRead(pinSensor01);               //Faz a leitura da entrada do sensor
          valorgas01 = map(valorgas01, 0, 1023, 0, 100);         //Faz a conversão da variável para porcentagem
          Serial.println(valorgas01);                       //Escreve o valor na porta Serial
          Mb.R[47]=(valorgas01); 
          if (valorgas01>=Mb.R[46]){                       //Condição, se valor continuar maior que ValDesarm faça:
                  digitalWrite(RELE14, HIGH);                     
                  //digitalWrite(LEDblue, LOW);
                  //digitalWrite(LEDred, LOW);                    //Liga relé para solenóide
                  //digitalWrite(buzzer, HIGH);                  //Dispara alarme de vazamento ou possível incêndio
                  //Serial.println("Alarme disparado!!!");       //Apresenta mensagem na porta serial
                  //delay(1000);                                 //Tempo de disparo do alarme
                  //digitalWrite(buzzer, LOW);                   //Desliga o alarme
                  //delay(2000);                                 //Aguarda
          }else{
          digitalWrite(RELE14, LOW);                     //Caso contrário permaneça com o relé desligado
          }
          //delay(1000);
          futureTemp03 = millis() + TIME_PAUSE_GAS;
    }//FIM TIME
  }//FIM LOOP



  void monitoringGas02()
{//INICIO LOOP
  if(timeIsOver(futureTemp03)){//INICIO TIME

          valorgas02 = analogRead(pinSensor02);               //Faz a leitura da entrada do sensor
          valorgas02 = map(valorgas02, 0, 1023, 0, 100);         //Faz a conversão da variável para porcentagem
          Serial.println(valorgas02);                       //Escreve o valor na porta Serial
          Mb.R[48]=(valorgas02); 
          if (valorgas02>=Mb.R[46]){                       //Condição, se valor continuar maior que ValDesarm faça:
                  digitalWrite(RELE14, HIGH);                     
                  //digitalWrite(LEDblue, LOW);
                  //digitalWrite(LEDred, LOW);                    //Liga relé para solenóide
                  //digitalWrite(buzzer, HIGH);                  //Dispara alarme de vazamento ou possível incêndio
                  //Serial.println("Alarme disparado!!!");       //Apresenta mensagem na porta serial
                  //delay(1000);                                 //Tempo de disparo do alarme
                  //digitalWrite(buzzer, LOW);                   //Desliga o alarme
                  //delay(2000);                                 //Aguarda
          }else{
          digitalWrite(RELE14, LOW);                     //Caso contrário permaneça com o relé desligado
          }
          //delay(1000);
          futureTemp03 = millis() + TIME_PAUSE_GAS;
    }//FIM TIME
  }//FIM LOOP


  void monitoringGas03()
{//INICIO LOOP
  if(timeIsOver(futureTemp03)){//INICIO TIME

          valorgas03 = analogRead(pinSensor03);               //Faz a leitura da entrada do sensor
          valorgas03 = map(valorgas02, 0, 1023, 0, 100);         //Faz a conversão da variável para porcentagem
          Serial.println(valorgas03);                       //Escreve o valor na porta Serial
          Mb.R[49]=(valorgas03); 
          if (valorgas03>=Mb.R[46]){                       //Condição, se valor continuar maior que ValDesarm faça:
                  digitalWrite(RELE14, HIGH);                     
                  //digitalWrite(LEDblue, LOW);
                  //digitalWrite(LEDred, LOW);                    //Liga relé para solenóide
                  //digitalWrite(buzzer, HIGH);                  //Dispara alarme de vazamento ou possível incêndio
                  //Serial.println("Alarme disparado!!!");       //Apresenta mensagem na porta serial
                  //delay(1000);                                 //Tempo de disparo do alarme
                  //digitalWrite(buzzer, LOW);                   //Desliga o alarme
                  //delay(2000);                                 //Aguarda
          }else{
          digitalWrite(RELE14, LOW);                     //Caso contrário permaneça com o relé desligado
          }
          //delay(1000);
          futureTemp03 = millis() + TIME_PAUSE_GAS;
    }//FIM TIME
  }//FIM LOOP



  void monitoringGas04()
{//INICIO LOOP
  if(timeIsOver(futureTemp03)){//INICIO TIME

          valorgas04 = analogRead(pinSensor04);               //Faz a leitura da entrada do sensor
          valorgas04 = map(valorgas02, 0, 1023, 0, 100);         //Faz a conversão da variável para porcentagem
          Serial.println(valorgas04);                       //Escreve o valor na porta Serial
          Mb.R[50]=(valorgas04); 
          if (valorgas04>=Mb.R[46]){                       //Condição, se valor continuar maior que ValDesarm faça:
                  digitalWrite(RELE14, HIGH);                     
                  //digitalWrite(LEDblue, LOW);
                  //digitalWrite(LEDred, LOW);                    //Liga relé para solenóide
                  //digitalWrite(buzzer, HIGH);                  //Dispara alarme de vazamento ou possível incêndio
                  //Serial.println("Alarme disparado!!!");       //Apresenta mensagem na porta serial
                  //delay(1000);                                 //Tempo de disparo do alarme
                  //digitalWrite(buzzer, LOW);                   //Desliga o alarme
                  //delay(2000);                                 //Aguarda
          }else{
          digitalWrite(RELE14, LOW);                     //Caso contrário permaneça com o relé desligado
          }
          //delay(1000);
          futureTemp03 = millis() + TIME_PAUSE_GAS;
    }//FIM TIME
  }//FIM LOOP
