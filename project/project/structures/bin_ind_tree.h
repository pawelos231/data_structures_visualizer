#pragma once

//also known as fenwick tree



class FenwickTree {

private:
	std::vector<int> tree;
	int size;

public:
	FenwickTree(int size) {};
	void update(int index, int delta) {};
	int query(int index) {};
	int getRangeSum(int startIndex, int endIndex) {};
	int getAtIndex(int index) {};
	void setAtIndex(int index, int value) {};
	std::vector<int> getTreeArray() {};
	int getSize() {};
	static FenwickTree buildFromArray(const std::vector<int>& array) {};

};