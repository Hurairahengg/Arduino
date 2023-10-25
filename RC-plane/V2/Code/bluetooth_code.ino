#include <Servo.h>

Servo esc;  // Create a Servo object to control the ESC
char command;  // Variable to store the received command

void setup() {
  esc.attach(9); // Attaches the ESC signal wire to pin 9
  Serial.begin(9600);  // Initialize serial communication
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read(); // Read the incoming command
    
    if (command == 'V') {
      esc.writeMicroseconds(2000); // Set ESC to 180 degrees (full throttle)
      Serial.println("ESC set to 180");
    } else if (command == 'v') {
      esc.writeMicroseconds(1000); // Set ESC to 0 degrees (no throttle)
      Serial.println("ESC set to 0");
    }
  }
}
