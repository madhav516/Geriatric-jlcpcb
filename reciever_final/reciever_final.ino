#include<Servo.h>
#include<SPI.h>
#include<nRF24L01.h>
#include<RF24.h>
RF24 radio(9,8);
const byte address[6] = "00001";
Servo myservo;
Servo myservo1;
int trig =2;
int trig1 =7;
int echo1 =4;
int echo= 8;
int pos=0;
long distance;
long duration;
long duration1;
long distance1;
const int left_irsensor = 3;
const int right_irsensor = 5;//Says that the right IR sensor is connected to pin 8. const is for saying that it will always be connected to pin 8. int is for integer. 8 is an integer, so we use int. After int, a variable or a constant is declared. In this case, it is a constant. A variable can change values while a constant cannot.//const int left_irsensor = 7;
const int motor_rightFront = 6;//the wire of the right motor which controls its forward motion is connected to pin 3
const int motor_rightBack = 9;//the wire of the motor which controls its backward motion is connected to pin 3
const int motor_leftFront = 13;//The varables can be named however you want. I decided to go along with simple names.
const int motor_leftBack = 12;
int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
// put your setup code here, to run once:
while(!Serial);
Serial.begin(9600);
radio.begin();
radio.openReadingPipe(0,address);
radio.startListening();
Serial.begin(9600);
myservo.attach(11); //for control of u.s
myservo1.attach(10);//for control of door
pinMode(ledPin, OUTPUT);
pinMode(motor_rightBack, OUTPUT);// forwoard rotation of right motor
pinMode(motor_rightFront, OUTPUT);//backwoard rotation of right motor
pinMode(motor_leftBack, OUTPUT);//backwoard rotation of back motor
pinMode(motor_leftFront, OUTPUT);//forwoard rotation of back motor
pinMode(left_irsensor, INPUT);//left_irsensor
pinMode(right_irsensor, INPUT);//right_irsensor
pinMode(trig,OUTPUT);
pinMode(trig1,OUTPUT);
pinMode(echo1,INPUT);
pinMode(echo,INPUT);
}

void loop() {

if(radio.available())
 { 
   char text[32] = {0};
   radio.read(&text, sizeof(text));
   if(text== "D")
   {
    digitalWrite(motor_rightFront, LOW);
    digitalWrite(motor_rightBack, HIGH);
   }
 }
 
  light();
  
   for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }  
digitalWrite(trig, LOW);
delay(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trig, HIGH);
delay(10);
digitalWrite(trig, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echo, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
// put your main code here, to run repeatedly:
int right_sensor = digitalRead(right_irsensor);//declaring a variable called right_sensor to take the reading from the right IR sensor. We are using digitalRead() since it is only a white and black surface. It will read LOW for black and HIGH for white./
int left_sensor = digitalRead(left_irsensor);
int reading = distance;
if(reading>29)
{//If the reading is more than 29 cm, then the robot can run.
   if(right_sensor == LOW && left_sensor == HIGH)
   {
      left();//turn left.
      } 
           if(right_sensor == HIGH && left_sensor == LOW)
           {
            right();
           }
            if(right_sensor == HIGH && left_sensor == HIGH)
            {
             yay();
                }
              if(right_sensor == LOW && left_sensor == LOW)
              {
                forward();
       
                  }
}

else
{
yay();//if it is not more than 29 cm, then it will stop. yay() is defined as a function below. 
sonic();
 if(distance1<21)
 {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }  

  
}
}
 
}

void right(){//void is used to define functions. This function will make the robot turn right.
//digitalWrite() is used to make things work or stop based on digital signals given to it in the form of HIGH and LOW.HIGH is to make something work while LOW is to stop it./ 
digitalWrite(motor_rightFront, LOW);//make the right motor stop moving forward
digitalWrite(motor_rightBack,LOW );//make the right motor stop moving backward
digitalWrite(motor_leftFront, LOW);//make the left motor stop moving forward
digitalWrite(motor_leftBack, HIGH);//make the left motor stop moving backward
}

void left(){
digitalWrite(motor_rightFront, LOW);
digitalWrite(motor_rightBack, HIGH);
digitalWrite(motor_leftFront, LOW);
digitalWrite(motor_leftBack, LOW);

}

void forward(){
digitalWrite(motor_rightFront, LOW);
digitalWrite(motor_rightBack, HIGH);
digitalWrite(motor_leftFront, LOW);
digitalWrite(motor_leftBack, HIGH);

}

void mop(){
digitalWrite(motor_rightFront, LOW);
digitalWrite(motor_rightBack, HIGH);
}

void yay(){ //This is to make it stop. stop is a function on its own, so I could not name this function stop.
digitalWrite(motor_rightFront, LOW);
digitalWrite(motor_rightBack, LOW);
digitalWrite(motor_leftFront, LOW);
digitalWrite(motor_leftBack, LOW);
}

void backward(){
digitalWrite(motor_rightFront, HIGH);
digitalWrite(motor_rightBack, LOW);
digitalWrite(motor_leftFront, HIGH);
digitalWrite(motor_leftBack, LOW);
}
void sonic() 
{
  digitalWrite(trig1, LOW);
delay(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trig1, HIGH);
delay(10);
digitalWrite(trig1, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration1 = pulseIn(echo1, HIGH);
// Calculating the distance
distance1= duration1*0.034/2;


}

void light()

{
  sensorValue = analogRead(sensorPin);
 Serial.println(sensorValue);
 if(sensorValue < 100)
 {
   Serial.println("LED light on");
   digitalWrite(ledPin,HIGH);
   delay(1000);
 }
 else
{
 digitalWrite(ledPin,LOW);
 delay(sensorValue);
}
}
