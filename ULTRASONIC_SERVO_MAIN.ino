#include <Servo.h>
#include <NewPing.h>

#define LM1 4     
#define LM2 5    
#define RM1 2    
#define RM2 3    
#define TP 8
#define EP 9
#define maximum_distance 200
boolean movestraight=false;
int distance=100;
NewPing sonar(TP,EP,maximum_distance);
Servo servo_pin;


void setup() 
{
  pinMode(LM1, OUTPUT);
  pinMode(LM2,OUTPUT);
  pinMode(RM1,OUTPUT);
  pinMode(RM2,OUTPUT);
  servo_pin.attach(10);
  servo_pin.write(115);
  delay(200);
  distance=readPing();
  delay(100);
  Serial.begin(9600);
}

void loop() {
  int distanceright=0;
  int distanceleft=0;
  delay(100);
  Serial.println(distance);
  if (distance<=15)
  {          
  
    movestop();
    delay(300);
   movebackward();
   delay(200);
    movestop();
   delay(300);
    distanceright=lookright();
    delay(880);
    distanceleft=lookleft();
    delay(880);
    if (distance>=distanceleft){
  
      turnright();
      delay(100);
      movestop();
    }
    else{
      turnleft();
      delay(100);
      movestop();    
    }
  }
  else{
    moveforward();
  }
  distance=readPing();
}

int lookright()
{
  servo_pin.write(50);
  delay(400);
  int distance=readPing();
  delay(100);
  servo_pin.write(115);
  return distance;
}

int lookleft()
{
  servo_pin.write(170);
  delay(400);
  int distance=readPing();
  delay(100);
  servo_pin.write(115);
  return distance;
}

int readPing()
{
    delay(50);
    int cm=sonar.ping_cm();
    if (cm==0){
      cm=250;}
      return cm;
}

void movestop()
{
      digitalWrite(RM1,LOW);
      digitalWrite(RM2,LOW);
      digitalWrite(LM1,LOW);
      digitalWrite(LM2,LOW);
      
}
void moveforward()
{
  if (!movestraight){
    movestraight=true;
    digitalWrite(RM1,HIGH);
    digitalWrite(RM2,LOW);
    digitalWrite(LM1,HIGH);
    digitalWrite(LM2,LOW);
    }
}

void movebackward()
{
    movestraight=false;
    digitalWrite(RM1,LOW);
    digitalWrite(RM2,HIGH);
    digitalWrite(LM1,LOW);
    digitalWrite(LM2,HIGH);
    
}

void turnright()
{
    digitalWrite(RM1,LOW);
    digitalWrite(RM2,HIGH);
    digitalWrite(LM1,HIGH);
    digitalWrite(LM2,LOW);
    delay(500);
     digitalWrite(RM1,HIGH);
    digitalWrite(RM2,LOW);
    digitalWrite(LM1,HIGH);
    digitalWrite(LM2,LOW);
}

void turnleft()
{
    digitalWrite(RM1,HIGH);
    digitalWrite(RM2,LOW);
    digitalWrite(LM1,LOW);
    digitalWrite(LM2,HIGH);
    delay(500);
     digitalWrite(RM1,HIGH);
    digitalWrite(RM2,LOW);
    digitalWrite(LM1,HIGH);
    digitalWrite(LM2,LOW);
}
