#include <iostream>
#include "csv_reader.h"


csv_reader::csv_reader() {}

std::vector<order_book_entry> csv_reader::read_csv(std::string filename) {
    std::vector<order_book_entry> entries;

    return entries;
}

std::vector<std::string> csv_reader::tokenise(std::string csv_line, char seperator) {
    std::vector<std::string> tokens;

    return tokens;
}

order_book_entry csv_reader::strings_to_obe(std::vector<std::string> tokens) {
    double price, amount;


    if (tokens.size() != 5) {
        std::cout << "bad line " << std::endl;
        throw std::exception{};
    }

    try {
        price = std::stod(tokens[3]);
        amount = std::stod(tokens[4]);
    } catch (std::exception &e) {
        std::cout << "bad float! " << tokens[3] << std::endl;
        std::cout << "bad float! " << tokens[4] << std::endl;
        throw;
    }


    order_book_entry obe{price, amount, tokens[0], tokens[1], order_book_entry::string_to_order_book_type(tokens[2])};

    return obe;
}
