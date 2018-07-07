#ifndef DLLIST_H
#define DLLIST_H
#include <iostream>
using namespace std;
template<class T>
class DoublyLinkedList {
	protected:
		int size;
		class Node {
			public:
				Node(){
					next = NULL;
					prev = NULL;
					datum = NULL;
				}

				Node(T * newDatum){
					next = NULL;
					prev = NULL;
					datum = newDatum;
				}

				~Node() {
					delete datum;
				}

				Node * getNext() {
					return this->next;
				}
				
				void setNext(Node * nextPtr) {
					this->next = nextPtr;
				}
				
				Node * getPrev() {
					return this->prev;
				}
				
				void setPrev(Node * prevPtr) {
					this->prev = prevPtr;
				}

				T * getDatum() {
					return this->datum;
				}

			private:
				Node * next;
				Node * prev;
				T * datum;
		};
		Node * head;
		Node * tail;

	public:
		DoublyLinkedList() {
			size = 0;
			head = NULL;
			tail = NULL;
		}
		void add(T * newNode) {
			if(size == 0) {
				head = new Node(newNode);
				tail = head;
			} else {
				Node * node = new Node(newNode);
				tail->setNext(node);
				node->setPrev(tail);
				tail = node;
			}
			size++;
		}
		void remove(T * oldNode) {
			if(this->size == 0) {
				return;
			} else {
				Node * node = head;
				while(node != NULL) {
					Node * next = node->getNext();
					Node * prev = node->getPrev();
					if(node->getDatum() == oldNode) {
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
		void remove(Node * oldNode) {
			if(this->size == 0) {
				return;
			} else {
				Node * node = head;
				while(node != NULL) {
					Node * next = node->getNext();
					Node * prev = node->getPrev();
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
	
};

#endif
