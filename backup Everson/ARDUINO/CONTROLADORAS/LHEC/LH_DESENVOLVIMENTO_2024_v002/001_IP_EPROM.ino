//IDENTIFICAÇÃO DADOS MEMORIA EEPROM
int endereco1 = 0;
int endereco2 = 1;


//Numero a ser armazenado
int ip1 = 11;
int ip2 = 216; //endereço ip padrão


//DADOS CONEXÃO ETHERNET/INTERNET

// INICIO: Variaveis usadas para ethernet
// CONFIGURAÇÃO MAC
uint8_t mac[] = { 0x0A, 0x0A, 0x0A, 0x0A, 0x0B, 0x0B };
                //0x01, 0x23, 0x45, 0x67, 0x89, 0xAB
                //0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A

//CONFIGURAÇÃO IP
uint8_t ip[] = { 192, 168, EEPROM.read(endereco1), EEPROM.read(endereco2) }; //EEPROM.read(endrede02)
uint8_t subnet[] = { 255, 255, 255, 0 };
uint8_t gateway[] = { 192, 168, EEPROM.read(endereco1), 1 };
uint8_t dns_server[] = { 192, 168, EEPROM.read(endereco1), 1 };


// FIM: Variaveis usadas para ethernet
//------------------------------------------------------------



void prepareIPEPROM()
{

    //Grava a primeira parte do numero em endereco1
     EEPROM.write(0, ip1);
     EEPROM.write(1, ip2);

     //Serial.print(" EEPROM Endereço 01 :");
     //Serial.println(EEPROM.read(endereco1));
     //Serial.print(" EEPROM Endereço 02 :");
     //Serial.println(EEPROM.read(endereco2));
     //Serial.println(" FIM EEPROM ... ");

     Mb.R[18] = EEPROM.read(endereco2);
     Mb.R[19] = EEPROM.read(endereco1);




}

void monitoringIPEquip() 
{

// Verifica o valor da 1a variavel modbus
switch (Mb.R[0])

    {//inicio switch

            case 9996: //
                    Serial.print("Gravando dados na EEPROM :");

                   EEPROM.write(endereco2, Mb.R[18]);
                    delay(2000);
                    Serial.println(EEPROM.read(endereco2));
                    break;

            case 9997: //
                    Serial.print("Gravando dados na EEPROM :");
                    EEPROM.write(endereco1, Mb.R[19]);
                    delay(2000);
                    Serial.println(EEPROM.read(endereco1));
                    break;

//            case 9998: //
//                    if (digitalRead(botaoreset)==0){ //zerar a memoria eeprom
//                        for (int i = 0 ; i < EEPROM.length() ; i++) {
//                      EEPROM.write(i, 0);
//                      }
//                     }
//                    break;                    

    } // fim switch
} // fim do loop
