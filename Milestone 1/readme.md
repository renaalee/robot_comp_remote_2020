# Milestone 1
#### Getting the Robot to Move 4 ft
------

## Setup
- Attached the servo shield to the pre-assembled robot base
- Installed the ZumoShield library on the Arduino IDE 
      - ```Tools > Manage Libraries``` search for ```ZumoShield```

## Programming
- added ZumoShield library to the project code 
      - ```Sketch > Include Library > Contributed Libraries > ZumoShield```
- 
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

