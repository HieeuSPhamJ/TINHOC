#include<Servo.h>
Servo myservo;

int pos = 0;
int t = 20;
int INP=0;
int value;

void setup(){
  Serial.begin(9600);
  myservo.attach(9);
}

void loop(){
  while (Serial.available()){
    value = Serial.read()-48;
  }
  Serial.println(value);
  if (value==1)
    myservo.write(180);
  else
    myservo.write(0);
}


//const int led=9;
//int value=0;
//void setup()
// {
// Serial.begin(9600);
// pinMode(led, OUTPUT);
// digitalWrite (led, LOW);
// Serial.println("Connection established...");
// }
//void loop()
// {
// while (Serial.available())
// {
// value = Serial.read();
// }
// if (value == '1')
// digitalWrite (led, HIGH);
// else if (value == '0')
// digitalWrite (led, LOW);
// }
