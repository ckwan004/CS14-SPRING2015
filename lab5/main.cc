#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include "bst.h"

using namespace std;

int main()
{
	srand(time(0));
	BST<int> thing = BST<int>();
	for(int i=0; i< 100; ++i) {
		thing.insert(rand()%100);
	}

	// thing.inorder();
	// cout << endl;
	// thing.postorder();
	// cout << endl;
	// thing.preorder();
	// cout << endl;

	// if(thing.search(5))
	// 	cout << "there is a five.\n";

	// try {
	// 	cout << thing[0] << endl;
	// 	cout << thing[1] << endl;
	// 	cout << thing[2] << endl;	
	// } catch(const char * error) {
	// 	cout << error << endl;
	// }

	thing.minCover();
	thing.displayMinCover();

	int buffer[1000];
	cout << "Part 2" << endl;
	thing.findSumPath(12, buffer);

	cout << "Part 3" << endl;
	cout << thing.displayVertSum(0) << endl;

	return 0;
}