#pragma once
#include <iostream>
#include <vector>

template <typename T>
class Stack {
private:
	std::vector<T> elements;

public:
	void push(const T& element) {
		elements.push_back(element);
	}

	const T pop() {
		if (empty()) {
			throw std::out_of_range("Stack is empty");
		}
		T element = elements.back();
		elements.pop_back();
		return element;
	}

	const T top() const {
		if (empty()) {
			throw std::out_of_range("Stack is empty");
		}
		return elements.back();
	}

	const size_t size() const {
		return elements.size();
	}

	const bool empty() const {
		return elements.empty();
	}
};