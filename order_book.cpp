#include "order_book.h"
#include "csv_reader.h"

order_book::order_book(std::string filename) {
    this->orders= csv_reader::read_csv(filename);
}

std::vector<std::string> order_book::get_known_products() {
    std::vector<std::string> products;
    return products;
}

std::vector<order_book_entry> order_book::get_orders(order_book_type type, std::string product, std::string timestamp) {
    std::vector<order_book_entry> orders;

    return orders;
}
