//=====================================================================================
//                         S E T U P
//=====================================================================================
void setup()
{
//Porta Serial Arduino
        Serial.begin(57600);

//inicia configuração de rede
        prepareIPEPROM();

//Conectando a rede internet
        Serial.println("Conectando rede internet....... ");              // Mostra o numero do ip no monitor
        Serial.println("     ");

// Inicializa ethernet
        Ethernet.begin(mac, ip, dns_server, gateway, subnet);
    
    //Imprime informações IP
        Serial.print("Endereço IP: ");              // Mostra o numero do ip no monitor
        Serial.println(Ethernet.localIP());
        Serial.println("     ");

//Informa que o sistema esta pronto para operar
        Serial.println("Sistema iniciado...");
        
        //INDICAÇÃO PLACA LIGADA PRONTA
        pinMode(LED_ON, OUTPUT);
//        digitalWrite(LED_ON, HIGH);               //INDICAÇÃO DO LED UE A PLACA ESTA LIGADA
        

//SISTEMA

//   A
//   B
        prepareboanoite();

//   C
//   D
//   F
//        prepareFOTOCELULA();
//        prepareFitaLed();

//   G
//        prepareGas();

//   H
//   I
//        prepareInterruptor();
//        prepareInterruptorMax();
//        prepareI3PRO();


//   J
//   K
//   L
//        prepareLDR();
//        prepareLDR_Dim();

//   M
//        prepareMicrofone();

//   N
//   O
//   P
//        preparePIR();
//        preparePisoAquec();

//   Q
//   R
//        prepareReles();
//        prepareModRGB();
//        prepareReedSwitch();
//        prepareRFTransm();
//        prepareRFRecept();

//   S
//   T
//        prepareTemp();
//        prepareTempAgua();
//        prepare_tempAHT10();

//   U
//   V
    //VENEZIANAS
//        prepareVENEZIANAs();
//        prepareINTVENEZ();

//   X
//   Y
//   W
//   Z




     
}//FIM SETUP
//*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,



//=====================================================================================
//                         L O O P
//=====================================================================================
void loop()
{//Inicio Loop

//   A
//   B
        monitoring3PROboanoite();
        monitoringBN01();
        monitoringBN02();

//   C
//   D
//   F
//        monitoringFOTOCELULA_I();
//        monitoringFOTOCELULA_AUT();
//        monitoringModRGB();
//        monitoringFitaLed();

//   G
//   H
//   I
//        monitoringIPEquip();
//        monitoringIPRede();
//        monitoringInterruptor();
//        monitoringInterruptorMax();
//        monitoringI3PRO();

//   J
//   K
//   L
//        monitoringLDR();
//        monitoringLDR2();             // COMANDO SERÁ ATIVADO PELO CASE 2001
//        monitoringLDR_AUT();

//   M
//        monitoringMicrofone();

//   N
//   O
//   P
//        monitoringPisoAquec();

//   Q
//   R
//        monitoringReedSwitch01();    // COMANDO SERÁ ATIVADO PELO CASE 2003
//        monitoringReedSwitch02();
//        monitoringReedSwitch03();
//        monitoringReedSwitch04();
//        monitoringRFTransm();
//        monitoringRFRecept();

//   S
//   T
//        monitoringTempAgua();
//        monitoring_tempAHT10();

//   U
//   V
      //VENEZIANAS
//        monitoringI3PROVen();
//        monitoringINTVENEZ01();
//        monitoringINTVENEZ02();
//        monitoringINTVENEZ03();
//        monitoringINTVENEZ04();

//   X
//   Y
//   W
//   Z



       

  
// Executa comunicacao modbus
Mb.Run();

// Verifica o valor da 1a variavel modbus
switch (Mb.R[0])

    {//inicio switch


            case 9999: //SENSOR LUMINOSIDADE LDR
//                    voltaraoinicio();
                    break;
                    
/*            case 2001: //SENSOR LUMINOSIDADE LDR
                    monitoringLDR();
                    break;
/*
            case 2002: //SENSOR REED SWITCH 1
                    monitoringReedSwitch();
                    break;

            case 2003: //SENSOR REED SWITCH 2
                    monitoringReedSwitch02();
                    break;
*/
/*            case 2004: //SENSOR VAZAMENTO DE GAS
                    monitoringGas();
                    break;
*/        
/*            case 2006: //LDR AUTOMATICO
                    monitoringLDR_AUT_II();
                    //Serial.print("LDR AUTOMATICO LIGADO: ");
                    break;
*/
/*
            case 2005: //SENSOR PIR - PRESENÇA 1
                    monitoringPIR01();
                    break;          
                    
            case 20051: //SENSOR PIR - PRESENÇA 2 
                    monitoringPIR02();
                    break;  
*/                    
/*            case 2006: //SENSOR PIR - PRESENÇA 2 
                    monitoringLDR_Dim();
                    break;  
/*
    //inicio FITAS RGB
                
   
*/

    } // fim switch

} // fim loop
//*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,

//----------------------------------------------------------------------------------------------------------------



