#include "stockServer.h"
#include <cassert>

stockServer::stockServer(int serverElements) {
	if (serverElements < 1 || serverElements > 100) {
		cout << "Can only create servers that will store 1 to 100 elements.\n\n";
		serverSize = 100;
	}

	else {
		serverSize = serverElements;
	}

	currentElements = 0;
	computingPower = rand() % 10;
	arrayContainer = new stock[serverSize];
	assert(arrayContainer != nullptr);
}

stockServer::~stockServer() {
	delete[] arrayContainer;
}

void stockServer::insertEnd(stock toInsert) {
	if (currentElements >= serverSize) {
		cout << "Cannot insert anymore stocks.\n\n";
		return;
	}

	arrayContainer[currentElements] = toInsert;
	currentElements++;
}

void stockServer::printElements() {
	for (int i = 0; i < currentElements; ++i) {
		arrayContainer[i].printStock();
	}
}

// We don't copy a server's computing power.
const stockServer& stockServer::operator= (const stockServer& RHS) {
	delete[] arrayContainer;
	currentElements = RHS.currentElements;
	serverSize = RHS.serverSize;
	arrayContainer = new stock[serverSize];
	assert(arrayContainer != nullptr);

	for (int i = 0; i < currentElements; ++i) {
		arrayContainer[i] = RHS.arrayContainer[i];
	}

	return *this;
}

stock stockServer::getStockAt(int position) {
	return arrayContainer[position];
}

int stockServer::getServerSize() {
	return serverSize;
}

int stockServer::getCurrentElements() {
	return currentElements;
}

int stockServer::getComputingPower() {
	return computingPower;
}