#pragma once
#include <queue>
#include <iostream>
#include <algorithm> 

//BALANCE FACTOR:
//bf = h_l - h_r




template <typename T>
class AVLTree {

	T data;
	AVLTree* left;
	AVLTree* right;
	int height = 1;

public:
	AVLTree() : data(0), left(nullptr), right(nullptr) {}
	explicit AVLTree(int dataI) : data(dataI), left(nullptr), right(nullptr) {}

	int const getHeight(AVLTree* node) const {
		if (node == nullptr) return 0;
		return this->height;
	};

	int const getBalance(AVLTree* node) const {
		if (node == nullptr) return 0;
		return this->getHeight(node->left) - this->getHeight(node->right);
	};

	AVLTree* const leftRotate(AVLTree* node) {
		AVLTree* root = node->right;
		AVLTree* left = node;

		left->right = root->left;
		root->left = left;

		this->updateHeight(node);
		this->updateHeight(root);

		return root;
		
	};

	AVLTree* const rightRotate(AVLTree* node) {

		AVLTree* root = node->left; 
		AVLTree* right = node; 

		right->left = root->right;
		root->right = right;

		this->updateHeight(node);
		this->updateHeight(root);

		return root;
	};

	AVLTree* insert(AVLTree* node, T value) {
		if (node == nullptr) return new AVLTree(value);
		if (value > node->data) {
			node->right = insert(node->right, value);
		}
		if (value < node->data) {
			node->left = insert(node->left, value);
		}
		this->updateHeight(node);
		return this->balance(node);
	};

	AVLTree* remove(AVLTree* root, T value) {
		if (root == nullptr)
			return nullptr;

		if (value < root->data) {
			root->left = remove(root->left, value);
		}
		else if (value > root->data) {
			root->right = remove(root->right, value);
		}
		else {
			if (root->left == nullptr && root->right == nullptr) {
				return nullptr;
			}

			else if (root->left == nullptr) {
				AVLTree* temp = root->right;
				delete root;
				return temp;
			}
			else if (root->right == nullptr) {
				AVLTree* temp = root->left;
				delete root;
				return temp;
			}
			else {
				AVLTree* temp = this->findMinValue(root);
				root->data = temp->data;
				root->right = deleteNode(root->right, temp->data);
			}
		}
		return this->balance(root);
	};

	AVLTree* search(AVLTree* node, T value) {
		if (node == nullptr || node->data == value)
			return node;

		if (value < node->data)
			return search(node->left, value);

		return search(node->right, value);
	}



	void updateHeight(AVLTree* node) {
		node->height = std::max(getHeight(node->left), getHeight(node->right));
	}

	AVLTree* balance(AVLTree* node) {
		this->updateHeight(node);
		node->height = this->getHeight(node);
		int balance = this->getBalance(node);

		if (balance > 1 && this->getBalance(node->left) >= 0) {
			return this->rightRotate(node);
		}
		if (balance < -1 && this->getBalance(node->right) <= 0) {
			return this->leftRotate(node);
		}
		if (balance < -1 && this->getBalance(node->right) > 0) {
			node->right = this->rightRotate(node->right);
			return this->leftRotate(node);
		}
		if (balance > 1 && this->getBalance(node->left) < 0) {
			node->left = leftRotate(node->left);
			return this->rightRotate(node);
		}
		return node;
	}

	AVLTree* findMinValue(AVLTree* root) {
		if (!root) {
			return nullptr;
		}

		AVLTree* current = root;
		while (current->left) {
			current = current->left;
		}

		return current;
	}


	void inorderTraversal(AVLTree* root) const {
		if (!root)return;

		inorderTraversal(root->left);
		std::cout << root->data << " ";
		inorderTraversal(root->right);
	}

	void preorderTraversal(AVLTree* root) const {
		if (!root) return;

		std::cout << root->data << " ";
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}

	void levelOrderTraversal(AVLTree* root) const {
		if (root == nullptr) return;

		std::queue<AVLTree*> queue;
		queue.push(root);
		while (!queue.empty()) {

			int len = queue.size();
			for (int i = 0; i < len; i++) {
				AVLTree* frontEl = queue.front();
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
