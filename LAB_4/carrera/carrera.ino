 #define LED_R RED_LED                              
 #define LED_G GREEN_LED
 #define LED_B BLUE_LED
  
  const int buttonPin1 = PUSH1;
  const int buttonPin2 = PUSH2;
  int  In=0;
  int Conta_1=0;
  int Conta_2=0;
  
void setup() {
  //Configuracion de de los pushbuttons
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonPin1), BotonJA, RISING);
  attachInterrupt(digitalPinToInterrupt(buttonPin2), BotonJB, RISING);
  //Configuracion de contador Jugador A
  pinMode(PD_0, OUTPUT);
  pinMode(PD_1, OUTPUT);
  pinMode(PD_2, OUTPUT);
  pinMode(PD_3, OUTPUT);
  pinMode(PE_1, OUTPUT);
  pinMode(PE_2, OUTPUT);
  pinMode(PE_3, OUTPUT);
  pinMode(PA_7, OUTPUT);
  //Configuracion de contador Jugador B
  pinMode(PB_5, OUTPUT);
  pinMode(PB_0, OUTPUT);
  pinMode(PB_1, OUTPUT);
  pinMode(PE_4, OUTPUT);
  pinMode(PE_5, OUTPUT);
  pinMode(PB_4, OUTPUT);
  pinMode(PA_5, OUTPUT);
  pinMode(PA_6, OUTPUT); 
  //Configuracion de semaforo. 
  pinMode(LED_G, OUTPUT); 
  pinMode(LED_R, OUTPUT);
  pinMode(LED_B, OUTPUT);
}
//Switch case para desplegar el valor en los leds del jugador 1.
void PrintJA (){
  if(Conta_1==1){
    digitalWrite(PD_0,HIGH);
    digitalWrite(PD_1,LOW);
    digitalWrite(PD_2,LOW);
    digitalWrite(PD_3,LOW);
    digitalWrite(PE_1,LOW);
    digitalWrite(PE_2,LOW);
    digitalWrite(PE_3,LOW);
    digitalWrite(PA_7,LOW);
    return;
    }
  if(Conta_1==2){
    digitalWrite(PD_0,LOW);
    digitalWrite(PD_1,HIGH);
    digitalWrite(PD_2,LOW);
    digitalWrite(PD_3,LOW);
    digitalWrite(PE_1,LOW);
    digitalWrite(PE_2,LOW);
    digitalWrite(PE_3,LOW);
    digitalWrite(PA_7,LOW);
    return;
    }
  if(Conta_1==3){
    digitalWrite(PD_0,LOW);
    digitalWrite(PD_1,LOW);
    digitalWrite(PD_2,HIGH);
    digitalWrite(PD_3,LOW);
    digitalWrite(PE_1,LOW);
    digitalWrite(PE_2,LOW);
    digitalWrite(PE_3,LOW);
    digitalWrite(PA_7,LOW);
    return;
    }
  if(Conta_1==4){
    digitalWrite(PD_0,LOW);
    digitalWrite(PD_1,LOW);
    digitalWrite(PD_2,LOW);
    digitalWrite(PD_3,HIGH);
    digitalWrite(PE_1,LOW);
    digitalWrite(PE_2,LOW);
    digitalWrite(PE_3,LOW);
    digitalWrite(PA_7,LOW);
    return;
    }
  if(Conta_1==5){
    digitalWrite(PD_0,LOW);
    digitalWrite(PD_1,LOW);
    digitalWrite(PD_2,LOW);
    digitalWrite(PD_3,LOW);
    digitalWrite(PE_1,HIGH);
    digitalWrite(PE_2,LOW);
    digitalWrite(PE_3,LOW);
    digitalWrite(PA_7,LOW);
    return;
    }
  if(Conta_1==6){
    digitalWrite(PD_0,LOW);
    digitalWrite(PD_1,LOW);
    digitalWrite(PD_2,LOW);
    digitalWrite(PD_3,LOW);
    digitalWrite(PE_1,LOW);
    digitalWrite(PE_2,HIGH);
    digitalWrite(PE_3,LOW);
    digitalWrite(PA_7,LOW);
    return;
    }
  if(Conta_1==7){
    digitalWrite(PD_0,LOW);
    digitalWrite(PD_1,LOW);
    digitalWrite(PD_2,LOW);
    digitalWrite(PD_3,LOW);
    digitalWrite(PE_1,LOW);
    digitalWrite(PE_2,LOW);
    digitalWrite(PE_3,HIGH);
    digitalWrite(PA_7,LOW);
    return;
    }  
  if(Conta_1==8){
    digitalWrite(PD_0,LOW);
    digitalWrite(PD_1,LOW);
    digitalWrite(PD_2,LOW);
    digitalWrite(PD_3,LOW);
    digitalWrite(PE_1,LOW);
    digitalWrite(PE_2,LOW);
    digitalWrite(PE_3,LOW);
    digitalWrite(PA_7,HIGH);
    return;
    } 
//Aqui esta la rutina para el ganador y reseteo de las variables.
  else{
    if(Conta_1==9){
      digitalWrite(BLUE_LED, HIGH);
      delay(500);
      }
    Conta_1=0;
    Conta_2=0;
    In = 0; 
        digitalWrite(PB_5,LOW);
    digitalWrite(PB_0,LOW);
    digitalWrite(PB_1,LOW);
    digitalWrite(PE_4,LOW);
    digitalWrite(PE_5,LOW);
    digitalWrite(PB_4,LOW);
    digitalWrite(PA_5,LOW);
    digitalWrite(PA_6,LOW);
    digitalWrite(PA_7,LOW);
    digitalWrite(BLUE_LED, LOW);
    return;
    }
  
  }
  //Switch case para desplegar el valor en los leds del jugador 2.
