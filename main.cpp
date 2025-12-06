#include <iostream>
#include <string>
#include <vector>
#include "merkel_main.h"
#include "order_book_entry.h"


int main() {

    merkel_main app{};
    app.init();
    app.print_menu();

    return 0;
}
