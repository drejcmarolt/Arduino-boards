#include "Nicla_System.h"
#include "Arduino_BHY2.h"

Sensor temperatura(SENSOR_ID_TEMP);
Sensor barometer(SENSOR_ID_BARO);

void setup() {
  // put your setup code here, to run once:
  nicla::begin();
  nicla::leds.begin();

  Serial.begin(115200);
  BHY2.begin();
  temperatura.begin();
  barometer.begin();



}

void loop() {
  // put your main code here, to run repeatedly:
  nicla::leds.setColor(red);
  delay(1000);
  nicla::leds.setColor(yellow);
  delay(1000);
  nicla::leds.setColor(green);
  delay(10000);
  nicla::leds.setColor(yellow);
  delay(5000);
  nicla::leds.setColor(red);
  delay(10000);
  //nicla::leds.setColor(blue);
  //delay(2000);
  //nicla::leds.setColor(green);
  //delay(5000);
  //nicla::leds.setColor(off);
  //delay(2000);
  //nicla::leds.setColor(yellow);
  //delay(2000);
  //nicla::leds.setColor(magenta);
  //delay(2000);
  //nicla::leds.setColor(cyan);
  //delay(2000);
  //nicla::leds.setColor(off);
  //delay(5000);

  static auto lastCheck = millis();
  BHY2.update();

  if (millis() - lastCheck >= 1000) {
    lastCheck = millis();
    Serial.println(String("Temperatura: ") + String(int(temperatura.value())));
    Serial.println(String("Barometer: ") + barometer.toString());
  }

}
