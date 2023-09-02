#include <AFMotor.h>

AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(4, MOTOR12_1KHZ); 
AF_DCMotor motor3(2, MOTOR34_1KHZ);
AF_DCMotor motor4(3, MOTOR34_1KHZ);
int leftC = 0;
int rightC = 0;
int backC = 0;



char command; 
void setup() {
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.print(digitalRead(2));
  
  if(digitalRead(2) == LOW) {
    forward();
    
    rightC = 0;
    leftC = 0;
  } else {
    if(leftC <= 100) {
      left();
      leftC++;
    } else if(rightC <= 220) {
      right();
      rightC++;
    } else if (rightC >= 220 && leftC >= 100){
      if(digitalRead(2) == HIGH) {
        if(leftC <= 500) {
          left();
          leftC++;
        }else if(rightC <= 1060) {
          right();
          rightC++;
        } else if (rightC >= 1060 && leftC >= 500){ 
          if(digitalRead(2) == HIGH) {
            if(leftC <= 1900) {
              left();
              leftC++;
            }else if(rightC <= 3800) {
              right();
              rightC++; 
              }
              else if (leftC >= 1900 && rightC >= 3800)
              {
                if(rightC == 3800 && backC <= 3800)  
                {
                  left();
                  backC++;  
                }
                else if(backC >= 3800)
                {
                  forward();
                }
              }
          }
      } else if (digitalRead(2) == LOW){
        rightC = 0;
        leftC = 0;
      }
    }
  }
}
}

void forward()
{
  motor1.setSpeed(255); 
  motor1.run(FORWARD);
  motor2.setSpeed(255); 
  motor2.run(FORWARD); 
  motor3.setSpeed(255);
  motor3.run(FORWARD); 
  motor4.setSpeed(255);
  motor4.run(FORWARD); 
}

void back()
{
  motor1.setSpeed(255);
  motor1.run(BACKWARD);
  motor2.setSpeed(255);
  motor2.run(BACKWARD);
  motor3.setSpeed(255); 
  motor3.run(BACKWARD); 
  motor4.setSpeed(255); 
  motor4.run(BACKWARD);
}

void left()
{
  motor1.setSpeed(255); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(255); 
  motor2.run(BACKWARD);
  motor3.setSpeed(255); 
  motor3.run(FORWARD);  
  motor4.setSpeed(255); 
  motor4.run(FORWARD);  
}

void right()
{
  motor1.setSpeed(255);
  motor1.run(FORWARD); 
  motor2.setSpeed(255); 
  motor2.run(FORWARD); 
  motor3.setSpeed(255);
  motor3.run(BACKWARD); 
  motor4.setSpeed(255); 
  motor4.run(BACKWARD); 
}

void Stop()
{
  motor1.setSpeed(0); 
  motor1.run(RELEASE); 
  motor2.setSpeed(0);
  motor2.run(RELEASE); 
  motor3.setSpeed(0); 
  motor3.run(RELEASE); 
  motor4.setSpeed(0); 
  motor4.run(RELEASE); 
}
