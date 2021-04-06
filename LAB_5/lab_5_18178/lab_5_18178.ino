/***************************************************************************
 * Alumno: Mariandree Rivera
 * Carnet: 18178
 * Laboratorio #5
 * *************************************************************************
 */

#include <SPI.h>
#include <SD.h>

String x = "";

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
  Serial.println("-PARA CORAZON ESCRIBIR 'COR1' ");
  Serial.println("");
  Serial.println("-PARA CORAZON ESCRIBIR 'DIN2' ");
  Serial.println("");
  Serial.println("-PARA CORAZON ESCRIBIR 'HON3' ");
  Serial.println("");
  Serial.println("or END to finish"); 

}
 void loop(){
    //OBTENIDO CODIGO PARA LEER CADENAS DE https://www.luisllamas.es/cadenas-de-texto-puerto-serie-arduino/
  while (Serial.available()){
      char character = Serial.read();//guarda lo que se lee del puerto 
      if (character != '\n') // si character no es igual a nada
      {
         x.concat(character); //concatena los valores de character en una cadena
      }
       else
      {
         x = "";
      }
   }
   if(x=="COR1"){
    // re-open the file for reading:
    myFile = SD.open("CORAZON.txt");
    if (myFile) {
      Serial.println("Archivo:");
      // read from the file until there's nothing else in it:
      while (myFile.available()) {
        Serial.write(myFile.read());
      }
      // close the file:
      myFile.close();
      Serial.println("");
      Serial.println(" MENU DE OPCIONES PARA IMPRIMIR ");
      Serial.println("");
      Serial.println("-PARA CORAZON ESCRIBIR 'COR1' ");
      Serial.println("");
      Serial.println("-PARA CORAZON ESCRIBIR 'DIN2' ");
      Serial.println("");
      Serial.println("-PARA CORAZON ESCRIBIR 'HON3' ");
      Serial.println("");
      Serial.println("or END to finish");  
      return;
    } 
    else {
      // if the file didn't open, print an error:
      Serial.println("error opening test.txt");
      return;
    }
  }

   if(x=="DIN2"){
    // re-open the file for reading:
    myFile = SD.open("DINO.txt");
    if (myFile) {
      Serial.println("Archivo:");
      // read from the file until there's nothing else in it:
      while (myFile.available()) {
        Serial.write(myFile.read());
      }
      // close the file:
      myFile.close();
      Serial.println("");
      Serial.println(" MENU DE OPCIONES PARA IMPRIMIR ");
      Serial.println("");
      Serial.println("-PARA CORAZON ESCRIBIR 'COR1' ");
      Serial.println("");
      Serial.println("-PARA CORAZON ESCRIBIR 'DIN2' ");
      Serial.println("");
      Serial.println("-PARA CORAZON ESCRIBIR 'HON3' ");
      Serial.println("");
      Serial.println("or END to finish");   
      return;
    } 
    else {
      // if the file didn't open, print an error:
      Serial.println("error opening test.txt");
      return;
    }
  }

  if(x=="HON3"){
    // re-open the file for reading:
    myFile = SD.open("HONGO.txt");
    if (myFile) {
      Serial.println("Archivo:");
      // read from the file until there's nothing else in it:
      while (myFile.available()) {
        Serial.write(myFile.read());
      }
      // close the file:
      myFile.close();
      Serial.println("");
      Serial.println(" MENU DE OPCIONES PARA IMPRIMIR ");
      Serial.println("");
      Serial.println("-PARA CORAZON ESCRIBIR 'COR1' ");
      Serial.println("");
      Serial.println("-PARA CORAZON ESCRIBIR 'DIN2' ");
      Serial.println("");
      Serial.println("-PARA CORAZON ESCRIBIR 'HON3' ");
      Serial.println("");
      Serial.println("or END to finish");  
      return;
    } 
    else {
      // if the file didn't open, print an error:
      Serial.println("error opening test.txt");
      return;
    }
  }
 }
