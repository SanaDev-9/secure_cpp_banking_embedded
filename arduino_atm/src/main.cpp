#include <Arduino.h>
#include "KeypadHandler.h"
#include "LCDHandler.h"
#include "EEPROMHandler.h"

// State machine
enum State { ENTER_PIN, MAIN_MENU, DEPOSIT, WITHDRAW };
State currentState = ENTER_PIN;

void setup() {
    Serial.begin(9600);
    lcdInit();     // Initialize LCD
    keypadInit();  // Initialize Keypad
    lcdPrint("ATM Ready");
}

void loop() {
    switch(currentState) {
        case ENTER_PIN: currentState = enterPinState(); break;
        case MAIN_MENU: currentState = mainMenuState(); break;
        case DEPOSIT: currentState = depositState(); break;
        case WITHDRAW: currentState = withdrawState(); break;
    }
    delay(200);
}


State enterPinState() {
    lcdPrint("Enter PIN:");
    char key = getKeyPressed();
    if(key == 'A'){ // Simulate correct PIN
        return MAIN_MENU;
    }
    return ENTER_PIN;
}

State mainMenuState() {
    lcdPrint("1:Dep 2:With");
    char key = getKeyPressed();
    if(key == '1') return DEPOSIT;
    if(key == '2') return WITHDRAW;
    return MAIN_MENU;
}

State depositState() {
    lcdPrint("Deposit +10");
    int bal = readBalance();
    saveBalance(bal+10);
    return MAIN_MENU;
}

State withdrawState() {
    lcdPrint("Withdraw -10");
    int bal = readBalance();
    saveBalance(bal-10);
    return MAIN_MENU;
}

