#pragma once
#include "./max_heap.h"

//priority queues are strongly realated to heaps, and the most common implementatios includes max heap

/*
Use cases:
 - Dijkstra's Algorithm for Shortest Path Finding
 - Event-driven Simulation
 - Network Traffic Management
 - Task Scheduling and Job Prioritization
 - Job Scheduling in Cloud Computing
*/


template<typename T>
class PriorityQueue {
private:
	MaxHeap<T> maxHeap;

public:
	PriorityQueue() : maxHeap(MaxHeap<T>()) {}
	PriorityQueue(int cap) : maxHeap(MaxHeap<T>(cap)) {}

	void insert(const T& data, int priority) {
		maxHeap.insert(data, priority);
	}

	void insert(const T& data) {
		maxHeap.insert(data);
	}

	void clear() {
		maxHeap.clear();
	}

	void remove() {
		maxHeap.remove();
	}

	bool isEmpty() const {
		return maxHeap.isEmpty();
	}

	std::size_t size() const {
		return maxHeap.size();
	}

	const T& peek() const {
		return maxHeap.peek();
	}

	void logHeap() const {
		maxHeap.logHeap();
	}
};