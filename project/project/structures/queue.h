#pragma once
#include <vector>
template <typename T>
class QueueArrayBased {
private:
	std::vector<T> queue;
public:

	void enqueue(T item) {
		this->queue.push_back(item);
	}

	const T dequeue() {
		if (this->empty()) {
			throw std::out_of_range("Queue is empty");
		}
		T frontElement = queue.front();
		this->queue.erase(this->queue.begin());
		return frontElement;
	}


	const T front() const {
		if (empty()) {
			throw std::out_of_range("Queue is empty");
		}
		return this->queue.front();
	}

	const size_t size() const {
		return this->queue.size();
	}

	const bool empty() const {
		return this->queue.empty();
	}
};