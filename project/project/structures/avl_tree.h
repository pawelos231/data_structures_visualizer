#pragma once
#include <algorithm>
#include <queue>


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
		return this.getHeight(node->left) - this.getHeight(node->right);
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
			insert(node->right, value);
		}
		if (value < node->data) {
			insert(node->left, value);
		}
		return node;
	};
	AVLTree* remove(T value) {

	};
	AVLTree* search(T value) {};



	void updateHeight(AVLTree* node) {
		node->height  =
		std::max(this->getHeight(node.left), this->getHeight(node.right))
	}

	AVLTree* balance(AVLTree* node) {
		node->height = this->getHeight(node);
		int balance = this->getBalance(node) + 1;

		if (balance > 1 && this->getBalance(node->left) >= 0) {
			return rightRotate(node);

		}
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
