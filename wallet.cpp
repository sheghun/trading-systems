#include "wallet.h"
#include <iostream>

#include "csv_reader.h"

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

bool wallet::can_fulfill_order(const order_book_entry &order) {
    std::vector<std::string> currs = csv_reader::tokenise(order.product, '/');
    // ask
    if (order.order_type == order_book_type::ask) {
        const double amount = order.amount;
        const std::string currency = currs[0];
        return this->contains_currency(currency, amount);
    }

    // bid
    if (order.order_type == order_book_type::bid) {
        const double amount = order.amount * order.price;
        const std::string currency = currs[1];
        return this->contains_currency(currency, amount);
    }
    return false;
}
