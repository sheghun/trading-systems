#pragma once
#include <string>

enum class order_book_type { bid, ask, sale, unknown, bidsale, asksale };
// class definition
class order_book_entry {

public:
    double price;
    double amount;
    std::string timestamp;
    std::string product;
    order_book_type order_type;
    std::string username;

    order_book_entry(double _price, double _amount, std::string _timestamp, std::string _product,
                     order_book_type _order_type, std::string _username = "dataset");
    static order_book_type string_to_order_book_type(std::string s);
    static bool compare_by_timestamp(order_book_entry &e1, order_book_entry &e2) { return e1.timestamp < e2.timestamp; }
    static bool compare_by_price_asc(const order_book_entry &e1, const order_book_entry &e2) {
        return e1.price < e2.price;
    }
    static bool compare_by_price_desc(const order_book_entry &e1, const order_book_entry &e2) {
        return e1.price > e2.price;
    }
};
