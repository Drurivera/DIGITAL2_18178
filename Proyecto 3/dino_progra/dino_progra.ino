/***************************************************************************
 * Alumno: Mariandree Rivera
 * Carnet: 18178
 * Proyecto #3, Dino_Run
 * *************************************************************************
 */
//la libreria fue tomada de :
// UTFT_Demo_320x240 
// Copyright (C)2015 Rinky-Dink Electronics, Henning Karlsen. All right reserved
// web: http://www.RinkyDinkElectronics.com/
// This demo was made for modules with a screen resolution 
// of 320x240 pixels.
//
// This program requires the UTFT library.
//
// Bitmap info for dinojuego_mono
#include <UTFTGLUE.h>              //libreria de GLUE para usar la pantalla 
UTFTGLUE myGLCD(0,A2,A1,A3,A4,A0); //variables utilizadas para la transmision con la pantalla.
 int pushT;
 int pushTE = 10;
 int Run = 0;                 //Variables declaradas
 int Bloque = 0;
 int Action = 1;

// -------------------------------------------------------------------------------
// Arduino Uno & ESP32 / 2009:
// -------------------
// Standard Arduino Uno & ESP32 /2009 shield        : <display model>,A5,A4,A3,A2
// DisplayModule Arduino Uno & ESP32 TFT shield     : <display model>,A5,A4,A3,A2
// -------------------------------------------------------------------------------

void setup()
{
  randomSeed(analogRead(0));
  

  myGLCD.InitLCD();                                        //inicializar la pantalla.
  myGLCD.setFont(BigFont);                                 //Seteo de la letra a utilizar.
  Serial.begin(9600);                                      //Baute rate para la comunicacion.
  myGLCD.fillScr(0,0,0);                                   //limpieza de la pantalla.
}

void loop(){
   Serial.write(1);                                       //Inicializacion de la comunicacion.
   pushT = Serial.read();                                 //lectura del puerto de la comunicacion.
   Home();                                                //manda a llamar la funcion de la inicio.
   delay (1000);
   if (digitalRead(pushTE) == 0){                         //verifica que si el push esta presionado.
    myGLCD.fillScr(0,0,0);                                //coloca el fondo en negro
    Action = 1;
    while (Action == 1){
      Juego();                                            //manda a llamar la funcion principal del juego.
      Runner();
      MoveB ();
      if (digitalRead(pushTE) == 0){                     //verifica que si el push esta presionado.
        SaltoRunner();                                   //manda a llamar la funcion del brinco del personaje.
        MoveB ();
      }
      Perder ();
    }
    return;
}
}  
void Home(){
  myGLCD.setColor(255,255,255);                                       //color blanco para el cuadrado
  myGLCD.fillRoundRect(60, 80, 260,150);                              //parametros donde se crea el rectangulo
  myGLCD.setColor(0, 0, 0);                                           //color de la letra
  myGLCD.setBackColor(255,255,255);                                   //fondo de la letra 
  myGLCD.print("Bienvenido a Dino Run", CENTER, 93);
  myGLCD.print("Presiona el push para iniciar", CENTER, 119);
  Action = 1;
  myGLCD.setColor(255, 255, 255);                                     //color de la letra
  myGLCD.setBackColor(0,0,0);                                         //fondo de la letra 
  myGLCD.print("ESTAS LISTO?", CENTER, 180);
}

void Perder (){

  if (((Bloque<=-120)&&(Bloque)>=-220) && Run == 0){
    
    myGLCD.fillScr(0,0,0);                                           //Coloca la pantalla en negro.
    Gameover();                                                      //manda a llamar la funcion del brinco del personaje.
    delay(2000);
    myGLCD.fillScr(0,0,0);

    }
  return;
  
  } 

void Juego(){
  myGLCD.setColor(14, 95, 166);                                      //color del rectangulo del titulo.
  myGLCD.fillRect(0, 0, 319, 13);                                    //coordenadas donde se debe imprimir el rectangulo superior.
  myGLCD.fillRect(0, 226, 319, 239);                                 //coordenadas donde se debe imprimir el rectangulo interior.
  myGLCD.setColor(255, 255, 255);                                    //color de la letra del titulo.
  myGLCD.setBackColor(14, 95, 166);                                  //color del desaltado de texto del titulo.
  myGLCD.print("*** Juego Dino Run ***", CENTER, 1);
  myGLCD.setBackColor(14, 95, 166);
  myGLCD.setColor(255,255,255);
  myGLCD.print("By Mariandree Rivera", CENTER, 227);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRect(0, 14, 319, 225);
  myGLCD.setColor(255, 255, 255);
  myGLCD.fillRect(0, 196, 319, 201);  


}
void Gameover(){                                                   //funcion que se despliega al perder en el juego.
  myGLCD.fillScr(0,0,0);
  myGLCD.setColor(255,0,0);
  myGLCD.fillRoundRect(60, 80, 260,150);
  
  myGLCD.setColor(255, 255, 255);
  myGLCD.setBackColor(255,0,0);
  myGLCD.print("GAME OVER", CENTER, 93);
  myGLCD.print("Presiona el push para reiniciar", CENTER, 119);
  myGLCD.setColor(255, 255, 255);
  myGLCD.setBackColor(255,255,255);
  myGLCD.print("VUELVETE A RETAR?", CENTER, 180);
  Action = 0;
  Run = 0;
  Bloque = 0;
  
  return;

}
void Runner(){
   myGLCD.setColor(255, 255, 255);
   myGLCD.fillRoundRect(110, 130+Run, 120,195+Run);                      //Funcion del personaje.
   myGLCD.fillRoundRect(110, 185+Run, 155,195+Run);
   myGLCD.fillRoundRect(100, 160+Run, 140,170+Run);
   myGLCD.fillRoundRect(100, 140+Run, 140,150+Run);
}
void LimpiarRunner(){
   myGLCD.setColor(0,0,0);
   myGLCD.fillRoundRect(110, 130+Run, 120,195+Run);                     //Funcion de limpieza del personaje.
   myGLCD.fillRoundRect(110, 185+Run, 155,195+Run);
   myGLCD.fillRoundRect(100, 160+Run, 140,170+Run);
   myGLCD.fillRoundRect(100, 140+Run, 140,150+Run);

}
void SaltoRunner(){                                                     //funcion del salto del personaje.
      
      Run = 0;
      Runner();
      delay(250);
      MoveB ();
      LimpiarRunner();
      Run = -50;     
      Runner();
      delay(500);
      MoveB ();
      //Perder ();
      LimpiarRunner();
      Run = -100;       
      Runner();
      delay(500);
      MoveB ();
      LimpiarRunner();
      Run = -50;
      //Perder ();       
      Runner();
      MoveB ();
      MoveB ();
      LimpiarRunner();
      Run = 0;     
      Runner();
} 
void Block (){
  myGLCD.setColor(0, 255, 255);                                         //Funcion del obstaculo.
  myGLCD.fillRoundRect(280+Bloque, 160, 320+Bloque,195);
  }

void LimpiarBlock (){
  myGLCD.setColor(0,0,0);                                              //Funcion de limpieza del obstaculo.
  myGLCD.fillRoundRect(280+Bloque, 160, 320+Bloque,195);
  }

void MoveB (){                                                         //Funcion del movimiento del obstaculo.
      LimpiarBlock();
      Bloque = Bloque -30;
      if(Bloque <= -270){
        Bloque = 0;
        }
      Block();
      delay(450);
}

  
