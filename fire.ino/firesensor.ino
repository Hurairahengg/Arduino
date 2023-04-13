int led = 6; //led pin
int fire = 7; //sensor pin
int state = 0;



void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT); 
  pinMode(fire, INPUT); //read the sensor
}

void loop() {
  state = digitalRead(fire); //reciving the state

  if(state == HIGH) //if the state is high
  {
      digitalWrite(led, HIGH); //turn on led
      Serial.println("FIRE"); 

  }else{ //if state is low

    Serial.println("Peace");
    digitalWrite(led, LOW); //turn led off

  }

}
