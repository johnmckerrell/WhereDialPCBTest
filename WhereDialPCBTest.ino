
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
const int ledPin1 = 0, ledPin2 = 1;
int ledState1 = LOW, ledState2 = LOW;

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(9);
  // initialize the serial port:
//  Serial.begin(9600);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  // step one revolution  in one direction:
//   Serial.println("clockwise");
  myStepper.step(50);//stepsPerRevolution);
  delay(1000);
  
//  Serial.println("counterclockwise");
  myStepper.step(50);//-stepsPerRevolution);
  delay(1000); 
  
  if ( digitalRead(buttonPin1) == LOW ) {
    ledState1 = ledState1 == HIGH ? LOW : HIGH;
  }
  if ( digitalRead(buttonPin2) == LOW ) {
    ledState2 = ledState2 == HIGH ? LOW : HIGH;
  }
  digitalWrite(ledPin1, ledState1);
  digitalWrite(ledPin2, ledState2);
}

