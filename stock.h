#include <iostream>
#include<algorithm>
using namespace std;

class stock {
private:
	string symbol;
	double cost;
	int shares;

public:
	stock();
	static string generateSymbol();
	void printStock();
};