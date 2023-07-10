#pragma once
#include <vector>
#include <iostream>
//also known as fenwick tree
//Fenwick Trees excel when you have a significant number of updates or require frequent prefix sum calculations efficiently.
//negative numbers -> two complement, flip all the bits and add one

class FenwickTree {

private:
	std::vector<int> tree;
	int size;

public:
	FenwickTree(int size): size(size) {
		this->tree.resize(size + 1, 0);
	};
	FenwickTree(std::vector<int>& arr) : tree(arr), size(arr.size() -1 ) {
		this->tree = this->buildFromArray(arr);
	};

	void update(int index, int delta) {
		while (index <= this->size) {
			this->tree[index] += delta;
			index += index & -index;
		}

	};

	const int query(int index) {
		int sum = 0;
		while (index > 0) {
			sum += tree[index];
			index -= index & -index;
		}
		return sum;
	};

	int getRangeSum(int startIndex, int endIndex) {
		return query(endIndex) - query(startIndex - 1);
	}

	int getAtIndex(int index) {
		return query(index) - query(index - 1);
	}

	void setAtIndex(int index, int value) {
		int delta = value - getAtIndex(index);
		update(index, delta);
	}

	std::vector<int> getTreeArray() {
		return tree;
	}

	int getSize() {
		return size;
	}

	std::vector<int> buildFromArray(const std::vector<int>& array) {
		int size = array.size();
		std::vector<int> tree(array);
		tree.resize(size + 1, 0);

		for (int i = 1; i < size; i++) {
			int p = i + (i & -i);
			if (p < size) {
				tree[p] = tree[i] + tree[p];
			}
		}

		return tree;
	}

	void logTree() {
		for (int i = 0; i <= size; i++) {
			std::cout << this->tree[i] << std::endl;
		}
	}

};