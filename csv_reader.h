#pragma once
#include <vector>
#include "order_book_entry.h"

class csv_reader {
public:
    csv_reader();

    static std::vector<order_book_entry> read_csv(std::string filename);
    static std::vector<std::string> tokenise(std::string csv_line, char seperator);
    static order_book_entry strings_to_obe(std::string price_, std::string amount_, std::string timestamp_,
                                           std::string product_, order_book_type type_);

private:
    static order_book_entry strings_to_obe(std::vector<std::string> strings);
};
