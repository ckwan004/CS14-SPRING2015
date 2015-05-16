// -*- bst.h -*-
#ifndef BST_H
#define BST_H

#include <cassert> 
#include <iostream> 
#include <fstream> 
#include <cstdlib> 
#include <string> 
#include <sstream> 
#include <map>
#include <list>
#include <math.h>

using namespace std; 

#define nil 0

// #define Value int 
// restore for testing. 
template < typename Value >
class BST {
	class Node { // binary tree node 
	public:
		Node* left;
		Node* right;
		Value value;

		// size and height
		int hght;
		int sz;
		
		bool marked;

		Node( const Value v = Value() ) : value(v), left(nil), right(nil), hght(0), sz(0), marked(false) {}
		Value& content() { return value; }
		bool isInternal() { return left != nil && right != nil; } 
		bool isExternal() { return left != nil || right != nil; }
		bool isMarked() {return marked;} 
		void mark() {marked = true;}
		void unmark() {marked = false;}
		bool isLeaf() { return left == nil && right == nil; }
		int height() {
			// returns the height of the subtree rooted at this node
			// FILL IN
			return hght;
		}
		int size() {
			// returns the size of the subtree rooted at this node,
			// FILL IN 
			return sz;
		}
	}; // Node

	// const Node* nil; // later nil will point to a sentinel node.
	int count;
	int c_size;
	Node * root;
	Value holder;

public:

	int size() { 
		// size of the overall tree
		// FILL IN
		if(root != nil)
			return root->size();
		return 0;
	}

	bool empty() { return size() == 0; }

	void print_node(const Node * n) {
		//Print the node's value.
		//FILL IN
		cout << n->content();
	}

	bool search(Value x) {
		//searchf or a Value in the BST and return true if it was found.
		//FILL IN
		if(root != nil) {
			modiOrder(root, x);
			if(holder == x)
				return true;
			return false;
		}
		return false;
	}

	void modiOrder(Node * T, Value x) {
		if(T) {
			modiOrder(T->left, x);
			if(x == T->content())
				holder = T->content();
			modiOrder(T->right, x);
		}
	}

	void preorder() const {
		//Traverse and print the tree one Value per line in perorder.
		//FILL IN
		if(root != nil)
			prOrder(root);
	}

	void prOrder(Node * T) const {
		if(T) {
			cout << T->content() << " ";
			prOrder(T->left);
			prOrder(T->right);
		}
	}

	void postorder() const {
		// Traverse and print the tree one Value per line in postorder.
		// FILL IN
		if(root != nil)
			poOrder(root);
	}

	void poOrder(Node * T) const {
		if(T) {
			poOrder(T->left);
			poOrder(T->right);
			cout << T->content() << " ";
		}
	}

	void inorder() const {
		// Traverse and print the tree one Value per line in inorder
		// FILL IN
		if(root != nil)
			inOrder(root);
	}

	void inOrder(Node * T) const {
		if(T) {
			inOrder(T->left);
			cout << T->content() << " ";
			inOrder(T->right);
		}
	}

	Value& operator[](int n) {
		//returns reference to the value field of the n-th Node.
		// FILL IN
		if(n < size() && n >= 0 && root != nil) {
			findVal(n+1, root);
			count = 0;
			return holder;
		}
		throw "Is not an index in the BST.\n";
	}

	void findVal(int n, Node* T) {
		if(T != nil) {
			findVal(n, T->left);

			++count;
			if(count == n) {
				holder = T->content();
			}

			findVal(n, T->right);
		}
	}

	BST() : count(0), c_size(0), root(nil) {}

	void insert( Value X ) { root = insert( X, root ); } 
	Node* insert( Value X, Node* T ) {
		//added code for height
		++count;

		// The normal binary-tree insertion procedure ... 
		if( T == nil){
			T = new Node( X ); // the only place that T gets updated.
			T->hght = count;
			++(T->sz);
			count = 0;
		} else if ( X < T->value ) {
			++(T->sz);
			T->left = insert( X, T->left );
		} else if ( X > T->value ) {
			++(T->sz);
			T->right = insert( X, T->right ); 
		} else {
			++(T->sz);
			T->hght = count;
			T->value = X; 
			count = 0;
		}

		// later, rebalancing code will be installed here
		return T;
	}


