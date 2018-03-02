#ifndef GRAPH_H
#define GRAPH_H
#include "permutation.h"
#include <vector>
#include <iostream>

/*This is a container that holds permutations as nodes on
	a graph.  Member functions build and traverse the graph to 
	find a superpermutation.
*/
using namespace std;
class Graph {
	public:
		void buildGraph(int degree);
		void print();
		void findSolutions();
	private:
		const char charSet[10] = {'0','1','2','3','4','5','6','7','8','9'};
		void buildNodesRecursively(int, int);
		std::vector<Permutation *> nodes;
		std::vector<Permutation *> solutions;
};

#endif
