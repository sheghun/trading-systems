#include <exception>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

class ring_location {
public:
    ring_location(double _x, double _y, std::string _responsible_department, std::string _data_source) :
        x(_x), y(_y), responsible_department(std::move(_responsible_department)), data_source(std::move(_data_source)) {
    }

    double x, y;
    std::string responsible_department;
    std::string data_source;

    void print() {
        std::cout << "lat: " << x << " lon: " << y;
        std::cout << " data source: " << data_source;
        std::cout << " responsible department: " << responsible_department << std::endl;
    }
};

std::vector<std::string> tokenise(std::string const &csv_line, std::string separator) {
    std::vector<std::string> tokens;

    int end;
    int start = csv_line.find_first_not_of(separator, 0);
    do {
        end = csv_line.find_first_of(separator, start);
        if (start == csv_line.length() || start == end)
            break;
        if (end >= 0) {
            tokens.push_back(csv_line.substr(start, end - start));
        } else {
            tokens.push_back(csv_line.substr(start, csv_line.length() - start));
        }
        start = end + 1;

    } while (end != std::string::npos);

    return tokens;
}


int main() {
    std::ifstream csv_file{"ring_locations.csv"};


    if (csv_file.is_open()) {
        int i = 0;
        std::vector<ring_location> ring_locations;

        std::string line;
        // start reading from file
        while (std::getline(csv_file, line)) {
            try {
                i++;
                auto tokens = tokenise(line, ",");

                if (tokens.size() != 14) {
                    continue;
                }

                double x = std::stod(tokens[0]);
                double y = std::stod(tokens[1]);

                ring_location r_l{x, y, tokens[11], tokens[10]};
                r_l.print();

                ring_locations.push_back(r_l);
            } catch (std::exception const &e) {
                continue;
            }
        };
        std::cout << "" << ring_locations.size() << " valid out of " << i << std::endl;

    } else {
        std::cout << "file not opened" << std::endl;
    }
}
