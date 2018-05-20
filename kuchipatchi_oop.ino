#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <EEPROM.h>

#include "Frame.h"
#include "bitmaps.h"
#include "Controller.h"
#include "Monster.h"
#include "MoverMon.h"

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define SSD1306_LCDHEIGHT 64

void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 
  display.clearDisplay();
  display.invertDisplay(true);

  Monster Kuchipatchi(kuchipatchi1,kuchipatchi2);
  //Frame kuchi(kuchipatchi1,64,32);
  Controller cpu;
  cpu.drawFrame(Kuchipatchi.getFrame());
  display.display();
}

void loop() {

}
