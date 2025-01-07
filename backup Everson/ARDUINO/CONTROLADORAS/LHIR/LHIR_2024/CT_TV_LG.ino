




void monitoringTVLG()
{//inicio LOOP
  
switch (m.getU32(40001))
  {//inicio switch
//==============================================================================================
//-------------------------------------CONTROLES--------------------------------------------------


//Controles TV LG
           case 101: //Liga Desliga ---------------
                irsend.sendNEC(0x20DF10EF, 32);
                m.setU32(40001, 0x0);
                break;
                
           case 102: //imput -------------------
                irsend.sendNEC(0x20DFD02F, 32); 
                m.setU32(40001, 0x0);
                break;
                
           case 103: //volume +
                irsend.sendNEC(0x20DF40BF, 32); 
                m.setU32(40001, 0x0);
                Serial.println("TV LG: VOL + | Cod. 103");
                break;
                
           case 104: //volume - 
                irsend.sendNEC(0x20DFC03F, 32); 
                m.setU32(40001, 0x0);
                Serial.println("TV LG: VOL - | Cod. 104");
                break;
                
           case 105: // tecla smart ----------------
                irsend.sendNEC(0x20DF3EC1, 32); 
                m.setU32(40001, 0x0);
                break;
                
             case 106: // settings ------------
                irsend.sendNEC(0x20DF3EC1, 32); 
                m.setU32(40001, 0x0);
                break;
                
           case 107: // qmenu -----------
                irsend.sendNEC(0x20DFA25D, 32); 
                m.setU32(40001, 0x0);
                break;
                
           case 108: // para cima ---------------
                irsend.sendNEC(0x20DF02FD, 32); 
                m.setU32(40001, 0x0);
                break;
                
           case 109: // para baixo -----------------
                irsend.sendNEC(0x20DF827D, 32); 
                m.setU32(40001, 0x0);
                break;
                
           case 110: // para esquerda------------------
                irsend.sendNEC(0x20DFE01F, 32); 
                m.setU32(40001, 0x0);
                break;
                
           case 111: // para direita ------------------
                irsend.sendNEC(0x20DF609F, 32); 
                m.setU32(40001, 0x0);
                break;
                
           case 112: // OK --------------------
                irsend.sendNEC(0x20DF22DD, 32); 
                m.setU32(40001, 0x0);
                break;
                
           case 113: // voltar ----------------
                irsend.sendNEC(0x20DF14EB, 32); 
                m.setU32(40001, 0x0);
                break;
                
           case 114: // sair --------------------
                irsend.sendNEC(0x20DFDA25, 32); 
                m.setU32(40001, 0x0);
                break;
                
           case 115: // gravar
                irsend.sendNEC(0x20DFBD42, 32); 
                m.setU32(40001, 0x0);
                break;
                
           case 116: // stop ---------------
                irsend.sendNEC(0x20DF8D72, 32); 
                m.setU32(40001, 0x0);
                break;
                
           case 117: // para traz ----------------
                irsend.sendNEC(0x20DFF10E, 32); 
                m.setU32(40001, 0x0);
                break;
                
           case 118: // play ---------------
                irsend.sendNEC(0x20DF0DF2, 32); 
                m.setU32(40001, 0x0);
                break;
                
           case 119: // pause ------------------
                irsend.sendNEC(0x20DF5DA2, 32); 
                m.setU32(40001, 0x0);
                break;
                
           case 120: // para frente -----------------
                irsend.sendNEC(0x20DF718E, 32); 
                m.setU32(40001, 0x0);
                break;
                
           case 121: // vermelho
                irsend.sendNEC(0x20DF4EB1, 32); 
                m.setU32(40001, 0x0);
                break;
                
           case 122: // verde
                irsend.sendNEC(0x20DF8E71, 32); 
                m.setU32(40001, 0x0);
                break;
                
           case 123: // amarelo
                irsend.sendNEC(0x20DFC639, 32); 
                m.setU32(40001, 0x0);
                break;
                
           case 124: // my pps 
                irsend.sendNEC(0x20DF42BD, 32); 
                m.setU32(40001, 0x0);
                break;
                
           case 125: // info ---------------
                irsend.sendNEC(0x20DF55AA, 32); 
                m.setU32(40001, 0x0);
                break;
                
           case 126: // ratio
                irsend.sendNEC(0x20DF9E61, 32); 
                m.setU32(40001, 0x0);
                break;
                
           case 127: // canal +
                irsend.sendNEC(0x20DF00FF, 32); 
                m.setU32(40001, 0x0);
                break;
                
           case 128: // canal - 
                irsend.sendNEC(0x20DF807F, 32);
                m.setU32(40001, 0x0);
                break;
                
           case 129: // futebol
                irsend.sendNEC(0x20DFDD22, 32); 
                m.setU32(40001, 0x0);
                break;
   //   Fim Controle LG SMART


               

}//fim switch
}
