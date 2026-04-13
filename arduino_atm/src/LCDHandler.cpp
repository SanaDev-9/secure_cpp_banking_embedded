#include "LCDHandler.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void lcdInit() {
    lcd.init();
    lcd.backlight();
}

void lcdPrint(const char* msg) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(msg);
}