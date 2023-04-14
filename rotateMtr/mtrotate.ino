#include <Servo.h>
#define mt1 13 
#define mt2 12
#define mt3 11
#define mt4 10
int btn1 = 2;
int btn2 = 4;
int btn3 = 7;
int btn4 = 8;
int lstbtnst1 = 0; 
int lstbtnst2 = 0; 
int lstbtnst3 = 0; 
int lstbtnst4 = 0; 
int btnst1 = 0; 
int btnst2 = 0; 
int btnst3 = 0; 
int btnst4 = 0;
int i = 0;
Servo servo;



void setup()
{
  //making the motors output pin
  servo.attach(9);
  pinMode(mt1, OUTPUT); 
  pinMode(mt2, OUTPUT);
  pinMode(mt3, OUTPUT);
  pinMode(mt4, OUTPUT);
  //taking inputs from button
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
   pinMode(btn4, INPUT);
  Serial.begin(9600); //start serial monitor at 9600 baud
 
}

void forward() //making a function for forward
{
    servo.write(90);
    digitalWrite(mt1, HIGH);
    digitalWrite(mt2, HIGH);

}
void noforward() //making a function for no forward
{
    servo.write(90);
    digitalWrite(mt1, LOW);
    digitalWrite(mt2, LOW);

}

void backward() //making a function for backwards
{
    servo.write(90);
    digitalWrite(mt3, HIGH);
    digitalWrite(mt4, HIGH);

}
void nobackward() //making a function for no backwards
{
    servo.write(90);
    digitalWrite(mt3, LOW); 
    digitalWrite(mt4, LOW);

}
void right()
{
    servo.write(0);
    digitalWrite(mt1, HIGH);
    digitalWrite(mt2, HIGH);
}
void left()
{
    servo.write(180);
    digitalWrite(mt1, HIGH);
    digitalWrite(mt2, HIGH);
}

void loop()
{
  //reading the buttons
  btnst1 = digitalRead(btn1);
  btnst2 = digitalRead(btn2);
  btnst3 = digitalRead(btn3);
  btnst4 = digitalRead(btn4);

    if(btnst1 != lstbtnst1){

        if (btnst1 == HIGH) //if high go forward
        {
          forward();
          Serial.println("hello");
        }

        else if (btnst1 == LOW) //if low stop going forward
        {
          noforward();
          Serial.println("hello");
        }

        lstbtnst1 = btnst1;
      
    }

    if(btnst3 != lstbtnst3){

        if (btnst3 == HIGH) //if high go forward
        {
          right();
          Serial.println("hello");
        }

        else{
            noforward();
          Serial.println("hello");
        }

        lstbtnst3 = btnst3;
      
    }

     if(btnst2 != lstbtnst2){ 

        if (btnst2 == HIGH) //if high go backwards
        {
          backward();
          Serial.println("hello");
        }

        else if (btnst2 == LOW) //if low stop going backwards
        {
          nobackward();
          Serial.println("hello");
        }
        lstbtnst2 = btnst2; //remember button state
    }

    if(btnst4 != lstbtnst4){

        if (btnst4 == HIGH) //if high go forward
        {
          left();
          Serial.println("hello");
        }

        else{
            noforward();
          Serial.println("hello");
        }

        lstbtnst4 = btnst4;
      
    }
}