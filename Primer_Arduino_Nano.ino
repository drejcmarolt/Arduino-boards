#include "Arduino.h"
#include "Arduino_BHY2.h"

Sensor temp(SENSOR_ID_TEMP);
Sensor baro(SENSOR_ID_BARO);
Sensor hum(SENSOR_ID_HUM);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while(!Serial);

  BHY2.begin();

  temp.begin();
  baro.begin();
  hum.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  static auto printTime = millis();

  BHY2.update();

  if(millis() - printTime >= 1000) {
    printTime = millis();

    if(temp.dataAvailable()) {
      Serial.println(String("Temperatura: ") + String(temp.value(), 3));
      temp.clearDataAvailFlag();

    }
    if(baro.dataAvailable()) {
      Serial.println(String("Barometer: ") + String(baro.value(), 3));
      baro.clearDataAvailFlag();
    }
    if(hum.dataAvailable()) {
      Serial.println(String("Vlaznost: ") + String(hum.value(), 3));
      hum.clearDataAvailFlag();
    }
  }

}
