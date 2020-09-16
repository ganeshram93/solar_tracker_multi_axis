
int pin1=0;
int pin2=1;
int val;

#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
                                     // for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 12,13,10,11);            

void setup() {
  // set the speed at 60 rpm:
  analogReference(DEFAULT);
  myStepper.setSpeed(50);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  // step one revolution  in one direction:
   val=(analogRead(pin1)-(analogRead(pin2)));
  Serial.println(val);
  if(val<100){
   Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  }
  if(val>200)
  {
   // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  }
}

