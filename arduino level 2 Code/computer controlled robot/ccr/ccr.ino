#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2); //rs, en, d4, d5, d6, d7

const int l1 = 24;  //left motor pins
const int l2 = 25;
const int r1 = 0;  //right motor pins
const int r2 = 1;

const int e1 = 15;  //elbow motor pins
const int e2 = 16;
const int w1 = 13;  //wrist motor pins
const int w2 = 14;

void Forward(){    //forward
digitalWrite(l1,1);
digitalWrite(l2,0);
digitalWrite(r1,1);
digitalWrite(r2,0);
}

void Stop(){        //stop
digitalWrite(l1,0);
digitalWrite(l2,0);
digitalWrite(r1,0);
digitalWrite(r2,0);

digitalWrite(e1,0);
digitalWrite(e2,0);
digitalWrite(w1,0);
digitalWrite(w2,0);
}

void Reverse(){      //reverse
digitalWrite(l1,0);
digitalWrite(l2,1);
digitalWrite(r1,0);
digitalWrite(r2,1);

}

void Right(){      //right
digitalWrite(l1,1);
digitalWrite(l2,0);
digitalWrite(r1,0);
digitalWrite(r2,1);

}

void Left(){        //left
digitalWrite(l1,0);
digitalWrite(l2,1);
digitalWrite(r1,1);
digitalWrite(r2,0);

}

void ElbowUp(){      //elbowup
digitalWrite(e1,1);
digitalWrite(e2,0);

}

void ElbowDown(){      //elbowdown
digitalWrite(e1,0);
digitalWrite(e2,1);

}

void WristUp(){      //wristup
digitalWrite(w1,1);
digitalWrite(w2,0);

}

void WristDown(){      //wristdown
digitalWrite(w1,0);
digitalWrite(w2,1);

}


void setup(){
Serial.begin(9600);  //baudrate

pinMode(l1,OUTPUT);  //left motor
pinMode(l2,OUTPUT);  
pinMode(r1,OUTPUT);  //right motor
pinMode(r2,OUTPUT);  
pinMode(e1,OUTPUT);  //elbow motor
pinMode(e2,OUTPUT);  
pinMode(w1,OUTPUT);  //wrist motor
pinMode(w2,OUTPUT);  


lcd.begin(16,2);      //declaring 16*2 LCD
lcd.print("IIT PALAKKAD");  //initial display
delay(2000);
} 

void loop(){
lcd.clear();  //clearing lcd

while(!Serial.available()){

  lcd.clear();
  lcd.print("RockOn!LoveDose");  //print that no data is available
  delay(5);
  Stop();
}

char c = Serial.read();

Serial.println(c);
//lcd.clear();
//lcd.print(c);
//delay(10);
lcd.clear();


if( c == 'a' ){          //left
  Left();
  lcd.print( "Turning Left" );
  delay(20);
}

if( c == 'd' ){          //right
  Right();
  lcd.print( "Turning Right" );
  delay(20);
   
}

if( c == 'w' ){          //forward
  Forward();
  lcd.print( "Moving Forward" );
  delay(20);
}

if( c == 's' ){          //reverse
  Reverse();
  lcd.print( "Moving Backward" );
  delay(20);
}

if( c == 'j' ){          //wristup
  WristUp();
  lcd.print( "Wrist Moving Up" );
  delay(20);
}

if( c == 'k' ){          //wristdown
  WristDown();
  lcd.print( "Wrist Moving Down" );
  delay(20);
}

if( c == 'n' ){          //elbowup
  ElbowUp();
  lcd.print( "Elbow Moving Up" );
  delay(20);

}

if( c == 'm' ){          //elbowdown
  ElbowDown();
  lcd.print( "Elbow Moving Down" );
  delay(20);

}

}

