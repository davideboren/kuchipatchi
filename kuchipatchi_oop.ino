/*
 * Kuchipatchi
 *
 * Arduino Tamagotchi/Digimon Simulator
 * Using 0.96" OLED Screen
 */

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <EEPROM.h>
#include <vector>

#include "Frame.h"
#include "Defs.h"
#include "Controller.h"
#include "Monster.h"
#include "MoverMon.h"
#include "Sitter.h"
#include "MoveInstruction.h"
#include "Egg.h"
#include "MonsterRef.h"
#include "MonsterDB.h"

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define SSD1306_LCDHEIGHT 64

void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.invertDisplay(true);
  randomSeed(analogRead(0));

  Controller cpu;
  cpu.activate();
}

void loop() {

}
