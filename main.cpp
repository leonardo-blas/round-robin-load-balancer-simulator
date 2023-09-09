/*
Load balancer simulator, by Leonardo Blas.

In this project, we simulate a load balancer by implementing stockServer
and loadBalancer objects. Our load balancer is capable of balancing via Round
Robin.

stockServer objects are data structures based on static arrays, which contain
stock objects (the ones we've been dealing with in class). For practical
purposes, we can only create stockServer objects that will store between 1 to
100 objects, and while we will have an insertion method, no deletion methods
will be provided.

loadBalancer objects don't store data. They act as the medium that connects
user data requests and stockServer objects. They are capable of simulating
requests and distributing those requests in a Round Robin fashion among an
array of stockServer objects.

In this simulation, all stockServer objects contain the same data. It is up to
the loadBalancer object to distribute our user requests (simulated through the
main) among our servers.

As seen in the sample output, a Round Robin load balancer will distribute the
same number of requests across all stockServers regardless of their CPU power.
This works as expected, but is not ideal. This is when a Weighted Round Robin
load balancer would be best (in a future project!).
*/

#include "loadBalancer.h"

int main() {
	// Establishing the number of servers we will work with.
	const int numberOfServers = 10;
	
	// Creating an array of servers.
	stockServer stockServers[numberOfServers];
	
	// Filling the first server with 100 stocks.
	for (int i = 0; i < 100; ++i) {
		stockServers[0].insertEnd(stock());
	}
	
	// Copying the first server's data into the other servers.
	// Using the overloaded + operator.
	// We don't copy a server's computing power.
	for (int i = 1; i < numberOfServers; ++i) {
		stockServers[i] = stockServers[0];
	}
	
	// Printing the data set we're working with.
	cout << "--------------------------------------------------------------\n";
	cout << "Created " << numberOfServers << " servers. "
		<< "All servers hold the same 100 stocks:\n";
	cout << "--------------------------------------------------------------\n";
	stockServers[0].printElements();
	
	// Creating loadBalancer object;
	loadBalancer balancer;
	
	// Establishing the number of requests we will work with.
	int numberOfRequests = 10000;
	
	// Creating an array to record the number of requests handled per server.
	int serviceRecord[numberOfServers];
	
	// Trying a Round Robin Load Balancing.
	balancer.roundRobinBalancing(stockServers, numberOfServers,
		numberOfRequests, serviceRecord);
	
	// Printing each server's service record after Round Robin Load Balancing.
	cout << "--------------------------------------------------------------\n";
	cout << "Simulating " << numberOfRequests << " requests using Round Robin"
		<< " load balancing.\n";
	cout << "--------------------------------------------------------------\n";
	
	for (int i = 0; i < numberOfServers; ++i) {
		cout << "Server " << i << ", of computing power "
			<< stockServers[i].getComputingPower() << ", served " << serviceRecord[i]
			<< " requests.\n";
	}
}

