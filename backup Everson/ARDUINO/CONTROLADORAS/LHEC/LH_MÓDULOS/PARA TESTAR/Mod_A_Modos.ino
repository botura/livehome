//RELES LUZES
        #define MOD_NORMAL        11 //MODULO ECONOMICO
        #define MOD_ECO           12 //MODULO ECONOMICO
        #define MOD_INTEL         13 //MODULO INTELIGENTE





void prepareI3PRO()
{
  //Ao Reiniciar o sistema aciona automaticamente os relés:
        digitalWrite(MOD_NORMAL, LOW); //LUZ HOME THEATER BRANCA
        digitalWrite(MOD_ECO, LOW); //LUZ HOME THEATER BRANCA
        digitalWrite(MOD_INTEL, LOW); //CAFETEIRA


 //RELES
        pinMode(MOD_NORMAL, OUTPUT);//RÉGUA ELETROS 
        pinMode(MOD_ECO, OUTPUT);//RÉGUA ELETROS 
        pinMode(MOD_INTEL, OUTPUT);

     
}//FIM SETUP
//*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,*-,





void monitoringI3PRO()
{//Inicio Loop


  // Executa comunicacao modbus
        Mb.Run();

  // Verifica o valor da 1a variavel modbus
        switch (Mb.R[0])
           {//inicio switch


                //MODO NORMAL

                        case 1: //RÉGUA ELETROS - LIGA
                                digitalWrite(MOD_NORMAL, 1);
                                digitalWrite(MOD_ECO, 0);
                                digitalWrite(MOD_INTEL, 0);
                                Mb.R[21]=digitalRead(MOD_NORMAL); //status do Relé
                                Mb.R[22]=digitalRead(MOD_INTEL); //status do Relé
                                Mb.R[23]=digitalRead(MOD_ECO); //status do Relé
                                Mb.R[0] = 0;    
                                break;

                //MODO INTELIGENTE

                        case 2: //RÉGUA ELETROS - LIGA
                                digitalWrite(MOD_NORMAL, 0);
                                digitalWrite(MOD_ECO, 0);                        
                                digitalWrite(MOD_INTEL, 1);
                                Mb.R[21]=digitalRead(MOD_NORMAL); //status do Relé
                                Mb.R[22]=digitalRead(MOD_INTEL); //status do Relé
                                Mb.R[23]=digitalRead(MOD_ECO); //status do Relé
                                Mb.R[0] = 0;    
                                break;


                //MODO ECONOMICO

                        case 3: //RÉGUA ELETROS - LIGA
                                digitalWrite(MOD_NORMAL, 0);
                                digitalWrite(MOD_ECO, 1);                         
                                digitalWrite(MOD_INTEL, 0);
                                Mb.R[21]=digitalRead(MOD_NORMAL); //status do Relé
                                Mb.R[22]=digitalRead(MOD_INTEL); //status do Relé
                                Mb.R[23]=digitalRead(MOD_ECO); //status do Relé
                                Mb.R[0] = 0;    
                                break;





// ---------------------------------   fim RELÉS   ---------------------------------------------
} // fim switch



} // fim loop
