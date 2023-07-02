#pragma once

template <typename T>
class AVLTree {

	T data;
	AVLTree* left;
	AVLTree* right;

	AVLTree() : data(0), left(nullptr), right(nullptr) {}
	explicit AVLTree(int dataI) : data(dataI), left(nullptr), right(nullptr) {}



};