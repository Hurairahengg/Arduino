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

    //printing all the infos on the pins
    Serial.print(" X value = "); //printing for the preview
    Serial.print(xval); //printing the actual value after the preview text
    Serial.print('\n'); //use so no line collides
    Serial.print(" y value = ");
    Serial.print(yval);
    Serial.print('\n');
    Serial.print(" switch is = ");
    Serial.println(sval);
    Serial.print('\n'); //giving line spaces
    Serial.print('\n');
    
    
}
