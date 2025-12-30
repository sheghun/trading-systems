#include "wallet.h"
#include <iostream>

wallet::wallet() {}

void wallet::insert_currency(std::string type, double amount) {
    double balance;
    if (!this->currencies.contains(type)) {
        balance = 0;
    } else {
        balance = this->currencies[type];
    }
    balance += amount;
    this->currencies[type] = balance;
}

bool wallet::contains_currency(std::string type, double amount) {
    if (!this->currencies.contains(type)) {
        return false;
    } else {
        return this->currencies[type] >= amount;
    }
}

std::string wallet::to_string() { return ""; }
