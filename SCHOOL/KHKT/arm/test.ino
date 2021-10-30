#include<Servo.h>
Servo myservo;

char inp='a';

void setup(){
  Serial.begin(9600);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(2,OUTPUT);
}

void loop(){
//  myservo.write(180);
//  myservo.write(0);
//  digitalWrite(8,HIGH);
  while(Serial.available()){
    inp=Serial.read();
    Serial.println(inp);
  }
  //1
  if(inp=='1')
    digitalWrite(2,HIGH);
  else if(inp=='6')
    digitalWrite(2,LOW);
  //2
  if(inp=='2')
    digitalWrite(3,HIGH);
  else if(inp=='7')
    digitalWrite(3,LOW);
  //3
  if(inp=='3')
    digitalWrite(4,HIGH);
  else if(inp=='8')
    digitalWrite(4,LOW);
  //4
  if(inp=='4')
    digitalWrite(5,HIGH);
  else if(inp=='9')
    digitalWrite(5,LOW);
  //5
  if(inp=='5')
    digitalWrite(6,HIGH);
  else if(inp=='0')
    digitalWrite(6,LOW);
}
  
