#include "graph.h"

void Graph::buildGraph(int degree) {
	cout << "Building a permutation graph of degree " << degree << endl;

	this->buildNodesRecursively(degree,degree);

	cout << "Building complete\n";

}

void Graph::buildNodesRecursively(int degree, int amtToBuild) {
	//if the amount to build is 1 then we are at the base case
	if (amtToBuild == 1 ) {
		for (int i = 1; i<=degree; i++ ) {
			Permutation * newNode = new Permutation(degree);
			newNode->setChar(0, charSet[i]);
			this->nodes.push_back(newNode);
		}
	} else {
		//This will pile up the characters without checking for dupes
		this->buildNodesRecursively(degree, amtToBuild - 1);
		//remove the dupes
		for(std::vector<Permutation*>::iterator node = this->nodes.begin(); node != this->nodes.end(); node++) {
			//This setting up of a bool array would prevent n^2 dupe check in favor of 2n
			//bool character[degree];
			//for( int i = 0; i < degree; i++) {
			//	character[i] = false;
			//}
			bool isDupe = false;
			for( int i = 0; i < degree; i++) {
				for( int j = 0; j < degree; j++) {
					if ( (*node)->getChar(i) == (*node)->getChar(i) && i != j) {
						//dupe
						isDupe = true;
						this->nodes.erase(node);
						delete (*node);
					}
				}
			}
			if(!isDupe) {
				for(int i = 1; i <= degree; i++ ) {
					Permutation * newNode = new Permutation(*node);
					newNode->setChar(amtToBuild-1, charSet[i]);
				}
				//The above loop adds all the children, this is now a dupe
				delete (*node);
			}
		}
	}
	cout << "  digit " << degree - amtToBuild << " generated for each node\n";
}

void Graph::print () {
	cout << "The following nodes are in the current permutation graph:\n";
	for (std::vector<Permutation *>::iterator node = this->nodes.begin(); node != this->nodes.end(); node++) {
		for(int i = 0; i < (*node)->getSize(); i++) {
			cout << (*node)->getChar(i);
		}
		cout << endl;
	}
	cout << "End of nodes.\n";
}
