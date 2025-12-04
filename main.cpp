#include <algorithm>
#include <iostream>

int main() {

    while (true) {
        // print help
        std::cout << "1: print help" << std::endl;
        // print exchange stats
        std::cout << "2: print exchange stats" << std::endl;
        // make an offer
        std::cout << "3: make an offer" << std::endl;
        // make a bid
        std::cout << "4: make a bid" << std::endl;
        // print wallet
        std::cout << "5: print wallet" << std::endl;
        // continue
        std::cout << "6: continue" << std::endl;
        std::cout << "============" << std::endl;
        std::cout << "type in 1-6" << std::endl;

        int user_option;
        std::cin >> user_option;
        std::cout << "you chose: " << user_option << std::endl;
        ;

        if (user_option < 1 || user_option > 6) {
            std::cout << "invalid choice. choose 1-6" << std::endl;
        }

        if (user_option == 1) {
            std::cout << "help - your aim is to make money. analyse the market. make bid and offers." << std::endl;
        }

        if (user_option == 2) {
            std::cout << "market looks good" << std::endl;
        }

        if (user_option == 3) {
            std::cout << "make an offer - enter the amount: " << std::endl;
        }

        if (user_option == 4) {
            std::cout << "make a big - enter amount: " << std::endl;
        }

        if (user_option == 5) {
            std::cout << "your wallet is empty" << std::endl;
        }

        if (user_option == 6) {
            std::cout << "going to next timeframe" << std::endl;
        }
    }

    return 0;
}
