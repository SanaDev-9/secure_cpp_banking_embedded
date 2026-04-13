#include "ATM.h"

void ATM::processInput(char key, LiquidCrystal_I2C &lcd) {

    if (!authenticated) {
        input += key;

        lcd.clear();
        lcd.print("PIN: ");
        lcd.print(input);

        if (input.length() == 4) {
            if (input == pin) {
                authenticated = true;
                lcd.clear();
                lcd.print("Access Granted");
            } else {
                lcd.clear();
                lcd.print("Wrong PIN");
            }
            delay(2000);
            input = "";
            lcd.clear();
        }
        return;
    }

    // After login
    if (key == 'A') {
        lcd.clear();
        lcd.print("Balance:");
        lcd.setCursor(0,1);
        lcd.print(balance);
    }

    if (key == 'B') {
        balance -= 100;
        lcd.clear();
        lcd.print("Withdraw 100");
    }

    if (key == 'C') {
        balance += 100;
        lcd.clear();
        lcd.print("Deposit 100");
    }

    delay(1000);
    lcd.clear();
}