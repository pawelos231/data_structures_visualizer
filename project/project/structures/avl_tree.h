#pragma once

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

		//updateHeight(node);
		//updateHeight(root);

		return root;
		
	};

	AVLTree* const rightRotate() {

		AVLTree* root = node->left; 
		AVLTree* right = node; 

		right->left = root->right;
		root->right = right;


		//updateHeight(node);
		//updateHeight(root);

		return root;
	};
	AVLTree* insert(T value);
	AVLTree* remove(T value);
	AVLTree* search(T value);
	void preOrderTraversal() const;
	void inOrderTraversal() const;
	void postOrderTraversal() const;

};
