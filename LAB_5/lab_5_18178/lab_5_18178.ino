/***************************************************************************
 * Alumno: Mariandree Rivera
 * Carnet: 18178
 * Laboratorio #5
 * *************************************************************************
 */

#include <SPI.h>
#include <SD.h>


int nombre = Serial.read();
File root;
File myFile;

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  SPI.setModule(0);


  Serial.print("Initializing SD card...");
  pinMode(10, OUTPUT);

  if (!SD.begin(32)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
  Serial.println("");
  Serial.println(" MENU DE OPCIONES PARA IMPRIMIR ");
  Serial.println("");
  root = SD.open("/");
  printDirectory(root, 0);  
  nombre = 0;
}
 void loop(){
    //OBTENIDO CODIGO PARA LEER CADENAS DE https://www.luisllamas.es/cadenas-de-texto-puerto-serie-arduino/
  while (Serial.available()){
      nombre = Serial.read();//guarda lo que se lee del puerto 
      casos ();
   }
 }
 void casos(){ 
  printDirectory(root, 0);
  if(nombre == 49){
    // re-open the file for reading:
    myFile = SD.open("1_DINO.txt");
    if (myFile) {
      Serial.println("Archivo:");
      // read from the file until there's nothing else in it:
      while (myFile.available()) {
        Serial.write(myFile.read());
      }
      // close the file:
      myFile.close();
      nombre = 0;
    } 
    else {
      // if the file didn't open, print an error:
      Serial.println("error opening 1_DINO.txt");
      return;
    }
  }

  if(nombre == 50){
    // re-open the file for reading:
    myFile = SD.open("2_HONGO.txt");
    if (myFile) {
      Serial.println("Archivo:");
      // read from the file until there's nothing else in it:
      while (myFile.available()) {
        Serial.write(myFile.read());
      }
      // close the file:
      myFile.close();
      nombre = 0;
      return;
    } 
    else {
      // if the file didn't open, print an error:
      Serial.println("error opening DINO.txt");
      return;
    }
  }

  if(nombre == 51){
    // re-open the file for reading:
    myFile = SD.open("3_CORA~1.txt");
    if (myFile) {
      Serial.println("Archivo:");
      // read from the file until there's nothing else in it:
      while (myFile.available()) {
        Serial.write(myFile.read());
      }
      // close the file:
       myFile.close();
      nombre = 0;
      return;
    } 
    else {
      // if the file didn't open, print an error:
      Serial.println("error opening 3_CORA~1.txt");
      return;
    }
  }
   if(nombre == 48){
    Serial.println("aqui estoy");
    return;
    }
   }
 void printDirectory(File dir, int numTabs) {
   while(true) {
     
     File entry =  dir.openNextFile();
     if (! entry) {
       // no more files
       //dir.rewindDirectory();
       break;
     }
     for (uint8_t i=0; i<numTabs; i++) {
       Serial.print('\t');
     }
     Serial.print(entry.name());
     if (entry.isDirectory()) {
       Serial.println("/");
       printDirectory(entry, numTabs+1);
     } else {
       // files have sizes, directories do not
       Serial.print("\t\t");
       Serial.println(entry.size(), DEC);
     }
     entry.close();
   }
}
