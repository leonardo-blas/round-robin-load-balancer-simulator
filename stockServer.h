#include "stock.h"

class stockServer {
private:
	stock* arrayContainer; // The static stocks array.
	int serverSize; // The maximum number of stocks to be contained.
	int currentElements; // The current number of stocks contained.
	int computingPower; // A server's CPU capacity, in a (0-10) scale.
	// If a server's CPU capacity is 0, it is offline.
	
public:
	stockServer(int serverElements = 100);
	~stockServer();
	void insertEnd(stock toInsert);
	void printElements();
	const stockServer& operator= (const stockServer& RHS);
	stock getStockAt(int position);
	int getServerSize();
	int getCurrentElements();
	int getComputingPower();
};