#include "merkel_main.h"
#include <iostream>
#include <map>
#include <vector>


merkel_main::merkel_main() {}

void merkel_main::init() {
    int input;
    while (true) {
        print_menu();
        input = get_user_option();
        process_user_option(input);
    }
}

void merkel_main::print_menu() {
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

void merkel_main::print_help() { std::cout << "invalid choice. choose 1-6" << std::endl; }

void merkel_main::print_exchange_stats() { std::cout << "market looks good" << std::endl; }

void merkel_main::enter_bid() { std::cout << "make a bid - enter the amount: " << std::endl; }

void merkel_main::enter_offer() { std::cout << "make an offer - enter the amount: " << std::endl; }

void merkel_main::print_wallet() { std::cout << "your wallet is empty" << std::endl; }

void merkel_main::next_timeframe() { std::cout << "going to next timeframe" << std::endl; }

int merkel_main::get_user_option() {
    int user_option;

    std::cout << "type in 1-6" << std::endl;
    std::cin >> user_option;
    std::cout << "you chose: " << user_option << std::endl;

    return user_option;
}

void merkel_main::process_user_option(int user_option) {

    std::map<int, void (merkel_main::*)()> menu;

    menu[1] = &merkel_main::print_help;
    menu[2] = &merkel_main::print_exchange_stats;
    menu[3] = &merkel_main::enter_offer;
    menu[4] = &merkel_main::enter_bid;
    menu[5] = &merkel_main::print_wallet;
    menu[6] = &merkel_main::next_timeframe;


    if (user_option < 1 || user_option > 6) {
        std::cout << "invalid choice. choose 1-6" << std::endl;
        return;
    }

    (this->*menu.at(user_option))();
}

void merkel_main::load_order_book() {

    orders.push_back(order_book_entry{
            5319.450228,
            0.00020075,
            "2020/03/17 17:01:24.884492",
            "BTC/USDT",
            order_book_type::bid,
    });
}

void merkel_main::print_market_stats() {
    std::cout << "order book contains: " << orders.size() << " entries" << std::endl;
}
