#include <blynk.h>
#include "oled-wing-adafruit.h"

SYSTEM_THREAD(ENABLED);

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