#pragma once
#include <vector>
#include <type_traits>


template<typename T>
class minHeap {


	struct PriorityItem {
		int priority;
		T data;
	};

	std::vector<PriorityItem> heap;

public:



	minHeap() : heap(std::vector<PriorityItem>()) {}
	minHeap(const std::vector<PriorityItem>& array) : heap(array) {
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

	void heapifyDown() {

	}


	template <typename U = T>
	typename std::enable_if<!std::is_integral<U>::value>::type
	insert(const T& data, int priority) {
		PriorityItem PI{ priority, data };
		this->heap.push_back(PI);
	}

	template <typename U = T>
	typename std::enable_if<std::is_integral<U>::value>::type
	insert(const T& data) {
		std::cout << "siema" << std::endl;
		PriorityItem PI{ 0, data };  
		this->heap.push_back(PI);
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