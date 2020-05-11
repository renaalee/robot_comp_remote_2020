# Milestone 4
> Get the Zumo to navigate a simple maze with no branching (only one path) and stop when it reaches the end goal

## Setup
- I recreated the test maze from tutorial. 

## Programming
- I also left this to be pretty much the same as milestone 2 with minor threshold/speed tweaks, but it worked out just the same. It doesn't recognize when it has reached the end, however. 
- Using the tutorial code, I incorporated the functions to turn left and right: 
```
void turn_left() {
  motors.setSpeeds(-BASE_SPEED, BASE_SPEED);
  linesensors.read(sensor_vals);
  while(sensor_vals[0] > THRESHOLD && sensor_vals[1] > THRESHOLD){
      linesensors.read(sensor_vals);
  }  
}

void turn_right() {
  motors.setSpeeds(BASE_SPEED, -BASE_SPEED);
  linesensors.read(sensor_vals);
  while(sensor_vals[4] > THRESHOLD && sensor_vals[5] > THRESHOLD){
      linesensors.read(sensor_vals);
  }  
}
```
- This made for much sharper turns than before. 

## Milestone Completion
https://drive.google.com/file/d/1OTnBppJsHbp-zZnEWt0c941LcNkHhTzI/view?usp=sharing
