//Proje Final 13.04.2020

#include <SoftwareSerial.h>
#include <Servo.h>
Servo servom;
SoftwareSerial bt_iletisim(7, 8);



#define red 5
#define green 6
#define blue 3
#define SPEEDPOT A0

int RedVal = 255;
int GreenVal = 255;
int BlueVal = 255;
int FadeSpeedVal = 10;
int buton = 2;
int bdurum = 0;

float rad;
int r, g, b, i, j, k, sinOut;


byte data;
int red_led = 2;
int blue_led = 13;
int role = 12;


void setup() {
 
  Serial.begin(9600);
  bt_iletisim.begin(9600);
  servom.attach(11);
  servom.write(0);

  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

  pinMode(red_led, OUTPUT);
  pinMode(blue_led, OUTPUT);
  pinMode(role, OUTPUT);
  pinMode(buton,INPUT);
  
}

void loop() {
    
  if (bt_iletisim.available()) {
    data = bt_iletisim.read();
    Bt();
    Serial.println("bt calisti");
       Serial.println(data);
 }

}
void btkontrol(){
   data = bt_iletisim.read();
   Bt();  
}

void Ikaz() {
  analogWrite(red, 0);
  analogWrite(blue, 0);
  analogWrite(green, 0);
  
  analogWrite(blue, 255);
  delay(200);
  analogWrite(blue, 0);
  delay(200);
  analogWrite(blue, 255);
  delay(200);
  analogWrite(blue, 0);
  delay(200);
  analogWrite(blue, 255);
  delay(200);
  analogWrite(blue, 0);
}

void GreenMod() {
  for (i = 0; i < 256; i++)
  {
    btkontrol();
    //CheckFadeSpeed();
    analogWrite(green, i);
    delay(FadeSpeedVal);
    
  }
  
  for (i = 256; i >= 0; i--)
  {
    btkontrol();
    //CheckFadeSpeed();
    analogWrite(green, i);
    delay(FadeSpeedVal);
    
  }
}

void Kapa() {
  analogWrite(red, 0);
  analogWrite(blue, 0);
  analogWrite(green, 0);
}

void FadeMod(){
  analogWrite(red, 255);
  analogWrite(blue, 255);
  analogWrite(green, 255);
  for (i = 90; i <= 270; i++)
  {
    btkontrol();
    //CheckFadeSpeed();
    rad = DEG_TO_RAD * i;
    sinOut = constrain((sin(rad) * 128) + 128, 0, 255);
    analogWrite(green, sinOut);
    delay(FadeSpeedVal);
  }
  for (i = 90; i <= 270; i++)
  {
    btkontrol();
    //CheckFadeSpeed();
    rad = DEG_TO_RAD * i;
    sinOut = constrain((sin(rad) * 128) + 128, 0, 255);
    analogWrite(blue, sinOut);
    delay(FadeSpeedVal);
  }
  for (i = 270; i >= 90; i--)
  {
    btkontrol();
    //CheckFadeSpeed();
    rad = DEG_TO_RAD * i;
    sinOut = constrain((sin(rad) * 128) + 128, 0, 255);
    analogWrite(green, sinOut);
    delay(FadeSpeedVal);
  }
  for (i = 90; i <= 270; i++)
  {
    btkontrol();
    //CheckFadeSpeed();
    rad = DEG_TO_RAD * i;
    sinOut = constrain((sin(rad) * 128) + 128, 0, 255);
    analogWrite(red, sinOut);
    delay(FadeSpeedVal);
  }
  for (i = 270; i >= 90; i--)
  {
    btkontrol();
    //CheckFadeSpeed();
    rad = DEG_TO_RAD * i;
    sinOut = constrain((sin(rad) * 128) + 128, 0, 255);
    analogWrite(blue, sinOut);
    delay(FadeSpeedVal);
  }
  for (i = 90; i <= 270; i++)
  {
    btkontrol();
    //CheckFadeSpeed();
    rad = DEG_TO_RAD * i;
    sinOut = constrain((sin(rad) * 128) + 128, 0, 255);
    analogWrite(green, sinOut);
    delay(FadeSpeedVal);
  }
  for (i = 270; i >= 90; i--)
  {
    btkontrol();
    //CheckFadeSpeed();
    rad = DEG_TO_RAD * i;
    sinOut = constrain((sin(rad) * 128) + 128, 0, 255);
    analogWrite(green, sinOut);
    analogWrite(red, sinOut);
    delay(FadeSpeedVal);
  }
}
 
