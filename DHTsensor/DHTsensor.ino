#include <dht11.h> //INCLUDE LIBRARY
#define DHT11PIN 4 //define the sensor pin

dht11 DHT11;

void  setup()
{
  Serial.begin(9600); //start the serial monitor at 9600 baud
  pinMode(8, HIGH);
  pinMode(9, HIGH); //pinmode make the led OUTPUT pins
  pinMode(12, HIGH);
 
}

void loop()
{
  Serial.println(); //make space                                                                    

  int chk = DHT11.read(DHT11PIN); //reads the sensor pin

  Serial.print("Humidity (%): ");
  Serial.println((float)DHT11.humidity, 2); //prints the humidity

  Serial.print("Temperature  (C): ");
  Serial.println((float)DHT11.temperature, 2); //prints the temp

  if((float)DHT11.temperature >= 29.00){ //if it gets hot turn on red LED
    digitalWrite(8, HIGH);                                                        
  }else if((float)DHT11.temperature >= 26.00){ //if its normal turn on red LED                                                                                                                                                                                 
    digitalWrite(9, HIGH);                                                                                                                                                             
  }else if ((float)DHT11.temperature <= 25.00){ //if it gets cold turn on red LED
    digitalWrite(10, HIGH);  
  }

  delay(2000);

}