void PrintJB (){
  if(Conta_2==1){
    digitalWrite(PB_5,HIGH);
    digitalWrite(PB_0,LOW);
    digitalWrite(PB_1,LOW);
    digitalWrite(PE_4,LOW);
    digitalWrite(PE_5,LOW);
    digitalWrite(PB_4,LOW);
    digitalWrite(PA_5,LOW);
    digitalWrite(PA_6,LOW);
    return;
    }
  if(Conta_2==2){
    digitalWrite(PB_5,LOW);
    digitalWrite(PB_0,HIGH);
    digitalWrite(PB_1,LOW);
    digitalWrite(PE_4,LOW);
    digitalWrite(PE_5,LOW);
    digitalWrite(PB_4,LOW);
    digitalWrite(PA_5,LOW);
    digitalWrite(PA_6,LOW);
    return;
    }
  if(Conta_2==3){
    digitalWrite(PB_5,LOW);
    digitalWrite(PB_0,LOW);
    digitalWrite(PB_1,HIGH);
    digitalWrite(PE_4,LOW);
    digitalWrite(PE_5,LOW);
    digitalWrite(PB_4,LOW);
    digitalWrite(PA_5,LOW);
    digitalWrite(PA_6,LOW);
    return;
    }
  if(Conta_2==4){
    digitalWrite(PB_5,LOW);
    digitalWrite(PB_0,LOW);
    digitalWrite(PB_1,LOW);
    digitalWrite(PE_4,HIGH);
    digitalWrite(PE_5,LOW);
    digitalWrite(PB_4,LOW);
    digitalWrite(PA_5,LOW);
    digitalWrite(PA_6,LOW);
    return;
    }
  if(Conta_2==5){
    digitalWrite(PB_5,LOW);
    digitalWrite(PB_0,LOW);
    digitalWrite(PB_1,LOW);
    digitalWrite(PE_4,LOW);
    digitalWrite(PE_5,HIGH);
    digitalWrite(PB_4,LOW);
    digitalWrite(PA_5,LOW);
    digitalWrite(PA_6,LOW);
    return;
    }
  if(Conta_2==6){
    digitalWrite(PB_5,LOW);
    digitalWrite(PB_0,LOW);
    digitalWrite(PB_1,LOW);
    digitalWrite(PE_4,LOW);
    digitalWrite(PE_5,LOW);
    digitalWrite(PB_4,HIGH);
    digitalWrite(PA_5,LOW);
    digitalWrite(PA_6,LOW);
    return;
    }
  if(Conta_2==7){
    digitalWrite(PB_5,LOW);
    digitalWrite(PB_0,LOW);
    digitalWrite(PB_1,LOW);
    digitalWrite(PE_4,LOW);
    digitalWrite(PE_5,LOW);
    digitalWrite(PB_4,LOW);
    digitalWrite(PA_5,HIGH);
    digitalWrite(PA_6,LOW);
    return;
    }  
  if(Conta_2==8){
    digitalWrite(PB_5,LOW);
    digitalWrite(PB_0,LOW);
    digitalWrite(PB_1,LOW);
    digitalWrite(PE_4,LOW);
    digitalWrite(PE_5,LOW);
    digitalWrite(PB_4,LOW);
    digitalWrite(PA_5,LOW);
    digitalWrite(PA_6,HIGH);
    return;
    } 
//Aqui esta la rutina para el ganador y reseteo de las variables.
  else{
    if(Conta_2==9){
      digitalWrite(GREEN_LED, HIGH);
      delay(750);
      }
    Conta_1 =0;
    Conta_2 =0;
    In = 0;
    digitalWrite(PD_0,LOW);
    digitalWrite(PD_1,LOW);
    digitalWrite(PD_2,LOW);
    digitalWrite(PD_3,LOW);
    digitalWrite(PE_1,LOW);
    digitalWrite(PE_2,LOW);
    digitalWrite(PE_3,LOW); 
    digitalWrite(PA_6,LOW);
    digitalWrite(PA_7,LOW);
    digitalWrite(GREEN_LED,LOW);
    return ;
    }
}
void BotonJA (){
  if (In == 1){
    delay(790);
    //Incremento del contador.
    Conta_1= 1+Conta_1;
    //llamamos la funcion para poder imprimir en los leds, externos el valor que corresponde con el contador.
    PrintJA ();
    }
    return;
  }

void BotonJB (){
  if (In == 1){
    delay(790);
    //Incremento del contador.
    Conta_2= 1+Conta_2;
    //llamamos la funcion para poder imprimir en los leds, externos el valor que corresponde con el contador.
    PrintJB ();
    }
    return;
  }

void loop() {
  // iniciamos la rutina al presionar cualquiera de los dos botones, del semaforo. 
  if (In==0 && (digitalRead(buttonPin1)==0||digitalRead(buttonPin2)==0)){
     digitalWrite(LED_R,HIGH);
     digitalWrite(LED_G,LOW);

     delay(500);
     digitalWrite(LED_R,HIGH);  
     digitalWrite(LED_G,HIGH);
    
     delay(500);
     digitalWrite(LED_R, LOW);  
     digitalWrite(LED_G,HIGH);
    
     delay(500);
     digitalWrite(LED_R, LOW);    
     digitalWrite(LED_G, LOW);
     In=1;
     
}
}