void FlashMod() {

  for (i = 270; i >= 90; i--)
  {
    btkontrol();
    //CheckFadeSpeed();
    rad = DEG_TO_RAD * i;
    sinOut = constrain((sin(rad) * 128) + 128, 0, 255);
    analogWrite(red, sinOut);
    delay(FadeSpeedVal);
  }

  for (i = 90; i <= 270; i++)
  {
    btkontrol();
    //CheckFadeSpeed();
    rad = DEG_TO_RAD * i;
    sinOut = constrain((sin(rad) * 128) + 128, 0, 255);
    analogWrite(red, sinOut);
    delay(FadeSpeedVal);
  }

  for (i = 270; i >= 90; i--)
  {
    btkontrol();
    //CheckFadeSpeed();
    rad = DEG_TO_RAD * i;
    sinOut = constrain((sin(rad) * 128) + 128, 0, 255);
    analogWrite(blue, sinOut);
    delay(FadeSpeedVal);
  }

  for (i = 90; i <= 270; i++)
  {
    btkontrol();
    //CheckFadeSpeed();
    rad = DEG_TO_RAD * i;
    sinOut = constrain((sin(rad) * 128) + 128, 0, 255);
    analogWrite(blue, sinOut);
    delay(FadeSpeedVal);
  }

  for (i = 270; i >= 90; i--)
  {
    btkontrol();
    //CheckFadeSpeed();
    rad = DEG_TO_RAD * i;
    sinOut = constrain((sin(rad) * 128) + 128, 0, 255);
    analogWrite(green, sinOut);
    delay(FadeSpeedVal);
  }

  for (i = 90; i <= 270; i++)
  {
    btkontrol();
    //CheckFadeSpeed();
    rad = DEG_TO_RAD * i;
    sinOut = constrain((sin(rad) * 128) + 128, 0, 255);
    analogWrite(green, sinOut);
    delay(FadeSpeedVal);
  }

}

void GeceModu() {
    analogWrite(red, 255);
    analogWrite(blue, 255);
    analogWrite(green, 255);
 
}


void Bt(){

 
    if (data == 1) {
      digitalWrite(red_led, HIGH);
    }
    else if (data == 2) {
      digitalWrite(red_led, LOW);
    }
    else if (data == 3) {
      digitalWrite(blue_led, HIGH);
    }
    else if (data == 4) {
      digitalWrite(blue_led, LOW);
    }
    else if (data == 5) {
      
      servom.write(0);
      delay(10);
      Ikaz();
    }
    else if (data == 6) {
      servom.write(130);
      delay(10);
      Ikaz();
    }
    else if (data == 7) {
      digitalWrite(role, HIGH);
    }
    else if (data == 8) {
      digitalWrite(role, LOW);
    }


    else if (data == 10) {  
      byte  veri = data; 
      while(veri==10){
        FadeMod();
               data = bt_iletisim.read();
          //if(data==13){
          //  Kapa();
           // break;
       // }
      }
    }
    else if (data == 11) {  
      byte  veri = data; 
      while(veri==11){
        FlashMod();
        data = bt_iletisim.read();
      }
    }
    else if (data == 12) {  
      byte  veri = data; 
      while(veri==12){
        GreenMod();
        data = bt_iletisim.read();
      }
    }
    
    else if (data == 13){
      byte veri1 = data;
      while(veri1 ==13){
      Kapa();
      data = bt_iletisim.read();
      Bt();
      }   
   }

   else if(data == 15){
      FadeSpeedVal=FadeSpeedVal+1;
   }
   else if(data == 16){
      FadeSpeedVal=FadeSpeedVal-1;
   }
   
   else if(data == 17){
      byte veri1 = data;
      while(veri1 ==17){
      GeceModu();
      data = bt_iletisim.read();
      Bt();
      }
   }
   else if (data == 18){
      byte veri1 = data;
      while(veri1 ==18){
        Kapa();
        data = bt_iletisim.read();
        Bt();
        analogWrite(red, 0);
        analogWrite(blue, 255);
        analogWrite(green, 0);
    }
   }
   else if (data == 19){
     byte veri1 = data;
      while(veri1 ==19){
        Kapa();
        data = bt_iletisim.read();
         Bt();
        analogWrite(red, 255);
        analogWrite(blue, 0);
        analogWrite(green, 0);
    }
   }
   else if (data == 20){
     byte veri1 = data;
      while(veri1 ==20){
        Kapa();
        data = bt_iletisim.read();
        Bt();
        analogWrite(red, 255);
        analogWrite(blue, 255);
        analogWrite(green, 255);
   }
  }
   else if (data == 21){
    byte veri1 = data;
      while(veri1 ==21){
        Kapa();
        data = bt_iletisim.read();
        Bt();
        analogWrite(red, 0);
        analogWrite(blue, 0);
        analogWrite(green, 255);
   }
  }
   bdurum = digitalRead(buton);
   if (bdurum==HIGH){
    Serial.println("1 oldu");
    servom.write(100);
    
    delay(2000);
    servom.write(0);
    
    }
    
   
}


void CheckFadeSpeed(){  
 // FadeSpeedVal = analogRead(SPEEDPOT);
 // FadeSpeedVal = map(FadeSpeedVal, 0, 1023, 0, 20);
}