	void remove( Value X ) { root = remove( X, root ); } 
	Node* remove( Value X, Node*& T ) {
		// The normal binary-tree removal procedure ... 
		// Weiss’s code is faster but way more intricate. 
		if( T!=nil){
			--(T->sz);
			if ( X > T->value ) {
				T->right = remove( X, T->right );
			} else if ( X < T->value ) {
				T->left = remove( X, T->left );
			} else { // X == T->value
				if ( T->right != nil ) {
					Node* x = T->right;
					while ( x->left != nil ) x = x->left;
					T->value = x->value; // successor’s value 
					T->right = remove( T->value, T->right );
				} else if ( T->left != nil ) {
					Node* x = T->left;
					while ( x->right != nil ) x = x->right;
					T->value = x->value; // predecessor’s value 
					T->left = remove( T->value, T->left );
				} else { //*T is external
					delete T;
					T = nil; //the only updating of T
				} 
			}
		}
	
		// later, rebalancing code will be installed here
		return T; 
	}

	void okay( ) { okay( root ); } 
	void okay( Node* T ) {
		// diagnostic code can be installed here
		return; 
	}

	void minCover() {
		if(root != nil)
			prOrder2(root);
	}

	void prOrder2(Node * T) const {
		if(T) {
			if(T->isExternal() && (T == root->left || T == root->right))
				T->mark();
			if(!(T->isLeaf()))
				T->mark();
			prOrder2(T->left);
			prOrder2(T->right);
		}
	}

	void preOrderMarkCheck(Node * T) {
		if(T) {
			if(T->isMarked()) {
				cout << T->content() << " ";
				++c_size;
			}
			preOrderMarkCheck(T->left);
			preOrderMarkCheck(T->right);
		}
	}

	void displayMinCover() {
		c_size = 0;
		if(root != nil) {
			cout << endl << "Part 1" << endl;
			preOrderMarkCheck(root);
			cout << endl << c_size << endl;
		}
	}

	int displayVertSum(int i) {
		std::map<int, int> m;
		m[	i] = 0;
		if(root != nil)
			vertSum(root, 0, m);
		return m[i];
	}

	void vertSum(Node* node, int hd, std::map<int, int>& m) {
		if(node) {
			vertSum(node->left, hd-1, m);
			int sum = m[hd] + node->content();
			m[hd] = sum;
			vertSum(node->right, hd+1, m);
		}
	}

    void printBuff(int buffer[], int pathLen)
    {
        for(int i = pathLen - 1 ; i != -1 ; --i) {
        	cout << buffer[i] << " ";
        }
        cout << endl;
    }

    int calcPathSum(int buffer[], int pathLen)
    {
        int sum = 0;
        for(int i = 0 ; i < pathLen ; i++)
        {
            sum = sum + buffer[i];
        }

        return sum;
    }

    void findSumPathRecursion(Node* n, int sum, int pathLen, int buffer[])
    {
        if(n == NULL)
        {
            return;
        }

        buffer[pathLen] = n->value;
        pathLen = pathLen + 1;

        if(n->left == NULL && n->right == NULL && calcPathSum(buffer, pathLen) == sum)
        {
            printBuff(buffer, pathLen);
        }

        else
        {
            findSumPathRecursion(n->left, sum, pathLen, buffer);
            findSumPathRecursion(n->right, sum, pathLen, buffer);
        }
    }

    void findSumPath1(Node* n, int sum, int buffer[])
    {
        findSumPathRecursion(n, sum, 0, buffer);
    }

    void findSumPath(int sum, int buffer[])
    {
        findSumPath1(this->root, sum, buffer);
    }

};  // BST
#endif
