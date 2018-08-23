#include "Si7021_teensy.h"

SI7021 si7021;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  si7021.begin(); // Runs : Wire.begin() + reset()
  while(!Serial);
}

void loop() {
  // put your main code here, to run repeatedly:
  float temp=si7021.readTemp();
  if(temp==255.0){
    Serial.println("An error occured");
  }
  else{
    Serial.println(temp);
  }
  delay(50);
}
