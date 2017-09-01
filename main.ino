#include "Adafruit_VL53L0X.h"

#define DEBUG true

Adafruit_VL53L0X tof1 = Adafruit_VL53L0X();
auto tof2 = Adafruit_VL53L0X();
auto tof3 = Adafruit_VL53L0X();
auto tof4 = Adafruit_VL53L0X();
auto tof5 = Adafruit_VL53L0X();

int xshut[5] = {0,3,5,7,9};
int gpio1[5] = {3,6,8,10,12};
int tofaddress[5] = {0x1,0x2,0x3,0x4,0x5};

Adafruit_VL53L0X tof[5];

void setup() {
  Serial.begin(115200);

  // wait until serial port opens for native USB devices
  while (! Serial) {
    delay(1);
    }

//  
//  Serial.println("Adafruit VL53L0X test");
////  if (!lox.begin()) {
////    Serial.println(F("Failed to boot VL53L0X"));
////    while(1);
////  }
//  // power 
//  Serial.println(F("VL53L0X API Simple Ranging example\n\n")); 

  for (auto i : xshut)
    pinMode(xshut[i], OUTPUT);

  for (auto i : gpio1)
    pinMode(gpio1[i], INPUT);
  
  for (int i =0;i<5;i++)
  {
    tof[i] = Adafruit_VL53L0X();
    tof[i].begin(tofaddress[i], DEBUG);
  }


  
}


void loop() {

  VL53L0X_RangingMeasurementData_t measure[5];

  for(int i=0;i<5;i++)
  {
    tof[i].rangingTest(&measure[i], DEBUG);
    if (measure[i].RangeStatus !=4) 
    {
      Serial.print("Distance (mm): ");
    }
    else
      Serial.println(" out of range ");
  } 
//  VL53L0X_RangingMeasurementData_t measure;
//    
//  Serial.print("Reading a measurement... ");
//  lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!
//
//  if (measure.RangeStatus != 4) {  // phase failures have incorrect data
//    Serial.print("Distance (mm): "); Serial.println(measure.RangeMilliMeter);
//  } else {
//    Serial.println(" out of range ");
//  }
//    
//  delay(100);
}
