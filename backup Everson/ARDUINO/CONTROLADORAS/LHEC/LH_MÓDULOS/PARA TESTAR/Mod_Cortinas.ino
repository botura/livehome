
//RELES CORTINAS
        #define CORT01ABRE         23 // 
        #define CORT01FECHA        22 //
        #define CORT02ABRE         25 //
        #define CORT02FECHA        24 //
        #define CORT03ABRE         27 //
        #define CORT03FECHA        26 //


//SENSOR - ESTADO DA CORTINA
        int statusCort01 = 29; //PINO DIGITAL UTILIZADO PELO SENSOR
        int statusCort02 = 28; //PINO DIGITAL UTILIZADO PELO SENSOR
        int statusCort03 = 31;  //PINO DIGITAL UTILIZADO PELO SENSOR


void prepareCORTINAS()
{
  //Ao Reiniciar o sistema aciona automaticamente os relés:
        digitalWrite(CORT01ABRE, LOW);  // 
        digitalWrite(CORT01FECHA, LOW);  //
        digitalWrite(CORT02ABRE, HIGH); //
        digitalWrite(CORT02FECHA, HIGH); //
        digitalWrite(CORT03ABRE, LOW);  //
        digitalWrite(CORT03FECHA, LOW);  //

 //RELES
        pinMode(CORT01ABRE, OUTPUT);//RÉGUA ELETROS 
        pinMode(CORT01FECHA, OUTPUT);
        pinMode(CORT02ABRE, OUTPUT);
        pinMode(CORT02FECHA, OUTPUT);
        pinMode(CORT03ABRE, OUTPUT);
        pinMode(CORT03FECHA, OUTPUT);

 //SENSORES STATUS
       pinMode(statusCort01, INPUT); //DEFINE O PINO COMO ENTRADA
       pinMode(statusCort02, INPUT); //DEFINE O PINO COMO ENTRADA        
       pinMode(statusCort03, INPUT); //DEFINE O PINO COMO ENTRADA     
}//FIM SETUP
//*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,





void monitoringCORTINAS()
{//Inicio Loop


  // Executa comunicacao modbus
        Mb.Run();

  // Verifica o valor da 1a variavel modbus
        switch (Mb.R[0])
           {//inicio switch


                //CORTINA 01 - ABRE
                        case 8111: //RÉGUA CORTINA 01 ABRE - LIGA RELÉ
                                digitalWrite(CORT01ABRE, 1);
                                Mb.R[0] = 0;    
                                break;
                        case 8001: //RÉGUA CORTINA 01 ABRE - DESLIGA RELÉ
                                digitalWrite(CORT01ABRE, 0);
                                Mb.R[0] = 0;    
                                break;

                //CORTINA 01 - FECHA
                        case 8112: //RÉGUA CORTINA 01 FECHA - LIGA RELÉ
                                digitalWrite(CORT01FECHA, 1);
                                Mb.R[0] = 0;    
                                break;
                        case 8002: //RÉGUA CORTINA 01 FECHA - DESLIGA RELÉ
                                digitalWrite(CORT01FECHA, 0);
                                Mb.R[0] = 0;    
                                break;
//------------------------------------------------------------------------------------
                //CORTINA 02 - ABRE
                        case 8113: //RÉGUA CORTINA 02 ABRE - LIGA RELÉ
                                digitalWrite(CORT02ABRE, 1);
                                Mb.R[0] = 0;    
                                break;
                        case 8003: //RÉGUA CORTINA 02 ABRE - DESLIGA RELÉ
                                digitalWrite(CORT02ABRE, 0);
                                Mb.R[0] = 0;    
                                break;

                //CORTINA 02 - FECHA
                        case 8114: //RÉGUA CORTINA 02 FECHA - LIGA RELÉ
                                digitalWrite(CORT02FECHA, 1);
                                Mb.R[0] = 0;    
                                break;
                        case 8004: //RÉGUA CORTINA 02 FECHA - DESLIGA RELÉ
                                digitalWrite(CORT02FECHA, 0);
                                Mb.R[0] = 0;    
                                break;
//--------------------------------------------------------------------------------------
                //CORTINA 03 - ABRE
                        case 8115: //RÉGUA CORTINA 03 ABRE - LIGA RELÉ
                                  digitalWrite(CORT03ABRE, 1);
                                  delay(1000);
                                  digitalWrite(CORT03ABRE, 0);
                                  Mb.R[0] = 0;    
                                  break;


                //CORTINA 03 - FECHA
                        case 8116: //RÉGUA CORTINA 03 FECHA - LIGA RELÉ
                                digitalWrite(CORT03FECHA, 1);
                                delay(1000);
                                digitalWrite(CORT03FECHA, 0);
                                Mb.R[0] = 0;    
                                break;


// ---------------------------------   fim RELÉS   ---------------------------------------------
} // fim switch



} // fim loop



void monitoringStatusCort(){

            digitalRead(statusCort01);                  //FAZ A LEITURA DO SENSOR
                Mb.R[20]=(statusCort01);                   //status do sensor
                  Serial.print("O estado da cortina 01 é: ");
                  Serial.println(statusCort01); // Mostra na serial a temperatura do sensor
          
            digitalRead(statusCort02);                  //FAZ A LEITURA DO SENSOR
                Mb.R[21]=(statusCort02);                   //status do sensor
                  Serial.print("O estado da cortina 02 é: ");
                  Serial.println(statusCort02); // Mostra na serial a temperatura do sensor
            
            digitalRead(statusCort03);                  //FAZ A LEITURA DO SENSOR
                Mb.R[22]=(statusCort03);                   //status do sensor
                  Serial.print("O estado da cortina 03 é: ");
                  Serial.println(statusCort03); // Mostra na serial a temperatura do sensor
}
