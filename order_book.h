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

    /** returns the earliest time in the order book*/
    std::string get_earliest_time();

    /** returns the next time after the sent time in the orderbook
     * if there is not timestamp, wraps around to the start
     */
    std::string get_next_time(std::string timestamp);

    void insert_order(order_book_entry &order);

    static double get_highest_price(std::vector<order_book_entry> const &orders);
    static double get_lowest_price(std::vector<order_book_entry> const &orders);

private:
    std::vector<order_book_entry> orders;
};
