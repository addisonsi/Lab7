/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/addisonsimon/Lab7/src/Lab7.ino"
#include <blynk.h>
#include "oled-wing-adafruit.h"
/*
 * Project Lab_6
 * Description:
 * Author:
 * Date:
 */
void setup();
void loop();
#line 9 "/Users/addisonsimon/Lab7/src/Lab7.ino"
SYSTEM_THREAD(ENABLED);
// setup() runs once, when the device is first turned on.
OledWingAdafruit display;
void setup() {
  // Put initialization like pinMode and begin functions here.
  Blynk.begin("zz-BBGrJF91ILuXaXf63tZIuaalnNeem", IPAddress(167, 172, 234, 162), 9090);
  display.setup();
  display.clearDisplay();
  display.display();  // cause the display to be updated
  pinMode(A0, INPUT);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
  Blynk.run();
  display.clearDisplay();
  display.loop();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);

  double voltage = (analogRead(A0) * 3.3) / 4095.0;
  double temperature = (voltage - 0.5) * 100;
  if(display.pressedA()){
    Blynk.notify("Hey, got a push notification!");
    display.println("Push sent");
    display.display();
    delay(5000);
  }
  display.clearDisplay();
  display.print("The temperature is ");
  display.print((int)(temperature+0.5));
  display.println(" in Celsius");
  display.print("The temperature is ");
  display.print((int)(temperature*9/5 + 32 + 0.5));
  display.println(" in Farenheit");
  display.display();
  delay(100);
}