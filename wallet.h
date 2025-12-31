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
    /**
     * process the sale of a currency
     * assumes the order was mad by the owner of the wallet
     * @param sale the sale to process
     */
    void process_sale(const order_book_entry &sale);

    std::string to_string();

private:
    std::map<std::string, double> currencies;
};
