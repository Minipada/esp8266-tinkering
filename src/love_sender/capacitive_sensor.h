#include <CapacitiveSensor.h>

// With a NodeMCU, need a 180K resistor between send and receive pins
#define CALIBRATION_MEASUREMENTS 30

void setup_cs(CapacitiveSensor& cs){
  cs.set_CS_AutocaL_Millis(0xFFFFFFFF);
}

bool get_cs_status(CapacitiveSensor& cs, int non_active_value){
  long start = millis();
  long total =  cs.capacitiveSensor(30);
  Serial.println(total);
  if (total > (non_active_value)){
    return true;
  }
  return false;
}

int sensor_calibration(CapacitiveSensor& cs){
  int max = 0;
  
  for (int i = 0; i < CALIBRATION_MEASUREMENTS; i++){
    if (cs.capacitiveSensor(30) > max) {
      max = cs.capacitiveSensor(30);
    }
    
    delay(10);
  }
  Serial.print("Sensor: ");
  Serial.println(max);
  return max;
}

