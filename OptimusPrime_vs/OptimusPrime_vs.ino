// Purpose of this program: Navigate maze and shoot ball.
// Made by: Marco
// made on 3/31/2019
// ----------------------------------------
#include <Sabertooth.h>

int leftIR = 2;
int centerIR = 1;
int rightIR = 0;

// Different types of black
int BlackL = 640;
int BlackC = 640;
int BlackR = 640;

// SensorVal
int left;
int right;
int center;

// Directive
int dir; // 0 = forward, 1 = left, 2 = right

// Motor stuff
Sabertooth Drive(128);

void setup() {
  pinMode(leftIR, INPUT);
  pinMode(centerIR, INPUT);
  pinMode(rightIR, INPUT);
  SabertoothTXPinSerial.begin(38400);
  Drive.autobaud();
  //Serial.begin(9600);
}

void loop() {
  /*
  Serial.print("left:");
  Serial.println(analogRead(leftIR));
  Serial.print("center:");
  Serial.println(analogRead(centerIR));
  Serial.print("right:");
  Serial.println(analogRead(rightIR));
  */

  
  right = analogRead(rightIR);
  left = analogRead(leftIR);
  center = analogRead(centerIR);
  // 0 = fwd, 1 = left, 2 = right
  if (center > right and center > left) {
    dir = 0;
  }
  if (right > center and right > left) {
    dir = 2;
  }
  if (left > center and left > right) {
    dir = 1;
  }
  
  if (dir == 0) {
    //Serial.println("Center");
    Drive.motor(1, 40);
    Drive.motor(2, 40);
  }
  if (dir == 1) {
    //Serial.println("Left");
    Drive.motor(1, 40);
    Drive.motor(2, -40);
  }
  if (dir == 2) {
    //Serial.println("Right");
    Drive.motor(1, -40);
    Drive.motor(2, 40);
  }

}
