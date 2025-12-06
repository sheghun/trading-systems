#include <vector>
#include "order_book_entry.h"

using namespace std;
// some functions for summary
double computeAveragePrice(vector<order_book_entry> &entires);
double computeLowPrice(vector<order_book_entry> &entries);
double computeHighPrice(vector<order_book_entry> &entries);

// computing average price.
double computeAveragePrice(vector<order_book_entry> &entries) {
    double total = 0;
    double average = 0;
    for (const order_book_entry &e: entries) {
        total = total + e.price;
    }
    average = total / entries.size();
    return average;
}

// computing lowest price.
double computeLowPrice(vector<order_book_entry> &entries) {
    double lowest = entries[0].price;
    for (const order_book_entry &e: entries) {
        if (e.price < lowest)
            lowest = e.price;
    }
    return lowest;
}

// computing highest price.
double computeHighPrice(vector<order_book_entry> &entries) {
    double highest = entries[0].price;
    for (const order_book_entry &e: entries) {
        if (e.price > highest)
            highest = e.price;
    }
    return highest;
}
