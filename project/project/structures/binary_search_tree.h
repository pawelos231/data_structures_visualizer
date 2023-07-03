#include <iostream>
#include <queue>

using namespace std;

class BST {

private:
	int data;
	BST* left;
	BST* right;

public:

	BST(): data(0), left(nullptr), right(nullptr) {}
	explicit BST(int dataI) : data(dataI), left(nullptr), right(nullptr) {}


	BST* insertNode(BST* root, int data) {
		if (!root) {
			return new BST(data);
		}
		if (data > root->data) {
			root->right = insertNode(root->right, data);
		}
		else if (data < root->data) {
			root->left = insertNode(root->left, data);
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
		if (!root) return nullptr;

		if (nodeToDelete < root->data) {
			root->left = deleteNode(root->left, nodeToDelete);
		}
		else if (nodeToDelete > root->data) {
			root->right = deleteNode(root->right, nodeToDelete);
		}
		else {
			if (root->left == nullptr && root->right == nullptr) {
				return nullptr;
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
		if (!root)return;

		inorderTraversal(root->left);
		std::cout << root->data << " ";
		inorderTraversal(root->right);
	}

	void preorderTraversal(BST* root) {
		if (!root) return;

		std::cout << root->data << " ";
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}

	void levelOrderTraversal(BST* root) {
		if (root == nullptr) return;
		
		std::queue<BST*> queue;
		queue.push(root);
		while (!queue.empty()) {

			int len = queue.size();
			for (int i = 0; i < len; i++) {
				BST* frontEl = queue.front();
				std::cout << frontEl->data << std::endl;
				queue.pop();
				if (frontEl->left) {
					queue.push(frontEl->left);
				}
				if (frontEl->right) {
					queue.push(frontEl->right);
				}
			}
			
		}
	}
};
