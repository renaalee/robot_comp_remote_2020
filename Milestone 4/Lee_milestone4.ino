// Remote Comp Milestone 3
// Rena A. Lee Spring 2020

#include <Wire.h>
#include <ZumoShield.h>

ZumoReflectanceSensorArray linesensors(QTR_NO_EMITTER_PIN);
ZumoMotors motors;

void setup() {
  int i;
  int spin_direction = 1;
  motors.setSpeeds(100*spin_direction, -100*spin_direction);
  for(i = 0; i<100; i++){
    linesensors.calibrate();
    if(i%50 == 25){ // every 50 loops, starting on loop 25...
      spin_direction = -spin_direction;
      motors.setSpeeds(100*spin_direction, -100*spin_direction);
    }
    delay(20);
  }
  motors.setSpeeds(0,0);
  delay(100);
}

unsigned int sensor_vals[6];
int THRESHOLD = 400;
int BASE_SPEED = 350;
int line_posn;

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

double PROPORTION_GAIN = 0.3;
double DERIVATIVE_GAIN = 3;
int last_error = 0;

void follow_line() {
  int line_posn = linesensors.readLine(sensor_vals);
  int error = line_posn - 2500;
  int delta_e = error - last_error;
  int left_speed = BASE_SPEED + PROPORTION_GAIN*error + DERIVATIVE_GAIN*delta_e;
  int right_speed = BASE_SPEED - PROPORTION_GAIN*error - DERIVATIVE_GAIN*delta_e;
  last_error = error;\
  motors.setSpeeds(left_speed, right_speed);
}


void loop() {
  line_posn = linesensors.readLine(sensor_vals);
  if(sensor_vals[0] > THRESHOLD && sensor_vals[5] > THRESHOLD){
    motors.setSpeeds(0,0); 
    while(true){
      }   
  } else if(sensor_vals[0] > THRESHOLD && sensor_vals[1] > THRESHOLD){
    turn_left();
  } else if(sensor_vals[4] > THRESHOLD && sensor_vals[5] > THRESHOLD){
    turn_right();
  } else {
    follow_line();
  }
}
