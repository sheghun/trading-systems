#pragma once
#include <vector>
#include "order_book_entry.h"

class csv_reader {
public:
    csv_reader();

    static std::vector<order_book_entry> read_csv(std::string filename);

private:
    static std::vector<std::string> tokenise(std::string csv_line, char seperator);
    static order_book_entry strings_to_obe(std::vector<std::string> strings);
};
