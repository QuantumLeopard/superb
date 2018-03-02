#ifndef PERMUTATION_H
#define PERMUTATION_H
#include <vector>
#include <string>
/*This class is the container for a permutation of n characters.
	For n = 3, it may contain 312, for instance.
*/
using namespace std;
class Permutation {
	public:
		Permutation(int);
		Permutation(const Permutation * );
		~Permutation();
		char getChar(int);
		void setChar(int, char);
		int getSize();
	private:
		char * charArray;
		int size;
};

#endif
