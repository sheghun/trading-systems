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

bool wallet::remove_currency(std::string type, double amount) {
    double balance;
    if (amount < 0) {
        throw new std::exception{};
    }

    if (currencies.count(type) == 0) {
        return false;
    }

    if (this->contains_currency(type, amount)) {
        this->currencies[type] -= amount;
        return true;
    }

    return false;
}

bool wallet::contains_currency(std::string type, double amount) {
    if (!this->currencies.contains(type)) {
        return false;
    } else {
        return this->currencies[type] >= amount;
    }
}

std::string wallet::to_string() {
    std::string s;
    for (std::pair<std::string, double> pair: currencies) {
        std::string currency = pair.first;
        double amount = pair.second;
        s += currency + " : " + std::to_string(amount) + "\n";
    }

    return s;
}
