/*
 * Controle fita Led RGB, 
 * Vários efeitos de cores
 * OK - TESTADA E FUNCIONANDO - 27/03/2023
 * Manter portas de saída 9, 8 e 7
 */
 
//SENSOR RGB
     int LEDred                   = 9;
     int LEDgreen                 = 8;
     int LEDblue                  = 7;
     //FIM SENSOR RGB

//VALORES LEDS RGB
     int ValorRed                 = 0 ;
     int ValorGreen               = 0 ;
     int ValorBlue                = 0 ;
     


//void setup()
void prepareModRGB()
{

//Ao Reiniciar o sistema aciona automaticamente os relés:
        digitalWrite(LEDred, LOW); //
        digitalWrite(LEDgreen, LOW); //        
        digitalWrite(LEDblue, LOW); //

  //RGB
        pinMode (LEDred, OUTPUT);        //define LED Strip as output
        pinMode (LEDgreen, OUTPUT);        //define LED Strip as output
        pinMode (LEDblue, OUTPUT);
     
}//FIM SETUP



//void loop()
void monitoringModRGB()
{//Inicio Loop

// Executa comunicacao modbus
Mb.Run();

// Verifica o valor da 1a variavel modbus
switch (Mb.R[0])

    {//inicio switch

           case 2012: //STROBO
                      strobo();
                      break;

           case 2013: //efeito cores
                      efeito_de_cores();
                      break;

              case 2014: //
                      vermelhoFuncao();
                      break;

              case 2015: //
                      azulFuncao();
                      break;

              case 2016: //
                      verdeFuncao();
                      break;
                
              case 2024: // Desliga Fita RGB
                      offFuncao();
                      break;

              case 2017: //
                      amareloFuncao();
                      break;

              case 2018: //
                      roxoFuncao();
                      break;

              case 2019: //
                      brancoFuncao();
                      break;

              case 2020: //
                      rozaFuncao();
                      break;

              case 2021: //
                      magentaFuncao();
                      break;

              case 2022: //
                      laranjaFuncao();
                      break;
    //fim fita RGB


    } // fim switch

} // fim loop

//=======================================================================================
//                        F U N Ç Õ E S
//=======================================================================================

void strobo(){
  // Acende todas as cores juntas
  analogWrite(LEDred, 255);
  analogWrite(LEDgreen, 255);
  analogWrite(LEDblue, 255);
  delay(50);

  // Apaga todas as cores juntas
  analogWrite(LEDred, 0);
  analogWrite(LEDgreen, 0);
  analogWrite(LEDblue, 0);
  delay(50);
  
  // Como o delay é rápido, a fita da um efeito tipo strobo
}


//-------------------------------------------------------------------------------------
void efeito_de_cores(){

    for (ValorGreen = 0; ValorGreen <255; ValorGreen=ValorGreen+5){
        analogWrite(LEDgreen, ValorGreen);
        delay(50);
    }
    for (ValorRed = 255; ValorRed > 0; ValorRed=ValorRed-5){
        analogWrite(LEDred, ValorRed);
        delay(50);
    }
    for (ValorBlue = 0; ValorBlue < 255; ValorBlue=ValorBlue+5){
        analogWrite(LEDblue, ValorBlue);
        delay(50);
    }
    for (ValorGreen = 255; ValorGreen > 0; ValorGreen=ValorGreen-5){
        analogWrite(LEDgreen, ValorGreen);
        delay(50);
    }
    for (ValorRed = 0; ValorRed < 255; ValorRed=ValorRed+5){
        analogWrite(LEDred, ValorRed);
        delay(50);
    }
    for (ValorBlue = 255; ValorBlue > 0; ValorBlue=ValorBlue-5){
        analogWrite(LEDblue, ValorBlue);
        delay(50);
    }
}

//-------------------------------------------------------------------------------------

void offFuncao(){
  digitalWrite(LEDblue, 0);
  digitalWrite(LEDgreen, 0);
  digitalWrite(LEDred, 0);
}
void vermelhoFuncao(){
  digitalWrite(LEDblue, 0);
  digitalWrite(LEDgreen, 0);
  digitalWrite(LEDred, 255);
}
void azulFuncao(){
  digitalWrite(LEDblue, 255);
  digitalWrite(LEDgreen, 0);
  digitalWrite(LEDred, 0);
}
void verdeFuncao(){
  digitalWrite(LEDblue, 0);
  digitalWrite(LEDgreen, 255);
  digitalWrite(LEDred, 0);
}
void amareloFuncao(){
  analogWrite(LEDblue, 12);
  analogWrite(LEDgreen, 252);
  analogWrite(LEDred, 255);
}
void roxoFuncao(){
  analogWrite(LEDblue, 128);
  analogWrite(LEDgreen, 0);
  analogWrite(LEDred, 128);
}
void brancoFuncao(){
  digitalWrite(LEDblue, 255);
  digitalWrite(LEDgreen, 255);
  digitalWrite(LEDred, 255);
}
void rozaFuncao(){
  analogWrite(LEDblue, 180);
  analogWrite(LEDgreen, 14);
  analogWrite(LEDred, 250);
}
void magentaFuncao(){
  analogWrite(LEDblue, 252);
  analogWrite(LEDgreen, 241);
  analogWrite(LEDred, 12);
}
void laranjaFuncao(){
  analogWrite(LEDblue, 9);
  analogWrite(LEDgreen, 130);
  analogWrite(LEDred, 255);
}

//-------------------------------------------------------------------------------------
