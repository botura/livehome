//Ao detetectar movimento do sensor pir, o rele dispara piscando as luzes de um determinado ambiente

int leitura01 = 0;                      //Variável para armazenar a leitura do sensor
int leitura02 = 0;                      //Variável para armazenar a leitura do sensor
bool estadoSensor01 = false;            //Variável para armazenar o estado do sensor

 
void prepareboanoite(){
  
//  Serial.begin(57600);
  
  pinMode(RELE_BN01, OUTPUT); //DEFINE O PINO COMO SAÍDA
  pinMode(RELE_BN02, OUTPUT); //DEFINE O PINO COMO SAÍDA
//  pinMode(RELE_BN03, OUTPUT); //DEFINE O PINO COMO SAÍDA

  pinMode(pinoPIR01, INPUT); //DEFINE O PINO COMO ENTRADA
  pinMode(pinoPIR02, INPUT); //DEFINE O PINO COMO ENTRADA
//  pinMode(pinoPIR03, INPUT); //DEFINE O PINO COMO ENTRADA

}

void monitoringBN01()
{//INICIO LOOP

      //SENSOR DE MOVIMENTO 01 
              leitura01 = digitalRead(pinoPIR01);           //Realiza a leitura do sensor de presença
              if (leitura01 == HIGH) {                      //Se leitura for igual a HIGH, o movimento foi detectado
                digitalWrite(RELE_BN01, 0);               //Aciona o LED
                  Serial.println("Movimento detectado");  //Imprime a mensagem no monitor serial
                  Mb.R[21]=digitalRead(RELE_BN01); //status do Relé
              }
 }//FIM DO LOOP

void monitoringBN02()
{//INICIO LOOP

      //SENSOR DE MOVIMENTO 02 
              leitura02 = digitalRead(pinoPIR02);           //Realiza a leitura do sensor de presença
              if (leitura02 == HIGH) {                      //Se leitura for igual a HIGH, o movimento foi detectado
                digitalWrite(RELE_BN02, 0);               //Aciona o LED
                  Serial.println("Movimento detectado SENSOR 02");  //Imprime a mensagem no monitor serial
                  Mb.R[2]=digitalRead(RELE_BN01); //status do Relé
              }
 }//FIM DO LOOP




void monitoring3PROboanoite()
{//Inicio Loop


  // Executa comunicacao modbus
        Mb.Run();

  // Verifica o valor da 1a variavel modbus
        switch (Mb.R[0])
           {//inicio switch


            case 2001: //SENSOR LUMINOSIDADE LDR
                    //Serial.println("MOD BOA NOITE: ATIVADO");
                    monitoringBN01();
                    monitoringBN02();
                    //monitoringLDR();
                    break;



                //RELÉ BOA NOITE
                        case 20011: //RÉGUA ELETROS - INVERTE ESTADO RELÉ
                                digitalWrite(RELE_BN01, 1);
                                Mb.R[21]=digitalRead(RELE_BN01); //status do Relé
                                Mb.R[0] = 0;    
                                break;
                        case 20012: //RÉGUA ELETROS - LIGA
                                digitalWrite(RELE_BN02, 1);
                                Mb.R[21]=digitalRead(RELE_BN01); //status do Relé
                                Mb.R[0] = 0;    
                                break;


// ---------------------------------   fim RELÉS   ---------------------------------------------
} // fim switch
} // fim loop
