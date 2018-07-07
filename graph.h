#ifndef GRAPH_H
#define GRAPH_H
#include "dlList.h"
#include "permutation.h"
#include <vector>
#include <iostream>

/*This is a container that holds permutations as nodes on
	a graph.  Member functions build and traverse the graph to 
	find a superpermutation.
*/
using namespace std;
class Graph : public DoublyLinkedList<Permutation> {
	public:
		Graph();
		~Graph();
		void buildGraph(bool dbg, int degree);
		void print();
		void findSolutions();
	private:
		const char charSet[10] = {'0','1','2','3','4','5','6','7','8','9'};
		void buildNodesRecursively(bool, int, int);
		void generateGraphEdges(bool);
		int degree;
};

#endif