/*
SAMPLE RUN:

Cannot insert anymore stocks.

Cannot insert anymore stocks.

Cannot insert anymore stocks.

--------------------------------------------------------------
Created 10 servers. All servers hold the same 100 stocks:
--------------------------------------------------------------
symbol: OHZV
cost:   57
shares: 41

symbol: JBJY
cost:   28
shares: 35

symbol: DLNB
cost:   67
shares: 65

symbol: KVBE
cost:   4
shares: 76

symbol: YTFJ
cost:   20
shares: 97

symbol: QMGZ
cost:   42
shares: 40

symbol: BKWE
cost:   86
shares: 46

symbol: OUXD
cost:   66
shares: 74

symbol: NKHT
cost:   54
shares: 4

symbol: FYTL
cost:   14
shares: 50

symbol: ENTO
cost:   32
shares: 83

symbol: FULD
cost:   9
shares: 87

symbol: XLON
cost:   35
shares: 48

symbol: XZEC
cost:   1
shares: 40

symbol: PKMZ
cost:   23
shares: 72

symbol: XLUA
cost:   57
shares: 2

symbol: JYEC
cost:   52
shares: 37

symbol: DJES
cost:   67
shares: 6

symbol: PJIK
cost:   65
shares: 47

symbol: AUDV
cost:   82
shares: 5

symbol: GLLI
cost:   42
shares: 82

symbol: AMBO
cost:   15
shares: 51

symbol: KDQR
cost:   54
shares: 29

symbol: ORJF
cost:   1
shares: 76

symbol: GHHH
cost:   95
shares: 25

symbol: ZIFA
cost:   18
shares: 73

symbol: TZQG
cost:   74
shares: 82

symbol: NHPQ
cost:   32
shares: 68

symbol: CTMO
cost:   66
shares: 89

symbol: PCVK
cost:   76
shares: 98

symbol: ODAK
cost:   17
shares: 64

symbol: CQAU
cost:   73
shares: 48

symbol: OWDZ
cost:   66
shares: 89

symbol: QHKP
cost:   81
shares: 71

symbol: BYZM
cost:   9
shares: 30

symbol: MDLX
cost:   48
shares: 67

symbol: YDAX
cost:   56
shares: 73

symbol: NECX
cost:   88
shares: 39

symbol: JBHI
cost:   60
shares: 47

symbol: VOCD
cost:   84
shares: 3

symbol: QMWI
cost:   43
shares: 63

symbol: XZOQ
cost:   43
shares: 70

symbol: TPIK
cost:   45
shares: 86

symbol: UDMO
cost:   8
shares: 78

symbol: KPPZ
cost:   93
shares: 17

symbol: HFQS
cost:   16
shares: 1

symbol: XIIS
cost:   74
shares: 33

symbol: WNHX
cost:   28
shares: 33

symbol: VYDF
cost:   22
shares: 63

symbol: DWOM
cost:   48
shares: 66

symbol: UDCN
cost:   6
shares: 5

symbol: DGCN
cost:   7
shares: 99

symbol: ITPP
cost:   94
shares: 88

symbol: MXII
cost:   80
shares: 87

symbol: EBPY
cost:   70
shares: 78

symbol: GQSX
cost:   77
shares: 37

symbol: PLWZ
cost:   5
shares: 26

symbol: JOOP
cost:   90
shares: 46

symbol: IFVK
cost:   46
shares: 38

symbol: WPGP
cost:   41
shares: 25

symbol: EAWP
cost:   49
shares: 76

symbol: PIHO
cost:   43
shares: 44

symbol: UFFB
cost:   39
shares: 96

symbol: HPEV
cost:   66
shares: 30

symbol: QRGR
cost:   84
shares: 46

symbol: ZHIB
cost:   93
shares: 96

symbol: RKHZ
cost:   12
shares: 67

symbol: BZFH
cost:   91
shares: 16

symbol: NRKL
cost:   88
shares: 97

symbol: VPSZ
cost:   25
shares: 7

symbol: OPFG
cost:   36
shares: 75

symbol: ZGFL
cost:   41
shares: 11

symbol: SXBT
cost:   30
shares: 14

symbol: ILOC
cost:   39
shares: 5

symbol: GCOZ
cost:   28
shares: 85

symbol: ZIUF
cost:   54
shares: 3

symbol: IMXE
cost:   0
shares: 2

symbol: WNYS
cost:   63
shares: 28

symbol: CRFX
cost:   3
shares: 42

symbol: OGCS
cost:   58
shares: 30

symbol: ZPSC
cost:   49
shares: 85

symbol: JOTY
cost:   52
shares: 29

symbol: CWMB
cost:   44
shares: 22

symbol: OLSV
cost:   56
shares: 51

symbol: PYLO
cost:   79
shares: 2

symbol: WAJG
cost:   29
shares: 85

symbol: GYZA
cost:   60
shares: 99

symbol: ENFV
cost:   28
shares: 72

symbol: IKQJ
cost:   1
shares: 87

symbol: GVEN
cost:   50
shares: 78

symbol: PPWW
cost:   31
shares: 89

symbol: HXTG
cost:   40
shares: 13

symbol: VMAJ
cost:   20
shares: 88

symbol: FAXE
cost:   22
shares: 16

symbol: EIJI
cost:   18
shares: 2

symbol: MDUC
cost:   41
shares: 74

symbol: AIOI
cost:   52
shares: 50

symbol: ISIY
cost:   37
shares: 1

symbol: NZDU
cost:   65
shares: 81

symbol: TSAV
cost:   58
shares: 84

--------------------------------------------------------------
Simulating 10000 requests using Round Robin load balancing.
--------------------------------------------------------------
Server 0, of computing power 1, served 1000 requests.
Server 1, of computing power 1, served 1000 requests.
Server 2, of computing power 5, served 1000 requests.
Server 3, of computing power 3, served 1000 requests.
Server 4, of computing power 6, served 1000 requests.
Server 5, of computing power 8, served 1000 requests.
Server 6, of computing power 7, served 1000 requests.
Server 7, of computing power 3, served 1000 requests.
Server 8, of computing power 2, served 1000 requests.
Server 9, of computing power 1, served 1000 requests.

*/