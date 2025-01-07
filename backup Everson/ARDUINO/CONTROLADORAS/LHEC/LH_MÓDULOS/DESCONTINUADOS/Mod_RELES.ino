  


//void setup()
void prepareReles(){

        //Ao Reiniciar o sistema aciona automaticamente os relés:
        digitalWrite(RELE01, HIGH); //
        digitalWrite(RELE02, HIGH); //
        digitalWrite(RELE03, HIGH); //
//        digitalWrite(RELE04, HIGH); //
//        digitalWrite(RELE05, LOW); //
//        digitalWrite(RELE06, HIGH); //
//        digitalWrite(RELE07, HIGH); //
//        digitalWrite(RELE08, HIGH); //

        
        
        pinMode(RELE01, OUTPUT);// define LED como saida
        pinMode(RELE02, OUTPUT);// define LED como saida
        pinMode(RELE03, OUTPUT);// define LED como saida
//        pinMode(RELE04, OUTPUT);// define LED como saida
//        pinMode(RELE05, OUTPUT);// define LED como saida
//        pinMode(RELE06, OUTPUT);// define LED como saida
//        pinMode(RELE07, OUTPUT);// define LED como saida
//        pinMode(RELE08, OUTPUT);// define LED como saida

}
