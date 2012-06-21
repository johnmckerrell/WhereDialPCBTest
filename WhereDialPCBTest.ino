
/* 
 Stepper Motor Control - one revolution
 
 This program drives a unipolar or bipolar stepper motor. 
 The motor is attached to digital pins 8 - 11 of the Arduino.
 
 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.  
 
  
 Created 11 Mar. 2007
 Modified 30 Nov. 2009
 by Tom Igoe
 
 */

#include <Stepper.h>

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
                                     // for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 7,5,6,4);            
const int buttonPin1 = 2, buttonPin2 = 3;
const int ledPin1 = 0, ledPin2 = 1, ledPin3 = 2, ledPin4 = 3;

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(9);
  // initialize the serial port:
//  Serial.begin(9600);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
}

void loop() {
  digitalWrite(ledPin1,HIGH);
  digitalWrite(ledPin2,HIGH);
  digitalWrite(ledPin3,HIGH);
  digitalWrite(ledPin4,HIGH);
  delay(1000);
  digitalWrite(ledPin4,LOW);
  delay(1000);
  digitalWrite(ledPin1,LOW);
  digitalWrite(ledPin2,LOW);
  digitalWrite(ledPin3,LOW);
  delay(500);
  digitalWrite(ledPin1,HIGH);
  digitalWrite(ledPin2,HIGH);
  digitalWrite(ledPin3,HIGH);
  delay(1000);
  digitalWrite(ledPin3,LOW);
  delay(1000);
  digitalWrite(ledPin2,LOW);
  delay(1000);
  digitalWrite(ledPin1,LOW);
  
  // step one revolution  in one direction:
//   Serial.println("clockwise");
  myStepper.step(200);//stepsPerRevolution);
  delay(1000);
  
//  Serial.println("counterclockwise");
  myStepper.step(-100);//-stepsPerRevolution);
  delay(1000); 
  
}

