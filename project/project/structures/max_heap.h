#pragma once
#include <vector>
#include <type_traits>
#include <stdexcept>
#include <string>
#include <iostream>

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


	void swap(int index1, int index2) {
		std::swap(heap[index1], heap[index2]);
	}

	void heapifyUp(int index) {

		int parentIndex = getParentIndex(index);
		if (parentIndex >= 0 && heap[index].priority > heap[parentIndex].priority) {
			swap(parentIndex, index);
			heapifyUp(parentIndex);
		}
	}

	void heapifyDown(int index) {
		int leftChildIndex = getLeftChildIndex(index);
		int rightChildIndex = getRightChildIndex(index);
		int smallest = index;

		if (leftChildIndex < heap.size() && heap[leftChildIndex].priority > heap[smallest].priority) {
			smallest = leftChildIndex;
		}

		if (rightChildIndex < heap.size() && heap[rightChildIndex].priority > heap[smallest].priority) {
			smallest = rightChildIndex;
		}

		if (smallest != index) {
			swap(smallest, index);
			heapifyDown(smallest);
		}
	}

	const int getParentIndex(int childIndex) const {
		return (childIndex - 1) / 2;
	}


	const int getRightChildIndex(int parentIndex) const {
		return 2 * parentIndex + 2;
	}

	const int getLeftChildIndex(int parentIndex) const {
		return 2 * parentIndex + 1;
	}



	template <typename U = T>
	typename std::enable_if<!std::is_integral<U>::value>::type
		insert(const T& data, int priority) {
		PriorityItem PI{ priority, data };
		this->heap.push_back(PI);
		if (heap.size() > 1) {
			this->heapifyUp(heap.size() - 1);
		}
	}

	template <typename U = T>
	typename std::enable_if<std::is_integral<U>::value>::type
		insert(const T& data) {
		PriorityItem PI{ data, data };  //for now
		this->heap.push_back(PI);
		if (heap.size() > 1) {
			this->heapifyUp(heap.size() - 1);
		}
	}

	void clear() {
		this->heap.clear();
	}

	void remove() {
		if (heap.empty()) {
			throw std::logic_error("Heap is empty");
		}
		heap[0] = heap.back();
		heap.pop_back();
		if (!heap.empty()) {
			heapifyDown(0);
		}
	}

	const bool isEmpty() const {
		return heap.empty();
	}

	const std::size_t size() const {
		return this->heap.size();
	}

	const T& peek() const {
		if (heap.empty()) {
			throw std::logic_error("Heap is empty");
		}
		return this->heap.front().data;
	}

	void logHeap() const {
		for (const auto& item : heap) {
			std::cout << item.priority << ": " << item.data << std::endl;
		}
	}

};
