#include <cvzone.h>

SerialData sdata(1,1);
int valrec[1];

void setup() {
  sdata.begin(9600);
  pinMode(13, OUTPUT);

}

void loop() {

  sdata.Get(valrec);
  digitalWrite(13, valrec[0]);

}
