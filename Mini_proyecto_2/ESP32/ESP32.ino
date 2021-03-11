// Adafruit IO Digital Input Example
// Tutorial Link: https://learn.adafruit.com/adafruit-io-basics-digital-input
//
// Adafruit invests time and resources providing this open source code.
// Please support Adafruit and open source hardware by purchasing
// products from Adafruit!
//
// Written by Todd Treece for Adafruit Industries
// Copyright (c) 2016 Adafruit Industries
// Licensed under the MIT license.
//
// All text above must be included in any redistribution.

/************************** Configuration ***********************************/

// edit the config.h tab and enter your Adafruit IO credentials
// and any additional configuration needed for WiFi, cellular,
// or ethernet clients.
#include "config.h"

/************************ Example Starts Here *******************************/
byte lr=0b00000000;
unsigned long previousMillis = 0;
const long interval = 3000;
int tiempos=0;


// set up the 'digital' feed
AdafruitIO_Feed *led1 = io.feed("led 1");
AdafruitIO_Feed *led2 = io.feed("led 2");
AdafruitIO_Feed *tiempo = io.feed("tiempo");
void setup() {
  // start the serial connection
  Serial.begin(9600);
  io.connect();

  led1->onMessage(handleMessage);
  led2->onMessage(handleMessage1);
  tiempo->save(tiempos);
  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    delay(500);
  }
  led1->get();
  led2->get();
  tiempo->get();
}

void loop() {

  // io.run(); is required for all sketches.
  // it should always be present at the top of your loop
  // function. it keeps the client connected to
  // io.adafruit.com, and processes any incoming data.
  io.run();

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    tiempo->save(tiempos);
  }
  
   if (Serial.available()>0)
  {
    tiempos=Serial.read();
    Serial.write(lr);
  }
}

void handleMessage(AdafruitIO_Data *data) {
  bitWrite(lr,1,data->toPinLevel());
  digitalWrite(2,bitRead(lr,1));
  
}
void handleMessage1(AdafruitIO_Data *data) {

  bitWrite(lr,2,data->toPinLevel());
}
