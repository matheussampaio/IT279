/*
 * Asg3.cpp
 *
 *  Created on: Feb 29, 2016
 *      Author: cli2
 */
/*
 * Student should not modify any of the following functions except debugging_test().
 * Students are free to change debugging_test() and implement the public test() method in BST class as they wish
 * for debugging purpose. The submitted Asg3.cpp program should comment out debugging_test().
 *
 */

#include <cstdlib>
#include <iostream>
#include "AVL.h"
#include "AVL.cpp"
using namespace std;


std::string tostring(int n) {
	string data="";
	if (n==0) return "0";
	while (n!=0) {
		char a = (n%10+'0');
		data = a + data;
		n /= 10;
	}
	return data;
}

int toint(string s) {
	if (s=="")
		return 0;
	return toint(s.substr(0,s.length()-1))*10+(s.at(s.length()-1)-'0');
}

void printArray(string* a, int n, int size) {
	cout << "";
	for (int i=0; i< size && i < n; i++) {
		cout << *(a+i) << " ";
	}
	if (n < size) cout <<  ".........";
}

/**
 * Add n random new items into T, 0 <= key < max
 */
void randomadd(BST<std::string> * T, int n, int max) {
	cout << "Adding " << n << " random data: ";
	for (int i=0;i<n;i++) {
		int key = rand()%max;
		if (i < 20) cout << key << " ";
		cout.flush();
		std::string data = tostring(key);
		T->insert(key,data);
	}
	if (T->size() > 20)
		cout << ".........";
}

void debugging_test() {
	    cout << "Debugging test:\n\n";

		int n=10;
		for (int i=1;i<1000;i++) {
			srand(i);
			AVL<string> *V = new AVL<string>();
			cout <<  "\nTest " << i << ":  ";
			for (int k=0; k<n; k++) {
				int key=rand()%100;
				V->insert(key,tostring(key));
				cout << "+" << key;
			}
			cout << endl;
			cout <<  "AVL size: " << V->size() << ",  height=" << V->height() << "  ";

			V->test();

			string *a = V->inorder();
			int removeCount=0;
			for (int k=0; k<n; k++) {
				int key=toint(*(a+rand()%n));
				cout << "k=" << k <<"[?" << key << "]";
				cout.flush();
				if (V->remove(key) != NULL) {
					cout << "\n-" << key << "[";
					V->test();
					cout << "]\n";
					cout.flush();
					removeCount++;
				}
			}
			cout << "After remove " << removeCount << " items --> ";
			cout << "size: " << V->size() << ",  height=" << V->height();
			cout.flush();
			delete V;
		}
		cout << "\n\nBST, AVL remove test is done!" << endl;
}

void traversalTest(BST<std::string> *T) {
	cout << "\n\nInorder:    ";
	printArray(T->inorder(),20,T->size());
	cout << "\nPreorder:   ";
	printArray(T->preorder(),20,T->size());
	cout << "\nPostorder:  ";
	printArray(T->postorder(),20,T->size());
	cout << "\n\n";
}

void removingTest(BST<std::string> *T) {
	std::string *a = T->inorder();
	int removeCount=0, n = T->size();
	cout << "Removing: ";
	for (int k=0; k<20; k++) {
		int key=toint(*(a+rand()%n));
		cout << "-" << key;
		if (T->remove(key) != NULL)
			removeCount++;
	}
	cout << "\nAfter remove " << removeCount << ",  size=" << T->size() << ",  height=" << T->height() << " --> " ;
	printArray( T->inorder(),20,T->size());
	cout << endl;
	randomadd(T,5,1000);
	cout << " --> ";
	a = T->inorder();
	printArray(a,20,T->size());
	a = T->preorder();
	n = T->size();
	cout << "\nRemoving: ";
	for (int k=0; k<n; k++) {
		int key=toint(*(a+k));
		cout << "-" << key;
		if (T->remove(key) != NULL)
			removeCount++;
	}
	cout << "\nAfter remove " << removeCount << ",  size=" << T->size() << ",  height=" << T->height() << " --> " ;
	printArray( T->inorder(),20,T->size());
}

void standard_test(BST<std::string> *T) {
	BST <std::string> B,A(*T); // copy constructor;
    	B = A;                    // = operator;
	cout << endl;
	randomadd(T,T->size(),1000); // double the size of the tree T
	cout << "\nSize=" << T->size() << " Max=" << *T->max() << " Min=" << *T->min() << " Height=" << T->height();
	traversalTest(T);
	removingTest(T);
	cout << "\n\nOld copy of T in A :";
	printArray(A.inorder(),20,A.size());
	cout << "size=" << A.size() << " height="  << A.height() << endl;;
	cout << "Old copy of T in B :";
	printArray(B.inorder(),20,B.size());
	cout << "size=" << B.size() << " height="  << B.height() << endl;;
}

void height_test() {
	cout << "\n***** BST, AVL height test *****";
	BST<string> *B ;
	AVL<string> *V;

	int n=(int)5E5;
	for (int i=1;i<=5;i++) {
	    B = new BST<string>();
		V = new AVL<string>();
		cout <<  "\nTest " << i << ":";
		for (int k=0; k<n; k++) {
			int key=rand();
			B->insert(key,tostring(key));
			V->insert(key,tostring(key));
		}
		string *a = B->inorder();

		cout <<  "\nBST size=" << B->size() << ",  height=" << B->height() << "  => ";
		printArray(a,10,B->size());
		cout <<  "\nAVL size=" << V->size() << ",  height=" << V->height() << "  => ";
		printArray(V->inorder(),10,V->size());

		int removeCount=0;
		for (int k=0; k<n*2; k++) {
			int key=toint(*(a+rand()%n));
			V->remove(key);
			if (B->remove(key) != NULL)
				removeCount++;
		}
		cout << "\nAfter remove " << removeCount << " items";
		cout <<  "\nBST size=" << B->size() << ",  height=" << B->height() << "  => ";
		printArray(B->inorder(),10,B->size());
		cout <<  "\nAVL size=" << V->size() << ",  height=" << V->height() << "  => ";
		printArray(V->inorder(),10,V->size());
		cout << endl;
		cout.flush();
		delete B;
		delete V;
	}
}




int main() {
	srand(12345);

//	debugging_test();

	BST<std::string> *T;
	cout << "***  Standard Test on BST ***\n\n";
	T= new BST<std::string>();  randomadd(T,10,1000);  standard_test(T);
	cout << "\n\n***  Standard Test on AVL ***\n\n";
    	T= new AVL<std::string>();	randomadd(T,10,1000);  standard_test(T);
	height_test();
	cout << "\nBST, AVL Test is done!" << endl;
	return 0;
}





