//all the variable needed:
int x = A0;
int y = A1;
int sv = 7;
int xval;
int yval;
int sval;


void setup() {

  Serial.begin(9600);//starting the serial monitor at 9600baud

  //taking input for the pins
  pinMode(x, INPUT);
  pinMode(y, INPUT);
  pinMode(sv, INPUT);

}

void loop() {

  //taking al the values from the pins and storing them
  xval = analogRead(x);
  yval = analogRead(y);
  sval = digitalRead(sv);

    Serial.print("X Value is:");
    Serial.println(xval);
    Serial.print("Y Value is: ");
    Serial.println(yval);
    Serial.print("X Value is:");
    Serial.println(xval);
    Serial.println(\n\n);
    
  }
}
