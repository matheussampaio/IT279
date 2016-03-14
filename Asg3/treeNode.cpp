/*
 * Students don't have to use this class, you can design your own.
 *
 * treeNode.cpp
 *
 *  Created on: Feb 28, 2016
 *      Author: cli2
 */
/*
 * This is just a sample implementation of treeNode<T> class. Students are free to design your own tree node, but
 * the file name and the class name have to be the same, i.e., treeNode.cpp and TreeNode. For example, one probably
 * doesn't want to maintain the parent link. That is equally good, as long as one can manage to trace the
 * parent node.
 */

#include <iostream>
#include <cstdlib>
using namespace std;

/*******************************************************/
/*   Node for Tree                   by  Chung-Chih Li */
/*******************************************************/
template<typename T>
class TreeNode {
	public:
		T data;

		TreeNode(int key, T data) {
			height = 1;
			this->key  = key;
			this->data = data;
			parent=left=right=NULL;
		}

		int getKey() {
			return key;
		}

		int getHeight() {
			return height;
		}

		TreeNode<T> *getLeft() {
			return left;
		}

		TreeNode<T> *getRight() {
			return right;
		}

		TreeNode<T> *getParent() {
			return parent;
		}

		void setKey(int key) {
			this->key = key;
		}

		void setHeight(int h) {
					this->height = h;
		}

		void setLeft(TreeNode<T> *node) {
			this->left = node;
			if (node != NULL) node->parent = this;
			updateHeight(this);
		}

		void setRight(TreeNode<T> *node) {
			this->right = node;
			if (node != NULL) node->parent = this;
			updateHeight(this);
		}

		void setParent(TreeNode<T> *node)  {
			this->parent = node;
		}

		~TreeNode() {
		}


	private:
		int key;
		int height;
		TreeNode *parent, *left, *right;

		static void updateHeight(TreeNode<T> *node) {
			if (node == NULL) return;
			int R = (node->right == NULL ? 0 : node->right->height);
			int L = (node->left == NULL ? 0 : node->left->height);
			int H = 1 + (R>L ? R : L);
			if (H != node->height) {
				node->height = H;
				updateHeight(node->parent);
			}
		}
};
