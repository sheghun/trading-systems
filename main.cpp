#include <fstream>
#include <iostream>
#include <ostream>

#include "merkel_main.h"

std::vector<std::string> tokenise(std::string csv_line, char seperator) {
    std::vector<std::string> tokens;

    signed int start, end;

    std::string token;

    start = csv_line.find_first_not_of(seperator, 0);

    do {

        end = csv_line.find_first_of(seperator, start);

        if (start == csv_line.length() || start == end)
            break;

        if (end >= 0) {
            token = csv_line.substr(start, end - start);
        } else {
            token = csv_line.substr(start, csv_line.length() - start);
        }

        tokens.push_back(token);
        start = end + 1;

    } while (end != std::string::npos);


    return tokens;
}

int main() {

    // merkel_main app{};
    // app.init();


    std::string line;
    std::ifstream csv_file{"20200317.csv"};

    if (csv_file.is_open()) {
        std::cout << "file opened" << std::endl;
        while (std::getline(csv_file, line)) {
            std::cout << "Read line " << line << std::endl;
            const std::vector<std::string> tokens = tokenise(line, ',');
            if (tokens.size() != 5) {
                std::cout << "Bad line" << std::endl;
                continue;
            }

            try {
                double price = std::stod(tokens[3]);
                double amount = std::stod(tokens[4]);
                std::cout << price << ": " << amount << std::endl;
            } catch (std::exception &e) {
                std::cout << "bad float! " << tokens[3] << std::endl;
                break;
            }


            for (auto &t: tokens) {
                std::cout << t << std::endl;
            }
        }

        csv_file.close();
    } else {
        std::cout << "could not open file" << std::endl;
    }

    return 0;
}
