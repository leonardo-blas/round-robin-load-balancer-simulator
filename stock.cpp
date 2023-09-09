#include "stock.h"

stock::stock() {
   symbol = generateSymbol();
   cost = rand() % 100;
   shares = rand() % 100;
}

string stock::generateSymbol() {
   const int length = 4;
   string symbol;
   const char* possibles = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   auto generator = [&] { return possibles[rand() % strlen(possibles)]; };
   
   symbol.reserve(length);
   generate_n(back_inserter(symbol), length, generator);
   
   return symbol;
}

void stock::printStock() {
   cout << "symbol:	" << symbol << '\n';
   cout << "cost:	" << cost << '\n';
   cout << "shares:	" << shares << "\n\n";
}