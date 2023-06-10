#include <iostream>
using namespace std;

class BST {

private:
	int data;
	BST* left;
	BST* right;

public:

	BST(): data(0), left(nullptr), right(nullptr) {}

	explicit BST(int dataG) : data(dataG), left(nullptr), right(nullptr) {}


	BST* insertNode(BST* root, int data) {
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


	BST* findMinValue(BST* root) {
		if (!root) {
			return nullptr;
		}

		BST* current = root;
		while (current->left) {
			current = current->left;
		}

		return current;
	}


	BST* deleteNode(BST* root, int nodeToDelete) {
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
			if (root->left == nullptr && root->right == nullptr) {
				return NULL;
			}
			else if (root->left == nullptr) {
				BST* temp = root->right;
				delete root;
				return temp;
			}
			else if (root->right == nullptr) {
				BST* temp = root->left;
				delete root;
				return temp;
			}
			BST* node = findMinValue(root->right);
			root->data = node->data;
			root->right = deleteNode(root->right, node->data);
		}
		return root;
	}

	void inorderTraversal(BST* root) {
		if (!root) {
			return;
		}

		inorderTraversal(root->left_);
		std::cout << root->data_ << " ";
		inorderTraversal(root->right_);
	}
};
