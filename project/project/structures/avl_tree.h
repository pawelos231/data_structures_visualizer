#pragma once

#pragma once

template <typename T>
class AVLTree {

	T data;
	AVLTree* left;
	AVLTree* right;

public:
	AVLTree() : data(0), left(nullptr), right(nullptr) {}
	explicit AVLTree(int dataI) : data(dataI), left(nullptr), right(nullptr) {}

	int getHeight() const;
	int getBalance() const;
	AVLTree* rightRotate();
	AVLTree* leftRotate();
	AVLTree* insert(int value);
	AVLTree* remove(int value);
	AVLTree* search(int value);
	void preOrderTraversal() const;
	void inOrderTraversal() const;
	void postOrderTraversal() const;

};
