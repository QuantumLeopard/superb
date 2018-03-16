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
		Graph();
		~Graph();
		void buildGraph(bool dbg, int degree);
		void print();
		void findSolutions();
		void add(Permutation *);
		void remove(Permutation *);
	private:
		const char charSet[10] = {'0','1','2','3','4','5','6','7','8','9'};
		void buildNodesRecursively(bool, int, int);
		void generateGraphEdges(bool);
		Permutation * head;
		Permutation * tail;
		int size;
		int degree;
		class Edge;
		class Vertex {
			Permutation * permutation;
			void addNeighbor(Permutation *, int);
			Edge * head;
			Edge * tail;
			int numNeighbors;
			friend class Graph;
		};
		class Edge{
			int distance;
			Vertex * neighbor;
			friend class Graph;
		};
};

#endif
