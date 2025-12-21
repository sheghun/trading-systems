#pragma once
#include <vector>
#include "order_book.h"
#include "order_book_entry.h"

class merkel_main {

public:
    merkel_main();
    void init();

private:
    void print_menu();
    void print_help();
    void print_market_stats();
    void print_exchange_stats();
    void enter_bid();
    void enter_offer();
    void print_wallet();
    void next_timeframe();
    void process_user_option(int user_option);
    int get_user_option();

    order_book _order_book{"20200317.csv"};
};
