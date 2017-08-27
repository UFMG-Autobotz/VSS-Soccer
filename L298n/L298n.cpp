#include "L298n.h"
#include "Arduino.h"

//structure of a motor
struct Motor {
  int in1;
  int in2;
  int pwm;
};

Motor motors[1];

L298n::L298n(int ena, int in1, int in2, int in3, int in4, int enb) {

  pinMode (ena, OUTPUT);
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);
  pinMode (enb, OUTPUT);

  motors[0].in1 = in1;
  motors[0].in2 = in2;
  motors[0].pwm = ena;

  motors[1].in1 = in3;
  motors[1].in2 = in4;
  motors[1].pwm = enb;

}

void L298n::driveMotors(int speed) {
  analogWrite(motor[0].pwm, speed);
  analogWrite(motor[1].pwm, speed)
}

void L298n::setupMotors(int state1, int state2, int state3, int state4) {
  digitalWrite(motors[0].in1, state1);
  digitalWrite(motors[0].in2, state2);
  digitalWrite(motors[1].in3, state3);
  digitalWrite(motors[1].in4, state4);
}

void L298n::forward(int speed) {
  this->setupMotors(HIGH, LOW, HIGH, LOW);
  this->driveMotors(speed);
}

void L298n::right(int speed) {
  this->setupMotors(LOW, HIGH, HIGH, LOW);
  this->driveMotors(speed)
}

void L298n::left(int speed) {
  this->setupMotors(HIGH, LOW, LOW, HIGH)
  this->driveMotors(speed);
}

void L298n::backward(int speed) {
  this->setupMotors(LOW, HIGH, LOW, HIGH);
  this->driveMotors(speed);
}

void L298n::brake (void) {
  this->setupMotors(LOW, LOW, LOW, LOW);
  this->driveMotors(0);
}

