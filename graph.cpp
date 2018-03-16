#include "graph.h"

Graph::Graph() {
	size = 0;
	head = NULL;
	tail = NULL;
}

Graph::~Graph() {
	Permutation * node = head; 
	while(node != NULL) {
		Permutation * next = node->getNext();  
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
		//remove the dupes
		Permutation* node = head;
		std::vector<Permutation *> newNodes;
		while(node != NULL) {
			Permutation * next = node->getNext();
			for(int i = 1; i <= degree; i++ ) {
				bool isDupe = false;
				for(int j = 0; j < degree; j++) {
					if(node->getChar(j) == charSet[i]) {
						isDupe = true;
						break;
					}
				}
				if(!isDupe) {
					Permutation * newNode = new Permutation(node);
					newNode->setChar(amtToBuild-1, charSet[i]);
					newNodes.push_back(newNode);
				}
			}
			//The above loop adds all the children, this is now a dupe
			this->remove(node);
			node = next;
		}
		for(std::vector<Permutation *>::iterator newNode = newNodes.begin(); newNode!=newNodes.end(); newNode++) {
			this->add(*newNode);
		}
	}
	cout << "Digit: " << amtToBuild << " added\n";
}

void Graph::generateGraphEdges(bool dbg) {
	Permutation * workingNode = head;
	while (workingNode != NULL) {
		Permutation * potentialNeighbor = head;
		while (potentialNeighbor != NULL ) {
			if(potentialNeighbor == workingNode) { continue; }
			int overlap = workingNode->overlap(potentialNeighbor);
			int distance = degree - overlap;
			//workingNode->addNeighbor(potentialNeighbor, distance);
			potentialNeighbor = potentialNeighbor->getNext();
		}
		workingNode = workingNode->getNext();
	}
}

void Graph::print () {
	cout << "Graph size: " << size << "\n";
	for (Permutation * node = this->head; node != NULL; node=node->getNext()) {
		//cout << "NODE: " << node << endl;
		cout << node->str() << endl ;
		//cout << "  next: " << node->getNext() << endl;
		//cout << "  prev: " << node->getPrev() << endl;
	}
	cout << "End of "<< size << " nodes.\n";
}

void Graph::add(Permutation * newNode) {
	if(size == 0) {
		head = newNode;
		tail = newNode;
	} else {
		tail->setNext(newNode);
		newNode->setPrev(tail);
		tail = newNode;
	}
	size++;
}

void Graph::remove(Permutation * oldNode) {
	if(this->size == 0) {
		return;
	} else {
		Permutation * node = head;
		while(node != NULL) {
			Permutation * next = node->getNext();
			Permutation * prev = node->getPrev();
			if(node == oldNode) {
				if(prev) {
					prev->setNext(next);
				}
				if(next) {
					next->setPrev(prev);
				}
				if(head == node) {
					head = next;
				}
				if(tail == node) {
					tail = prev;
				}
				delete node;
				this->size -= 1;
				node = NULL;
			} else {
				node = next;
			}
		}
	}
}

