# Milestone 1
> Create your own code that moves the Zumo at least 4 feet.

## Setup
- Attached the servo shield to the pre-assembled robot base
- Googled the basics of Zumo Motor Shield from a tutorial on the provided site. 
- Installed the ZumoShield library on the Arduino IDE ```Tools > Manage Libraries``` search for ```ZumoShield```

## Programming
- added ZumoShield library to the project code ```Sketch > Include Library > Contributed Libraries > ZumoShield```
- first line of loop delays function so I have time to unplug and set the robot down (oops later I figured out I can wait to turn the thing on haha)
- left and right motors set to max. speed (400) and it veers a bit to the right but I didn't tweak that because it will be following a line later. 
- stops indefinitely after 3 seconds
```
#include <ZumoShield.h>

ZumoMotors motors;

void setup() { 
}

void loop() {
  delay(1000);
  motors.setSpeeds(400,400);
  delay(3000);
  motors.setSpeeds(0,0);
  while(true){
  }
}
```

## Milestone Completion
https://drive.google.com/file/d/1LdA68ZpimTrfNODJFzG63vOBW31MFDLW/view?usp=sharing
