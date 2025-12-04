#include <algorithm>
#include <iostream>
#include <map>

void print_menu() {
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
}

void print_help() { std::cout << "invalid choice. choose 1-6" << std::endl; }

void print_exchange_stats() { std::cout << "market looks good" << std::endl; }

void enter_bid() { std::cout << "make a bid - enter the amount: " << std::endl; }

void enter_offer() { std::cout << "make an offer - enter the amount: " << std::endl; }

void print_wallet() { std::cout << "your wallet is empty" << std::endl; }

void next_timeframe() { std::cout << "going to next timeframe" << std::endl; }

int get_user_option() {
    int user_option;

    std::cout << "type in 1-6" << std::endl;
    std::cin >> user_option;
    std::cout << "you chose: " << user_option << std::endl;

    return user_option;
}

void process_user_option(int user_option) {

    std::map<int, void (*)()> menu;

    menu[1] = print_help;
    menu[2] = print_exchange_stats;
    menu[3] = enter_offer;
    menu[4] = enter_bid;
    menu[5] = print_wallet;
    menu[6] = next_timeframe;


    if (user_option < 1 || user_option > 6) {
        std::cout << "invalid choice. choose 1-6" << std::endl;
        return;
    }

    menu.at(user_option)();
}

[[noreturn]] int main() {

    while (true) {
        print_menu();
        int user_option{get_user_option()};
        process_user_option(user_option);
    }
}
