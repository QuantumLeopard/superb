#ifndef PERMUTATION_H
#define PERMUTATION_H
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
/*This class is the container for a permutation of n characters.
	For n = 3, it may contain 312, for instance.
*/
using namespace std;
class Permutation {
	public:
		Permutation(int);
		Permutation(Permutation * );
		~Permutation();
		char getChar(int);
		void setChar(int, char);
		bool addNeighbor(Permutation *, int);
		int getSize();
		string str();
		int overlap(Permutation *);
	private:
		int size;
		char * charArray;
};

#endif
