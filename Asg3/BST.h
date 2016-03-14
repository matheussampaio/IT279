/*
 * BST.h
 *
 *  Created on: Feb 28, 2016
 *      Author: cli2
 */

/*
 * Students should not modify the public section of this class declaration.
 */

#ifndef BST_H_
#define BST_H_

#include "map.cpp"
#include "treeNode.cpp"

/*******************************************************/
/*  Binary Search Tree               by  Chung-Chih Li */
/*******************************************************/
template<typename T>
class BST : public map<T> {
	protected:
		int n;
		TreeNode<T> *root;

	public:
		BST();
		void insert(int key, T data);
		T *remove(int key);  // remove data with key and return the removed data's reference 
		T *get(int key); // Get the reference of the data with key vaule 
		int size();    // Return the number of items(data) stored in the tree
		int height();  // Return the height of the tree
		T *max();      // Return the reference of the data with the largest key vaule 
		T *min();      // Return the reference of the data with the smalles key vaule 
		T *toArray();  // Return an array of all data in ascending order

		T *inorder();  // Return an array of all data in inorder
		T *preorder(); // Return an array of all data in preorder
		T *postorder();// Return an array of all data in postorder

		BST<T> & operator = (const BST<T> & a); // Big Three
		BST(const BST<T> & t);
		~BST();

		int test();    // Students can design this method for their own debugging purpose. 

	private: // Students can add or remove any private methods as wish
		void remove(TreeNode<T> *node);
};

#endif /* BST_H_ */
