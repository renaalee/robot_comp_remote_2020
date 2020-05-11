// Remote Comp Milestone 3
// Rena A. Lee Spring 2020

#include <Wire.h>
#include <ZumoShield.h>

ZumoReflectanceSensorArray linesensors(QTR_NO_EMITTER_PIN);
ZumoMotors motors;

void setup() {
  int i;
  int spin_direction = 1;
  motors.setSpeeds(90*spin_direction, -90*spin_direction);
  for(i = 0; i<100; i++){
    linesensors.calibrate();
    if(i%50 == 25){ // every 50 loops, starting on loop 25...
      spin_direction = -spin_direction;
      motors.setSpeeds(90*spin_direction, -90*spin_direction);
    }
    delay(20);
  }
  motors.setSpeeds(0,0);
  delay(300);
}

unsigned int sensor_vals[6];
int BASE_SPEED = 300;
double PROPORTION_GAIN = 0.3;
double DERIVATIVE_GAIN = 3;
int last_error = 0;

void loop() {
  int line_posn = linesensors.readLine(sensor_vals);
  Serial.println(line_posn) // to check on line reading from sensors
  int error = line_posn - 2500;
  int delta_e = error - last_error;
  int left_speed = BASE_SPEED + PROPORTION_GAIN*error + DERIVATIVE_GAIN*delta_e;
  int right_speed = BASE_SPEED + -PROPORTION_GAIN*error + -DERIVATIVE_GAIN*delta_e;
  last_error = error;\
  motors.setSpeeds(left_speed, right_speed);
}
