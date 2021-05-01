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
#include <UTFTGLUE.h>              //use GLUE class and constructor
UTFTGLUE myGLCD(0,A2,A1,A3,A4,A0); //all dummy args
 int pushT;
 int pushTE = 10;
 int Run = 0;
 int Bloque = 0;
 int Action = 1;
// Declare which fonts we will be using
//extern uint8_t SmallFont[];      //GLUE defines as GFXFont ref

// Set the pins to the correct ones for your development shield
// ------------------------------------------------------------
// Arduino Uno / 2009:
// -------------------
// Standard Arduino Uno/2009 shield            : <display model>,A5,A4,A3,A2
// DisplayModule Arduino Uno TFT shield        : <display model>,A5,A4,A3,A2
//
// Arduino Mega:
// -------------------
// Standard Arduino Mega/Due shield            : <display model>,38,39,40,41
// CTE TFT LCD/SD Shield for Arduino Mega      : <display model>,38,39,40,41
//
// Remember to change the model parameter to suit your display module!
//UTFT myGLCD(ITDB32S,38,39,40,41);

void setup()
{
  randomSeed(analogRead(0));
  
// Setup the LCD
  myGLCD.InitLCD();
  myGLCD.setFont(BigFont);
  Serial.begin(9600); 
  pinMode(pushTE, INPUT);
  myGLCD.fillScr(0,0,0); //coloca el fondo en negro
}

void loop(){
   Serial.write(1);
   pushT = Serial.read();
   Home();
   delay (1000);
   if (digitalRead(pushTE) == 0){
    myGLCD.fillScr(0,0,0); //coloca el fondo en negro
    Action = 1;
    while (Action == 1){
      Juego();
      Runner();
      MoveB ();
      if (digitalRead(pushTE) == 0){
        SaltoRunner();
        MoveB ();
      }
      Perder ();
    }
    return;
}
}  
void Home(){
  //myGLCD.clrScr(); //limpia pantalla
  //myGLCD.fillScr(0,0,0); //coloca el fondo en negro
  myGLCD.setColor(255,255,255); //color blanco para el cuadrado
  myGLCD.fillRoundRect(60, 80, 260,150); //parametros donde se crea el rectangulo
  myGLCD.setColor(0, 0, 0); //color de la letra
  myGLCD.setBackColor(255,255,255); //fondo de la letra 
  myGLCD.print("Bienvenido a Dino Run", CENTER, 93);
  myGLCD.print("Presiona el push para iniciar", CENTER, 119);
  Action = 1;
  myGLCD.setColor(255, 255, 255); //color de la letra
  myGLCD.setBackColor(0,0,0); //fondo de la letra 
  myGLCD.print("ESTAS LISTO?", CENTER, 180);
}

void Perder (){

  if (((Bloque<=-120)&&(Bloque)>=-220) && Run == 0){
    
    myGLCD.fillScr(0,0,0);
    Gameover();
    delay(2000);
    myGLCD.fillScr(0,0,0);

    }
  return;
  
  } 

void Juego(){
  myGLCD.setColor(14, 95, 166); //color del rectangulo del titulo
  myGLCD.fillRect(0, 0, 319, 13); //coordenadas donde se debe imprimir el rectangulo
  myGLCD.fillRect(0, 226, 319, 239); 
  myGLCD.setColor(255, 255, 255); // //color de la letra del titulo
  myGLCD.setBackColor(14, 95, 166);
  myGLCD.print("*** Juego Dino Run ***", CENTER, 1);
  myGLCD.setBackColor(14, 95, 166);
  myGLCD.setColor(255,255,255);
  myGLCD.print("By Mariandree Rivera", CENTER, 227);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRect(0, 14, 319, 225);
  myGLCD.setColor(255, 255, 255);
  myGLCD.fillRect(0, 196, 319, 201);  


}
void Gameover(){
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
  
  //delay (10000);
  return;

}
void Runner(){
   myGLCD.setColor(255, 255, 255);
   myGLCD.fillRoundRect(110, 130+Run, 120,195+Run);
   myGLCD.fillRoundRect(110, 185+Run, 155,195+Run);
   myGLCD.fillRoundRect(100, 160+Run, 140,170+Run);
   myGLCD.fillRoundRect(100, 140+Run, 140,150+Run);
}
void LimpiarRunner(){
   myGLCD.setColor(0,0,0);
   myGLCD.fillRoundRect(110, 130+Run, 120,195+Run);
   myGLCD.fillRoundRect(110, 185+Run, 155,195+Run);
   myGLCD.fillRoundRect(100, 160+Run, 140,170+Run);
   myGLCD.fillRoundRect(100, 140+Run, 140,150+Run);

}
void SaltoRunner(){
      
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
  myGLCD.setColor(0, 255, 255);
  myGLCD.fillRoundRect(280+Bloque, 160, 320+Bloque,195);
  }

void LimpiarBlock (){
  myGLCD.setColor(0,0,0);
  myGLCD.fillRoundRect(280+Bloque, 160, 320+Bloque,195);
  }

void MoveB (){
      /*
      Bloque = 0;
      Block();
      delay(250);
 */
      LimpiarBlock();
      Bloque = Bloque -30;
      if(Bloque <= -270){
        Bloque = 0;
        }
      Block();
      delay(450);
      

}

  
