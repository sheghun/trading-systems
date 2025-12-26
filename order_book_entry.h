#pragma once
#include <string>

enum class order_book_type { bid, ask, unknown };
// class definition
class order_book_entry {

public:
    double price;
    double amount;
    std::string timestamp;
    std::string product;
    order_book_type order_type;

    order_book_entry(double _price, double _amount, std::string _timestamp, std::string _product,
                     order_book_type _order_type);
    static order_book_type string_to_order_book_type(std::string s);
    static bool compare_by_timestamp(order_book_entry &e1, order_book_entry &e2) {
        return e1.timestamp < e2.timestamp;
    }
};
