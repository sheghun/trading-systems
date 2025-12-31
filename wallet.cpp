#include "wallet.h"
#include <stdexcept>

#include "csv_reader.h"

wallet::wallet() {}

void wallet::insert_currency(std::string type, double amount) {
    double balance;
    if (amount < 0) {
        throw std::invalid_argument("Amount cannot be negative");
    }
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
        throw std::invalid_argument("Amount cannot be negative");
        return false;
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

void wallet::process_sale(const order_book_entry &sale) {
    std::vector<std::string> currs = csv_reader::tokenise(sale.product, '/');
    if (sale.order_type == order_book_type::asksale) {
        double outgoing_amount = sale.amount;
        std::string outgoing_currency = currs[0];
        double incoming_amount = sale.amount * sale.price;
        std::string incoming_currency = currs[1];

        currencies[incoming_currency] += incoming_amount;
        currencies[outgoing_currency] -= outgoing_amount;
    }
    if (sale.order_type == order_book_type::bidsale) {
        double outgoing_amount = sale.amount * sale.price;
        double incoming_amount = sale.amount;
        std::string outgoing_currency = currs[1];
        std::string incoming_currency = currs[0];
        currencies[incoming_currency] += incoming_amount;
        currencies[outgoing_currency] -= outgoing_amount;
    }
}
