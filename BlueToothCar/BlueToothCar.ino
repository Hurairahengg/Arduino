#include <Servo.h>

Servo servo;

void setup() {
  servo.attach(6);  // Connect the servo to pin 9
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    int facePosition = Serial.parseInt();
    int servoPosition = map(facePosition, 0, 480, 0, 180);  // Adjust mapping range if needed
    servo.write(servoPosition);
  }
}
