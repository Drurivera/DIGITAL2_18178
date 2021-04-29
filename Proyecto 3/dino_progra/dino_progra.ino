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
    int Action = 1;
    while (Action == 1){
      Juego();
      Runner();
      delay(250);
      Block ();
      delay(500);
      myGLCD.fillScr(0,0,0); //coloca el fondo en negro
      }
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
  
  myGLCD.setColor(255, 255, 255); //color de la letra
  myGLCD.setBackColor(0,0,0); //fondo de la letra 
  myGLCD.print("ESTAS LISTO?", CENTER, 180);
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

    for (int i=0; i<2250; i++)
  {
    myGLCD.setColor(102,102,255);
    myGLCD.drawPixel(2+random(316), 16+random(180));
  }
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
  
  delay (10000);

}

void Runner(){
   myGLCD.setColor(255, 255, 255);
   myGLCD.fillRoundRect(110, 130, 120,195);
   myGLCD.fillRoundRect(110, 185, 160,195);
   myGLCD.fillRoundRect(100, 160, 140,170);
   myGLCD.fillRoundRect(100, 140, 140,150);

}

void Block (){
  myGLCD.setColor(0, 255, 255);
  myGLCD.fillRoundRect(180, 160, 230,195);
  }
