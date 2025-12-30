#pragma once
#include <map>
#include <string>
#include "order_book_entry.h"

class wallet {
public:
    wallet();
    void insert_currency(std::string type, double amount);
    bool remove_currency(std::string type, double amount);
    bool contains_currency(std::string type, double amount);
    bool can_fulfill_order(const order_book_entry &order);

    std::string to_string();

private:
    std::map<std::string, double> currencies;
};
