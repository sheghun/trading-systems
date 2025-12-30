#include "merkel_main.h"
#include <iostream>
#include <limits>
#include <map>
#include <vector>

#include "csv_reader.h"


merkel_main::merkel_main() {}

void merkel_main::init() {
    int input;
    current_time = this->_order_book.get_earliest_time();


    _wallet.insert_currency("BTC", 10);

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
    std::cout << "3: enter ask" << std::endl;
    // make a bid
    std::cout << "4: enter bid" << std::endl;
    // print wallet
    std::cout << "5: print wallet" << std::endl;
    // continue
    std::cout << "6: continue" << std::endl;

    std::cout << "============" << std::endl;

    std::cout << "current time is: " << current_time << std::endl;
}

void merkel_main::print_help() { std::cout << "invalid choice. choose 1-6" << std::endl; }

void merkel_main::print_exchange_stats() { std::cout << "market looks good" << std::endl; }

void merkel_main::enter_bid() {
    std::cout << "enter bid - enter the amount: product,price,amount e.g ETH/BTC,200,0.5" << std::endl;
    std::string input;
    std::getline(std::cin, input);

    std::vector<std::string> tokens = csv_reader::tokenise(input, ',');
    if (tokens.size() != 3) {

        std::cout << "merkel_main::enter_bid bad input! " << input << std::endl;

    } else {
        try {

            order_book_entry obe =
                    csv_reader::strings_to_obe(tokens[1], tokens[2], current_time, tokens[0], order_book_type::bid);
            if (this->_wallet.can_fulfill_order(obe)) {
                std::cout << "wallet looks good. " << std::endl;
                this->_order_book.insert_order(obe);
            } else {
                std::cout << "wallet has insufficient funds " << std::endl;
            }
        } catch (const std::exception &e) {
            std::cout << "merkel_main::enter_bid bad input! " << input << std::endl;
        }
    }

    std::cout << "you typed: " << input << "\n" << std::endl;
}

void merkel_main::enter_ask() {
    std::cout << "enter ask - enter the amount: product,price,amount e.g ETH/BTC,200,0.5" << std::endl;
    std::string input;
    std::getline(std::cin, input);

    std::vector<std::string> tokens = csv_reader::tokenise(input, ',');
    if (tokens.size() != 3) {

        std::cout << "merkel_main::enter_ask bad input! " << input << std::endl;

    } else {
        try {

            order_book_entry obe =
                    csv_reader::strings_to_obe(tokens[1], tokens[2], current_time, tokens[0], order_book_type::ask);
            if (this->_wallet.can_fulfill_order(obe)) {
                std::cout << "wallet looks good. " << std::endl;
                this->_order_book.insert_order(obe);
            } else {
                std::cout << "wallet has insufficient funds " << std::endl;
            }
        } catch (const std::exception &e) {
            std::cout << "merkel_main::enter_ask bad input! " << input << std::endl;
        }
    }

    std::cout << "you typed: " << input << "\n" << std::endl;
}

void merkel_main::print_wallet() { std::cout << _wallet.to_string() << std::endl; }

void merkel_main::next_timeframe() {
    std::cout << "going to next timeframe" << std::endl;
    std::vector<order_book_entry> sales = _order_book.match_asks_to_bids("ETH/BTC", current_time);
    std::cout << "sales: " << sales.size() << std::endl;
    for (const order_book_entry &sale: sales) {
        std::cout << "sale price: " << sale.price << " amount: " << sale.amount << std::endl;
    }
    current_time = _order_book.get_next_time(current_time);
}

int merkel_main::get_user_option() {
    std::string line;
    try {

        std::cout << "type in 1-6" << std::endl;

        std::getline(std::cin, line);
        int user_option = std::stoi(line);

        std::cout << "you chose: " << user_option << std::endl;

        return user_option;
    } catch (const std::exception &e) {
        std::cout << "merkel_main::get_user_option bad input! " << line << std::endl;
    }
    return 0;
}

void merkel_main::process_user_option(int user_option) {

    std::map<int, void (merkel_main::*)()> menu;

    menu[1] = &merkel_main::print_help;
    menu[2] = &merkel_main::print_market_stats;
    menu[3] = &merkel_main::enter_ask;
    menu[4] = &merkel_main::enter_bid;
    menu[5] = &merkel_main::print_wallet;
    menu[6] = &merkel_main::next_timeframe;


    if (user_option < 1 || user_option > 6) {
        std::cout << "invalid choice. choose 1-6" << std::endl;
        return;
    }

    (this->*menu.at(user_option))();
}

void merkel_main::print_market_stats() {
    for (auto const &p: _order_book.get_known_products()) {
        std::cout << "product: " << p << std::endl;
        std::vector<order_book_entry> ask_entries = _order_book.get_orders(order_book_type::ask, p, current_time);
        std::vector<order_book_entry> bid_entries = this->_order_book.get_orders(order_book_type::bid, p, current_time);

        std::cout << "asks seen: " << ask_entries.size() << std::endl;
        std::cout << "bids seen: " << bid_entries.size() << std::endl;
        std::cout << "max ask: " << order_book::get_highest_price(ask_entries) << std::endl;
        std::cout << "max bid: " << order_book::get_highest_price(bid_entries) << std::endl;
        std::cout << "min ask: " << order_book::get_lowest_price(ask_entries) << std::endl;
        std::cout << "min bid: " << order_book::get_lowest_price(bid_entries) << std::endl;
    }

    // std::cout << "\norder book contains: " << orders.size() << " entries" << std::endl;
    // unsigned int bids = 0;
    // unsigned int asks = 0;
    //
    // for (order_book_entry &e: orders) {
    //     if (e.order_type == order_book_type::ask) {
    //         ++asks;
    //     }
    //     if (e.order_type == order_book_type::bid) {
    //         ++bids;
    //     }
    // }
    //
    // std::cout << "order book asks: " << asks << " bids: " << bids << std::endl << std::endl;
}
