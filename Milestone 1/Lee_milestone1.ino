// Remote Comp milestone 1
// Rena A. Lee Spring 2020

#include <ZumoShield.h>

ZumoMotors motors;

void setup() { 
}

void loop() {
  delay(1000);
  motors.setSpeeds(400,400)
  delay(3000);
  motors.setSpeeds(0,0)
  while(true){
  }
}
