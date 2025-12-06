#pragma once

class merkel_main {

public:
    merkel_main();
    void init();
    void print_menu();
    void print_help();
    void print_exchange_stats();
    void enter_bid();
    void enter_offer();
    void print_wallet();
    void next_timeframe();
    void process_user_option(int user_option);
    int get_user_option();
};
