/*
 * AVL.h
 *
 *
 *  Created on: Feb 28, 2016
 *      Author: cli2
 */

/*
 * If students want to implement AVL remove method, they have to un-comment the two methods and check
 * necessary rotations.
 */

#ifndef AVL_H_
#define AVL_H_

#include "BST.h"

enum Rotation {NoRotation, LL, LR, RR, RL};

/*******************************************************/
/*   AVL Tree                         by Chung-Chih Li */
/*******************************************************/
template<typename T>
class AVL: public BST<T>  { // inherit BST
	public:
		AVL();	           // default constructor
		void insert(int key, T data);
		//T *remove(int key);  //remove data with key and return the removed data's reference

		AVL<T> & operator = (const AVL<T> & a); // Big Three
		AVL(const AVL<T> & RT);
		~AVL();

	private:// Students can add or remove any private methods as wish
		//void remove(TreeNode<T> *node);
		void rotate(TreeNode<T> *node);
};

#endif /* AVL_H_ */
