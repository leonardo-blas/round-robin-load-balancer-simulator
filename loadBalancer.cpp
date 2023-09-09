#include "loadBalancer.h"

void loadBalancer::roundRobinBalancing(stockServer* stockServers, int servers,
	int requests, int* serviceRecord){
	
	// Zeroing our service records.
	for (int i = 0; i < servers; ++i) {
		serviceRecord[i] = 0;
	}
	
	// Round Robin distribution simulation.
	for (int i = 0; i < requests; i++) { 
		// Round Robin distribution.
		int hashCode = i % servers;
		// Fetching a random stock from the determined server.
		stockServers[hashCode].getStockAt(rand() % 100);
		// Recording the determined server's usage.
		serviceRecord[hashCode]++;
	}
}