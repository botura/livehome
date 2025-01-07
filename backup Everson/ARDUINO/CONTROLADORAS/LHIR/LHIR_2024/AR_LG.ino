void monitoringAR_LG()
{//inicio LOOP

switch (m.getU32(40001))
  {//inicio switch
//==============================================================================================
//-------------------------------------CONTROLES--------------------------------------------------
 //   Inicio Controle AR LG
           case 500: LGQUENTELIGA();    delay(500); // liga desliga
               Serial.println("Ligar Ar LG no Quente 27°,... comando 500");
               m.setU32(40001, 0x0);
               break;
           case 501: LGQUENTEDESLIGA();    delay(500); // liga desliga
               Serial.println("DESLIGA Ar LG no Quente,... comando 501");
               m.setU32(40001, 0x0);
               break;    
           case 502: LGLIGAFRIO();    delay(500); // liga desliga
               Serial.println("LIGA Ar LG no Frio 18°,... comando 502");
               m.setU32(40001, 0x0);
               break;    
           case 503: LGDESLIGAFRIO();    delay(500); // liga desliga
               Serial.println("DESLIGA Ar LG no Frio,... comando 503");
               m.setU32(40001, 0x0);
               break;                   
           case 504: LGTEMPMAIS();    delay(500); // liga desliga
               Serial.println("Ar LG AUMENTAR TEMPERATURA,... comando 504");
               m.setU32(40001, 0x0);
               break; 
           case 505: LGTEMPMENOS();    delay(500); // liga desliga
               Serial.println("Ar LG DIMINUIR TEMPERATURA,... comando 505");
               m.setU32(40001, 0x0);
               break;   

  /*         case 150: //Power: On, Mode: 0 (Cool), Temp: 18C, Fan: 4 (Maximum)
                irsend.sendLG2(0x8800347, 28);
                m.setU32(40001, 0x0);
                Serial.println("AR LG: ON | Cod. 150");
                break;
           case 151: //Power: On, Mode: 0 (Cool), Temp: 18C, Fan: 4 (Maximum)
                irsend.sendLG2(0x759AC733, 30);
                m.setU32(40001, 0x0);
                Serial.println("AR LG: ON | Cod. 150");
                break;
*/
  }//fim switch
}//fim do loop





void LGQUENTELIGA(){
 uint16_t LGQUENTELIGA[59] = {3400,9600, 650,1450, 650,400, 650,400, 700,400, 700,1450, 550,550, 650,400, 700,400, 700,400, 700,400, 650,450, 650,450, 650,400, 700,1450, 650,400, 700,400, 550,1550, 650,1450, 650,400, 700,400, 700,400, 700,1450, 650,450, 650,450, 650,400, 700,1450, 650,400, 700,400, 600};
 irsend.sendRaw(LGQUENTELIGA, 59, 30);
 }
void LGQUENTEDESLIGA(){
 uint16_t LGQUENTEDESLIGA[59] = {3400,9600, 650,1450, 650,400, 650,400, 700,400, 650,1450, 650,400, 650,400, 700,400, 650,1450, 650,1450, 650,400, 650,400, 700,400, 650,450, 650,400, 700,400, 700,400, 700,400, 600,500, 650,400, 700,400, 700,1450, 650,400, 600,1500, 650,400, 650,400, 700,400, 700,1400, 600};
 irsend.sendRaw(LGQUENTEDESLIGA, 59, 30);
 }
void LGLIGAFRIO(){
 uint16_t LGLIGAFRIO[59] = {3400,9600, 650,1450, 650,400, 650,400, 650,400, 650,1450, 600,450, 500,550, 550,550, 550,550, 550,550, 650,450, 600,450, 550,500, 600,500, 650,450, 650,450, 650,450, 600,500, 600,1500, 600,1500, 600,500, 650,1450, 550,500, 550,500, 600,500, 600,1500, 600,1500, 600,1500, 550};
 irsend.sendRaw(LGLIGAFRIO, 59, 30);
 }
void LGDESLIGAFRIO(){
 uint16_t LGDESLIGAFRIO[59] = {3300,9650, 650,1450, 650,450, 650,400, 650,400, 700,1450, 650,450, 650,450, 650,400, 700,1450, 650,1450, 550,500, 650,400, 700,400, 700,400, 700,400, 550,550, 650,400, 700,400, 700,400, 700,400, 600,500, 700,1400, 650,400, 650,1450, 650,400, 550,550, 650,400, 700,1450, 650};
 irsend.sendRaw(LGDESLIGAFRIO, 59, 30);
 }  
void LGTEMPMAIS(){
 uint16_t LGTEMPMAIS[59] = {3450,9650, 550,1550, 650,400, 700,400, 700,450, 700,1450, 650,400, 650,450, 650,400, 700,450, 700,450, 700,450, 650,450, 650,1450, 650,1450, 650,400, 700,400, 700,1450, 550,1550, 650,400, 700,1450, 650,400, 700,1450, 600,500, 650,450, 700,1450, 650,1450, 650,400, 700,1450, 650};
 irsend.sendRaw(LGTEMPMAIS, 59, 30);
 }
void LGTEMPMENOS(){
 uint16_t LGTEMPMENOS[59] = {3900,9150, 650,1450, 650,400, 700,400, 850,250, 700,1450, 550,550, 650,400, 700,400, 650,450, 700,450, 650,450, 650,450, 650,1450, 650,1450, 650,450, 650,450, 650,1500, 600,1450, 650,1450, 650,450, 700,450, 650,1500, 600,450, 650,400, 650,1450, 650,1450, 650,1450, 550,500, 650};
 irsend.sendRaw(LGTEMPMENOS, 59, 30);
 } 