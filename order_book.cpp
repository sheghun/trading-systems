#include "order_book.h"
#include <map>
#include "csv_reader.h"

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
        if (e.order_type== type && e.product == product && e.timestamp == timestamp) {
            orders_sub.push_back(e);
        }
    }


    return orders_sub;
}
