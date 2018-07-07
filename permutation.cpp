#include "permutation.h"
using namespace std;

Permutation::Permutation(int size) {
	this->size = size;
	this->charArray = new char [size];
	for( int i = 0; i < size; i++ ) {
		this->charArray[i] = '0';
	}
}

Permutation::~Permutation() {
		delete[] this->charArray;
}

Permutation::Permutation(Permutation * that) {
	int size = that->getSize();
	this->size = size;
	this->charArray = new char [size];
	for( int i = 0; i < size; i++ ) {
		this->charArray[i] = that->charArray[i];
	}
}

char Permutation::getChar(int i) {
	return this->charArray[i];
}

void Permutation::setChar(int i, char val) {
	this->charArray[i] = val;
}

int Permutation::getSize() {
	return this->size;
}

string Permutation::str() {
	ostringstream returnVal;
	for(int i = 0; i<size; i++) {
		returnVal << charArray[i];
	}
	return returnVal.str();
}

int Permutation::overlap(Permutation * potentialNeighbor) {
	//start with complete overlap and slide apart until they match
	int offset = 0;
	bool matchingOverlapFound = false;
	while (!matchingOverlapFound && offset < size) {
		bool noMismatch = true;
		int pos = offset;
		while (noMismatch && pos < size) {
			if(this->getChar(pos) != potentialNeighbor->getChar(pos-offset)) {
				noMismatch = false;
			}
			pos++;
		}
		if (noMismatch) {
			matchingOverlapFound = true;
		} else {
			offset++;
		}
	}
	return size - offset;
}

bool addNeighbor(Permutation * newNeighbor, int distance) {
	return true;
}
