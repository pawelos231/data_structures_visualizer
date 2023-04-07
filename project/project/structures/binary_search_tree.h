#include <iostream>
using namespace std;

class BST {

private:
	int data;
	BST* left;
	BST* right;

public:

	BST() {
		this->data = 0;
		this->left = nullptr;
		this->right = nullptr;
	}

	BST(int dataGiven) {
		this->data = dataGiven;
		this->left = nullptr;
		this->right = nullptr;
	}

	BST* insert_node(BST* root, int data) {
		if (!root) {
			return new BST(data);
		}
		if (data > root->data) {
			root->right = insert_node(root->right, data);
		}
		else if (data < root->data) {
			root->left = insert_node(root->left, data);
		}
		return root;
	}

	BST* find_right_min_val(BST* curr) {
		//iterating to the utmost left leaf
		BST* temp = curr;
		while (curr != NULL && curr->left != NULL) {
			curr = curr->left;
		}
		return curr;
	}

	BST* delete_node(BST* root, int nodeToDelete) {
		if (!root) {
			return NULL;
		}
		if (nodeToDelete < root->data) {
			root->left = delete_node(root->left, nodeToDelete);
		}
		else if (nodeToDelete > root->data) {
			root->right = delete_node(root->right, nodeToDelete);
		}
		else {
			if (root->left == NULL && root->right == NULL) {
				return NULL;
			}
			else if (root->left == NULL) {
				BST* temp = root->right;
				delete root;
				return temp;
			}
			else if (root->right == NULL) {
				BST* temp = root->left;
				delete root;
				return temp;
			}
			BST* node = find_right_min_val(root->right);
			root->data = node->data;
			root->right = delete_node(root->right, node->data);
		}
		return root;
	}

	void InorderTraversal(BST* root) {
		if (root == NULL) {
			return;
		}
		InorderTraversal(root->left);
		InorderTraversal(root->right);
	}
};
