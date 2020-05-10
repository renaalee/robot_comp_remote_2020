// Remote Comp milestone 1
// Rena A. Lee Spring 2020

#include <ZumoShield.h>

ZumoMotors motors;

void setup() {
  
}

void loop() {
  delay(1000);
  motors.setLeftSpeed(400);
  motors.setRightSpeed(400);
  delay(3000);
  motors.setLeftSpeed(0);
  motors.setRightSpeed(0);
  while(true){
    
  }

}
