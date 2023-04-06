#pragma once

#include<iostream>
#include "../mem/named_ptr.h"

const char* INVALID_INDEX = "Index out of range";

template <typename T>
class LinkedList {
private:
	class Node {
	public:
		T data;
		NamedPtr<Node> next;

		Node() {
			next = NamedPtr<Node>(nullptr);
		};
		Node(T data) {
			this->data = data;
			this->next = nullptr;
		}

	};
	NamedPtr<Node> head;
	int len;
public:
	LinkedList() {
		head = NamedPtr<Node>(nullptr);
	}

	int length() {
		return len;
	}

	void push(T data) {

		NamedPtr<Node> newNode(new Node(data));
		NamedPtr<Node> temp = head;

		len++;

		if (head.get() == nullptr) {
			head = newNode;
			return;
		}

		while (temp.get() != nullptr && temp.get()->next.get() != nullptr) {
			temp = temp->next;
		}

		temp->next = newNode;
	};

	void insert(int index, T data) {
		NamedPtr<Node> newNode = NamedPtr<Node>(new Node(data));
		NamedPtr<Node> temp = head;
		NamedPtr<Node> temp2 = NamedPtr<Node>(nullptr);
		int helperValue = 0;

		if (head.get() == nullptr) {
			head = newNode;
		}

		while (temp.get() != nullptr) {
			temp = temp.get()->next;
			helperValue++;
		}

		if (helperValue < index || index < 0) {
			throw std::out_of_range(INVALID_INDEX);
		}

		temp = head;

		for (int i = 0; i < index - 1; i++) {
			temp2 = temp;
			temp = temp.get()->next;
		}

		if (temp2.get() == nullptr || temp2.get()->next == nullptr) {
			return;
		}

		temp2->next = newNode;
		newNode->next = temp;
		len++;
	};

	void remove(int index) {
		NamedPtr<Node> temp = head;
		NamedPtr<Node> temp2;

		if (len <= index) {
			throw std::out_of_range(INVALID_INDEX);
		}

		temp = head;
		if (index == 0) {
			head = head->next;
			len--;
			return;
		}

		for (int i = 0; i < index; i++) {
			temp2 = temp;
			temp = temp->next;
		}

		if (temp2.get() == nullptr || temp2.get()->next.get() == nullptr) {
			return;
		}

		temp2->next = temp->next;
		
		len--;
	};

	void print() {
		std::cout << "[";
		if (head.get() == nullptr) {
			std::cout << "]" << std::endl;
			return;
		}

		NamedPtr<Node> temp = head;
		while (temp.get() != nullptr) {
			std::cout << temp.get()->data << ", ";
			temp = temp->next;
		}

		std::cout << "\b\b]" << std::endl;
	};
};

