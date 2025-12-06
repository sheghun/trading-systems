#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum class OrderBookType { bid, ask};

//class declaration
class OrderBookEntry
{

public:
	double price;
	double amount;
	std::string timestamp;
	std::string product;
	OrderBookType orderType;

	//constructor
	OrderBookEntry(double _price, double _amount, std::string _timestamp, std::string _product, OrderBookType _orderType);

};

//class definition
OrderBookEntry::OrderBookEntry(double _price, double _amount, std::string _timestamp, std::string _product, OrderBookType _orderType)
	:price(_price), amount(_amount), timestamp(_timestamp), product(_product), orderType(_orderType)
{
}

//some functions for summary
double computeAveragePrice(vector<OrderBookEntry>& entires);
double computeLowPrice(vector<OrderBookEntry>& entries);
double computeHighPrice(vector<OrderBookEntry>& entries);



int main()
{
	std::vector<OrderBookEntry> entries;

	//adding data.
	OrderBookEntry obe1{ 0.02186299,0.1,"2020/03/17 17:01:24.884492","ETH/BTC",OrderBookType::bid };
	OrderBookEntry obe2{ 1.22186299,1.1,"2020/03/17 17:10:25.885492","ETH/BTC",OrderBookType::ask };
	OrderBookEntry obe3{ 2.22186299,3.1,"2020/03/18 15:12:25.885492","ETH/BTC",OrderBookType::ask };
	OrderBookEntry obe4{ 0.22186259,2.1,"2020/03/17 08:10:19.885492","ETH/BTC",OrderBookType::bid };
	OrderBookEntry obe5{ 3.22186269,0.1,"2020/03/17 23:10:20.885492","ETH/BTC",OrderBookType::ask };
	entries.push_back(obe1);
	entries.push_back(obe2);
	entries.push_back(obe3);
	entries.push_back(obe4);
	entries.push_back(obe5);


	//iteration
	cout << "prices" << endl;
	cout << "----------" << endl;
	for (const OrderBookEntry& e : entries)
	{
		cout << e.price << endl;
	}

	//summary
	cout << "===========summary============" << endl;
	cout << "average price is :" << computeAveragePrice(entries) << endl;
	cout << "lowest price is :" << computeLowPrice(entries) << endl;
	cout << "highest price is :" << computeHighPrice(entries) << endl;


    return 0;
}

//function definitions.

//computing average price.
double computeAveragePrice(vector<OrderBookEntry>& entries)
{
	double total=0;
	double average = 0;
	for (const OrderBookEntry& e : entries)
	{
		total = total + e.price;
	}
	average = total / entries.size();
	return average;
}

//computing lowest price.
double computeLowPrice(vector<OrderBookEntry>& entries)
{
	double lowest=entries[0].price;
	for (const OrderBookEntry& e : entries)
	{
		if (e.price < lowest) lowest = e.price;

	}
	return lowest;
}

//computing highest price.
double computeHighPrice(vector<OrderBookEntry>& entries)
{
	double highest = entries[0].price;
	for (const OrderBookEntry& e : entries)
	{
		if (e.price > highest) highest = e.price;

	}
	return highest;

}