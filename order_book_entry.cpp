#include "order_book_entry.h"

order_book_entry::order_book_entry(double _price, double _amount, std::string _timestamp, std::string _product,
                                   order_book_type _order_type) :
    price(_price), amount(_amount), timestamp(_timestamp), product(_product), order_type(_order_type) {}
