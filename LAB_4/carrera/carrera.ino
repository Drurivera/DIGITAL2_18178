  const int buttonPin1 = PUSH1;
  const int buttonPin2 = PUSH2;
  int conta_J1;
  int conta_J2;
  byte LED_B = 0b00000000;
  byte LED_G = 0b00000000;


void setup() {
  // put your setup code here, to run once:

  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(LED_B, OUTPUT); 
  pinMode(LED_G, OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly: 
  if (digitalRead(buttonPin1)==0 || digitalRead(buttonPin2)==0){
    Inicio();
  }
}

void Inicio () {
 digitalWrite(RED_LED,HIGH);
 digitalWrite(GREEN_LED,LOW);
 delay(500);
 digitalWrite(GREEN_LED,HIGH);
 digitalWrite(BLUE_LED,HIGH);
  delay(500);
 digitalWrite(GREEN_LED,HIGH);
 digitalWrite(BLUE_LED,LOW);
}
