#include <iostream>
#include <ctime>
#include "graph.h"
#include "permutation.h"
using namespace std;

int main () {
	bool dbg = true;
	int degree;
	bool exit = false;
	string userInput;
	cout << "This is Superb. Let's discover a superpermutation.\n";
	while(!exit){
		cout << "Please enter the number of symbols (or q to quit):\n";
		cin >> userInput;
		try {
			degree = stoi(userInput);
		} catch (...) {
			if(userInput.compare("q")) {
				cout << "Integers are the only valid input. Try again.\n";
			} else {
				cout << "Exiting Superb.\n";
				exit = true;
			}
			continue;
		}
		if (degree) {
			cout << "You entered " << degree << endl;
			clock_t start = clock();
			Graph permutationGraph;
			permutationGraph.buildGraph(dbg,degree);
			clock_t finish = clock();
			double buildSec = double(finish - start) / CLOCKS_PER_SEC;
			cout << "Building took " << buildSec * 1000.0 << " ms\n";
			cout << "Print permutations in graph? (y/n)\n";
			string doPrint;
			cin >> doPrint;
			if(doPrint.compare("y") == 0) {
				permutationGraph.print();
			}
		}
	}
}
