// Purpose of this program: Navigate maze and shoot ball.
// Made by: Marco
// made on 3/31/2019
// ----------------------------------------
#include <Sabertooth.h>

int leftIR = 0;
int centerIR = 1;
int rightIR = 2;
int black = 400; // To be determined


// Motor stuff
Sabertooth Drive(128);

void setup() {
  pinMode(leftIR, INPUT);
  pinMode(centerIR, INPUT);
  pinMode(rightIR, INPUT);
  SabertoothTXPinSerial.begin(38400);
  Drive.autobaud();
  Serial.begin(9600);

}

void loop() {
  Serial.print("left:");
  Serial.println(analogRead(leftIR));
  Serial.print("center:");
  Serial.println(analogRead(centerIR));
  Serial.print("right:");
  Serial.println(analogRead(rightIR));
  
  if (analogRead(centerIR) >= black) {
    Drive.motor(1, 32);
    Drive.motor(2, 32);
  }
  if (analogRead(leftIR) >= black) {
    Drive.motor(1, 32);
    Drive.motor(2, 20);
  }
  if (analogRead(rightIR) >= black) {
    Drive.motor(1, 20);
    Drive.motor(2, 32);
  }

  if (analogRead(centerIR) and analogRead(leftIR) and analogRead(rightIR)) {
    Drive.motor(1, -20);
    Drive.motor(2, -20);
  }

}
