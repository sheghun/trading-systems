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
    const std::string s = "2020/03/17 17:01:24.884492,btc/usdt,ask,5405.41766912,0.69895055";


    // for (const std::vector<std::string> tokens = tokenise(s, ','); auto &t: tokens) {
    //     std::cout << t << std::endl;
    // }

    std::ifstream csv_file{"20200317.csv"};
    ;

    if (csv_file.is_open()) {
        std::cout << "file opened" << std::endl;
        csv_file.close();
    } else {
        std::cout << "could not open file" << std::endl;
    }

    return 0;
}
