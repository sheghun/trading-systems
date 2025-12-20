#pragma once

#include <vector>
#include "csv_reader.h"
#include "order_book_entry.h"

class order_book {
public:
    /** construct reading a csv data file*/
    order_book(std::string filename);
    /* return vector of all know products in the dataset */
    std::vector<std::string> get_known_products();
    /* return vector of orders according to the sent filters*/
    std::vector<order_book_entry> get_orders(order_book_type type, std::string product, std::string timestamp);
};
