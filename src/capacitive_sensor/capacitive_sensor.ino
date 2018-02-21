#include <CapacitiveSensor.h>

// With a NodeMCU, need a 180K resistor between send and receive pins

CapacitiveSensor   cs_4_5 = CapacitiveSensor(4,5);

void setup()                    
{
   cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);
   Serial.begin(115200);
}

void loop()                    
{
    long start = millis();
    long total1 =  cs_4_5.capacitiveSensor(30);


    Serial.print(millis() - start);        // check on performance in milliseconds
    Serial.print("\t");                    // tab character for debug windown spacing

    Serial.print(total1);                  // print sensor output 1
    Serial.println();                      // default value for y setup is 270, and more than 280 when your hand is 1-3cm close to the box

    delay(10);                             // arbitrary delay to limit data to serial port    
}
