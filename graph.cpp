#include "graph.h"

using namespace std;
Graph::Graph() {
	size = 0;
	head = NULL;
	tail = NULL;
}

Graph::~Graph() {
	Node * node = head; 
	while(node != NULL) {
		Node * next = node->getNext();  
		delete node;
		node = next;
	}
}

void Graph::buildGraph(bool dbg, int degree) {
	cout << "Building a permutation graph of degree " << degree << endl;

	this->degree = degree;
	this->buildNodesRecursively(dbg,degree,degree);
	//this->generateGraphEdges(dbg);

	cout << "Building complete: " << size << " permutations\n";

}

void Graph::buildNodesRecursively(bool dbg, int degree, int amtToBuild) {
	//if the amount to build is 1 then we are at the base case
	if (amtToBuild == 1 ) {
		for (int i = 1; i<=degree; i++ ) {
			Permutation * newNode = new Permutation(degree);
			newNode->setChar(0, charSet[i]);
			this->add(newNode);
		}
	} else {
		//This will pile up the characters without checking for dupes
		this->buildNodesRecursively(dbg, degree, amtToBuild - 1);
		//Two handles, one for base class and one for derived, to minimize casting.
		Node * node = head;
		std::vector<Permutation *> newPerms;
		//create a vector with nodes with a new digit, that doesn't duplicate a digit
		//in the node
		while(node != NULL) {
			Node * next = node->getNext();
			for(int i = 1; i <= degree; i++ ) {
				bool isDupe = false;
				for(int j = 0; j < degree; j++) {
					if(node->getDatum()->getChar(j) == charSet[i]) {
						isDupe = true;
						break;
					}
				}
				if(!isDupe) {
					Permutation * newPerm = new Permutation(node->getDatum());
					newPerm->setChar(amtToBuild-1, charSet[i]);
					newPerms.push_back(newPerm);
				}
			}
			//The above loop adds all the children, this is now a dupe
			this->remove(node);
			node = next;
		}
		for(std::vector<Permutation *>::iterator newNode = newPerms.begin(); newNode!=newPerms.end(); newNode++) {
			this->add(*newNode);
		}
	}
	cout << "Digit: " << amtToBuild << " added\n";
}

void Graph::generateGraphEdges(bool dbg) {
	//Permutation * workingNode = head;
	//while (workingNode != NULL) {
	//	Permutation * potentialNeighbor = head;
	//	while (potentialNeighbor != NULL ) {
	//		if(potentialNeighbor == workingNode) { continue; }
	//		int overlap = workingNode->overlap(potentialNeighbor);
	//		int distance = degree - overlap;
	//		cout << workingNode->str() << " : " << potentialNeighbor->str() << " overlap: " << overlap << endl;
	//	//They're all neighbors, even if you don't overlap them
	//		workingNode->addNeighbor(potentialNeighbor, distance);
	//		potentialNeighbor = potentialNeighbor->getNext();
	//	}
	//	workingNode = workingNode->getNext();
	//}
}

void Graph::print () {
	cout << "Graph size: " << size << "\n";
	for (Node * node = this->head; node != NULL; node=node->getNext()) {
		//cout << "NODE: " << node << endl;
		cout << node->getDatum()->str() << endl ;
		//cout << "  next: " << node->getNext() << endl;
		//cout << "  prev: " << node->getPrev() << endl;
	}
	cout << "End of "<< size << " nodes.\n";
}

