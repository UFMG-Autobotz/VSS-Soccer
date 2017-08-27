#ifndef L298n_h
#define L298n_h

#include "Arduino.h"

class L298n {
public:
	L298n(int ena, int in1, int in2, int in3, int in4, int enb);
	void driveMotors(int speed);
	void setupMotors(int state1, int state2, int state3, int state4);
	void forward(int speed);
	void right(int speed);
	void left(int speed);
	void backward(int speed);
	void brake(int speed);

private:
	struct Motor;
    int _ena;
    int _in1;
    int _in2;
    int _in3;
    int _in4;
    int _enb;
};

#endif