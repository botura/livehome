

          int Sens_MQ2               = 32;       //PINO DIGITAL UTILIZADO PELO SENSOR
          int RELE_BUZZER_GAS        = 34;       //PINO DIGITAL UTILIZADO PELO RELÉ DA SIRENE
          int RELE_SOLENOIDE          = 3;       //PINO DIGITAL UTILIZADO PELA SOLENOIDE VAZAMENTO



//void setup()
void prepareGas()
    {

  //Ao Reiniciar o sistema aciona automaticamente os relés:
        digitalWrite(RELE_SOLENOIDE, LOW); //LUZ HOME THEATER BRANCA

    //SENSOR VAZAMENTO DE GÁS
          pinMode(Sens_MQ2, INPUT);             //DEFINE O PINO COMO ENTRADA
          pinMode(RELE_BUZZER_GAS, OUTPUT);     //DEFINE O PINO COMO SAÍDA
          pinMode(RELE_SOLENOIDE, OUTPUT);      //DEFINE O PINO COMO SAIDA
}


//void loop()
void monitoringGas()
    {

    if(digitalRead(Sens_MQ2) == HIGH){                    //SE A LEITURA DO PINO FOR NEGATIVA
             digitalWrite(RELE_BUZZER_GAS, HIGH);        //ACIONA O RELÉ DO ALARME
             digitalWrite(RELE_SOLENOIDE, LOW);         //ACIONA A SOLENOIDE SE TIVER VAZAMENTO
             Mb.R[6]=digitalRead(RELE_SOLENOIDE);        //status do Relé
             }
    else{                                                //SENÃO,
             digitalWrite(RELE_BUZZER_GAS, LOW);         //DESLIGA O RELÉ DO ALARME
             digitalWrite(RELE_SOLENOIDE, HIGH);          //DESLIGA O RELÉ DA SOLENOIDE
             Mb.R[6]=digitalRead(RELE_SOLENOIDE);        //status do Relé
             }
}
