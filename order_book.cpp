#include <algorithm>
#include <iostream>
#include <map>

#include "csv_reader.h"
#include "order_book.h"

order_book::order_book(std::string filename) { this->orders = csv_reader::read_csv(filename); }

std::vector<std::string> order_book::get_known_products() {
    std::vector<std::string> products;
    std::map<std::string, bool> product_map;

    for (order_book_entry &obe: orders) {
        product_map[obe.product] = true;
    }

    for (auto const &p: product_map) {
        products.push_back(p.first);
    }

    return products;
}

std::vector<order_book_entry> order_book::get_orders(order_book_type type, std::string product, std::string timestamp) {
    std::vector<order_book_entry> orders_sub;

    for (order_book_entry &e: orders) {
        if (e.order_type == type && e.product == product && e.timestamp == timestamp) {
            orders_sub.push_back(e);
        }
    }


    return orders_sub;
}

double order_book::get_highest_price(std::vector<order_book_entry> const &orders) {

    if (orders.empty()) {
        return 0.0f;
    }

    double max = orders[0].price;
    for (order_book_entry const &e: orders) {
        if (e.price > max) {
            max = e.price;
        }
    }

    return max;
}

double order_book::get_lowest_price(std::vector<order_book_entry> const &orders) {
    if (orders.empty()) {
        return 0.0f;
    }

    double min = orders[0].price;
    for (order_book_entry const &e: orders) {
        if (e.price < min) {
            min = e.price;
        }
    }

    return min;
}

std::string order_book::get_earliest_time() { return this->orders[0].timestamp; }

std::string order_book::get_next_time(std::string timestamp) {
    std::string next_timestamp;

    for (order_book_entry const &e: orders) {
        if (e.timestamp > timestamp) {
            next_timestamp = e.timestamp;
            break;
        }
    }

    if (next_timestamp.empty()) {
        next_timestamp = orders[0].timestamp;
    }


    return next_timestamp;
}

void order_book::insert_order(order_book_entry &order) {
    orders.push_back(order);
    std::sort(orders.begin(), orders.end(), order_book_entry::compare_by_timestamp);
}

std::vector<order_book_entry> order_book::match_asks_to_bids(const std::string &product, const std::string &timestamp) {
    std::vector<order_book_entry> asks = this->get_orders(order_book_type::ask, product, timestamp);
    std::vector<order_book_entry> bids = this->get_orders(order_book_type::bid, product, timestamp);

    std::vector<order_book_entry> sales;

    std::ranges::sort(asks, order_book_entry::compare_by_price_asc);
    std::ranges::sort(bids, order_book_entry::compare_by_price_desc);

    for (order_book_entry &ask: asks) {
        for (order_book_entry &bid: bids) {
            if (bid.price >= ask.price) {
                order_book_entry sale{ask.price, 0, timestamp, product, order_book_type::sale};
                if (bid.amount == ask.amount) {
                    sale.amount = ask.amount;
                    sales.push_back(sale);
                    bid.amount = 0;
                    break;
                }
                if (bid.amount > ask.amount) {
                    sale.amount = ask.amount;
                    sales.push_back(sale);
                    bid.amount -= ask.amount;
                    break;
                }
                if (bid.amount < ask.amount) {
                    sale.amount = bid.amount;
                    sales.push_back(sale);
                    ask.amount -= bid.amount;
                    bid.amount = 0;
                    continue;
                }
            }
        }
    }
    return sales;
}
