#pragma once
#include <vector>
#include <type_traits>


template<typename T>
class minHeap {
	std::vector<T> heap;

public:

	struct PriorityItem {
		int priority;
		T data;
	};


	static_assert(std::is_integral_v
	<typename PriorityItem::priority>, "Priority must be an integral type.");

	minHeap() : heap(std::vector<T>()) {}
	minHeap(const std::vector<T>& array) : heap(array) {
		//balance
	}


	void swap() {

	}

	void heapifyUp() {

	}

	std::size_t parentIndex() {

	}


	void rightChildIndex(T index) {

	}

	void leftChildIndex(T index) {


	}

	void heapifyUp() {

	}

	void heapifyDown() {

	}

	void insert(int priority, const T& data) {
		PriorityItem PI{priority,data};
		this->heap.push_back(PI)
	}

	void remove() {

	}

	bool isEmpty() {

	}

	std::size_t size() {
		return this->heap.size();
	}

	const T& peek() const {
		if (heap.empty()) {
			throw std::logic_error("Heap is empty");
		}
		return this->heap.front().data;
	}
};