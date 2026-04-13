#include "EEPROMHandler.h"
#include <EEPROM.h>

int balanceAddress = 0;

void saveBalance(int balance) {
    EEPROM.put(balanceAddress, balance);
}

int readBalance() {
    int balance;
    EEPROM.get(balanceAddress, balance);
    return balance;
}