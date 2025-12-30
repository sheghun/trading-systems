#include <iostream>
#include "merkel_main.h"
#include "wallet.h"


int main() {

    // merkel_main app{};
    // app.init();

    wallet wallet{};
    wallet.insert_currency("BTC", 10);
    std::cout << "wallet has BTC " << wallet.contains_currency("BTC", 5) << std::endl;
    std::cout << wallet.to_string() << std::endl;
}
