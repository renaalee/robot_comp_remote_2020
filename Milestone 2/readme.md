# Milestone 2
> Get the Zumo to follow a line on the floor for at least 4 feet.

## Setup
- 4 ft long line on the ground for the robot to follow
- Added Wire library to my project code at the top ```Sketch > Include Library > Wire``` to set up reading the IR sensors on the bottom of the robot.
- Went with PD control method from tutorial. I did try tinkering around with the bang-bang method but I couldn't get it to work, probably was finicky because I was working outside on a very dusty surface. I also could not figure out how to use the sprintf function.
- Seems pretty smooth and quick the way I have it now but no way to tell how it'll do with kinks in the track (until next milestone). 

## Programming
```
void setup() {
  int i;
  int spin_direction = 1;
  motors.setSpeeds(80*spin_direction, -80*spin_direction);
  for(i = 0; i<100; i++){
    linesensors.calibrate();
    if(i%50 == 25){ // every 50 loops, starting on loop 25...
      spin_direction = -spin_direction;
      motors.setSpeeds(80*spin_direction, -80*spin_direction);
    }
    delay(20);
  }
  motors.setSpeeds(0,0);
  delay(500);
}

unsigned int sensor_vals[6];
int THRESHOLD = 600;
int BASE_SPEED = 200;
int line_position;

void loop() {
  line_position = linesensors.readLine(sensor_vals);
  if(sensor_vals[0] > THRESHOLD && sensor_vals[1] > THRESHOLD){
    turn_left();
  } else if(sensor_vals[4] > THRESHOLD && sensor_vals[5] > THRESHOLD){
    turn_right();
  } else {
    follow_line();
  }
}
```
## Milestone Completion
https://drive.google.com/file/d/1ecU7MPx-Q_IZGPZOMbu8Xvlg-8qhru6x/view?usp=sharing
