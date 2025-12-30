#include <string>
#include <map>

class wallet {
public:
    wallet();
    void insert_currency(std::string type, double amount);
    bool contains_currency(std::string type, double amount);
    std::string to_string();
private:
    std::map<std::string, double> currencies;
};

