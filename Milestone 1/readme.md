# Milestone 1
> Create your own code that moves the Zumo at least 4 feet.

## Setup
- Attached the servo shield to the pre-assembled robot base
- Installed the ZumoShield library on the Arduino IDE ```Tools > Manage Libraries``` search for ```ZumoShield```

## Programming
- added ZumoShield library to the project code ```Sketch > Include Library > Contributed Libraries > ZumoShield```
- first line of loop delays function so I have time to unplug and set the robot down
- left and right motors set to max. speed (400)
- stops indefinitely after 3 seconds
```
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
```

## Milestone Completion

![alt text](https://github.com/renaalee/robot_comp_remote_2020/blob/master/Milestone%201/IMG_3214.MOV)
