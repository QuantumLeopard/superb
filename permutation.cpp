#include "permutation.h"

Permutation::Permutation(int size) {
	this->size = size;
	this->charArray = new char [size];
	for( int i = 0; i < size; i++ ) {
		this->charArray[i] = '0';
	}
	this->next = NULL;
	this->prev= NULL;
}

Permutation::Permutation(Permutation * that) {
	int size = that->getSize();
	this->size = size;
	this->charArray = new char [size];
	for( int i = 0; i < size; i++ ) {
		this->charArray[i] = that->charArray[i];
	}
	this->next = NULL;
	this->prev = NULL;
}

char Permutation::getChar(int i) {
	return this->charArray[i];
}

void Permutation::setChar(int i, char val) {
	this->charArray[i] = val;
}

Permutation * Permutation::getNext() {
	return this->next;
}

void Permutation::setNext(Permutation * nextPtr) {
	this->next = nextPtr;
}

Permutation * Permutation::getPrev() {
	return this->prev;
}

void Permutation::setPrev(Permutation * prevPtr) {
	this->prev = prevPtr;
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

Permutation::~Permutation() {
		delete[] this->charArray;
}
