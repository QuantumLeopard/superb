#include "permutation.h"

Permutation::Permutation(int size) {
	this->size = size;
	this->charArray = new char [size];
	for( int i = 0; i < size; i++ ) {
		this->charArray[i] = 0;
	}
}

Permutation::Permutation(const Permutation * that) {
	int size = that->size;
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

Permutation::~Permutation() {
		delete[] this->charArray;
}
