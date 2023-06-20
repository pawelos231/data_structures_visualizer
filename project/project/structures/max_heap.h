#pragma once
#include <vector>
#include <type_traits>
#include <stdexcept>
#include <string>

template<typename T>
class MaxHeap {

private:
	int capacity;
	struct PriorityItem {
		int priority;
		T data;
	};
	std::vector<PriorityItem> heap;

public:
	static const std::size_t DEFAULT_CAP = 100;
	MaxHeap() : heap(std::vector<PriorityItem>()), capacity(DEFAULT_CAP) {}
	MaxHeap(int cap) : capacity(cap) {}
	MaxHeap(const std::vector<PriorityItem>& array) : heap(array) {
		//balance
	}

};