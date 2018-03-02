#include <iostream>
#include "graph.h"
#include "permutation.h"
using namespace std;

int main () {
	int degree;
	bool exit = false;
	string userInput;
	cout << "This is Superb. Let's discover a superpermutation.\n";
	while(!exit){
		cout << "Please enter the number of characters (or q to quit):\n";
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
			Graph permutationGraph;
			permutationGraph.buildGraph(degree);
			permutationGraph.print();
		}
	}
}
