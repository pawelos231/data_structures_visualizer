#pragma once
#include <vector>
//also known as fenwick tree
//Fenwick Trees excel when you have a significant number of updates or require frequent prefix sum calculations efficiently.
//negative numbers -> two complement, flip all the bits and add one

class FenwickTree {

private:
	std::vector<int> tree;
	int size;

public:
	FenwickTree(int size) {};

	void update(int index, int delta) {
		while (index <= this->size) {
			this->tree[index] += delta;
			index += index & -index;
		}

	};

	const int query(int index) {
		int sum = 0;
		while (index) {
			this->sum += tree[index];
			index -= index & -index;
		}
		return sum;
	};

	int getRangeSum(int startIndex, int endIndex) {};
	int getAtIndex(int index) {};
	void setAtIndex(int index, int value) {};
	std::vector<int> getTreeArray() {};
	int getSize() {};
	static FenwickTree buildFromArray(const std::vector<int>& array) {};

};