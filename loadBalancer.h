/*
Round Robin balancing.
This function requests random stocks from our stockServers (all servers
contain the same data, under the same positions) and distributes it via Round
Robin. Additionally, we pass a serviceRecord int array to visualize the number
of requests each server handled.
*/

#include "stockServer.h"

class loadBalancer {
public:
	void roundRobinBalancing(stockServer* stockServers, int servers,
		int requests, int* serviceRecord);
};