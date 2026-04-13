#ifndef ATM_H
#define ATM_H

#include <Arduino.h>
#include "../lib/LiquidCrystal_I2C/LiquidCrystal_I2C.h"

class ATM {
private:
    int balance = 1000;
    String input = "";
    bool authenticated = false;
    const String pin = "1234";

public:
    void processInput(char key, LiquidCrystal_I2C &lcd);
};

#endif