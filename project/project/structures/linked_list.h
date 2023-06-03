#pragma once
#include<iostream>
#include "../mem/named_ptr.h"

const char* INVALID_INDEX = "Index out of range";

template <typename T>
class SinglyLinkedList {
private:
	class Node {
	public:
		T data;
		NamedPtr<Node> next;

		Node() {
			next = nullptr;
		};

		Node(T data) {
			this->data = data;
			this->next = nullptr;
		}
	};
	NamedPtr<Node> head;
	int len;
public:
	SinglyLinkedList() {
		head = nullptr;
	}
	

	int length() {
		return len;
	}

	void push(T data) {
		NamedPtr<Node> newNode(new Node(data));
		NamedPtr<Node> temp(head);

		len++;

		if (head == nullptr) {
			head = newNode;
			return;
		}

		while (temp != nullptr && temp->next != nullptr) {
			temp = temp->next;
		}

		temp->next = newNode;
	};

	void insert(int index, T data) {
		Node* newNode = new Node(data);
		Node* temp = head;
		Node* temp2 = NULL;
		int helperValue = 0;

		if (head == NULL) {
			head = newNode;
		}

		while (temp != nullptr) {
			temp = temp->next;
			helperValue++;
		}

		if (helperValue < index || index < 0) {
			throw std::out_of_range(INVALID_INDEX);
		}

		temp = head;

		for (int i = 0; i < index - 1; i++) {
			temp2 = temp;
			temp = temp->next;
		}

		if (temp2 == nullptr || temp2->next == nullptr) {
			return;
		}

		temp2->next = newNode;
		newNode->next = temp;
		len++;
	};

	void remove(int index) {
		Node* temp = head;
		Node* temp2 = nullptr;

		if (len <= index) {
			throw std::out_of_range(INVALID_INDEX);
		}

		temp = head;
		if (index == 0) {
			head = head->next;
			delete temp;
			len--;
			return;
		}

		for (int i = 0; i < index; i++) {
			temp2 = temp;
			temp = temp->next;
		}

		if (temp2 == nullptr || temp2->next == nullptr) {
			return;
		}

		temp2->next = temp->next;
		delete temp;
		len--;
	};

	void remove_elegant(unsigned int index) {
		if (index >= len)
			throw std::out_of_range(INVALID_INDEX);

		Node** ptr = &head;
		Node* target = head;

		for (int i = 0; i < index; i++)
			target = target->next;

		while (*ptr != target)
			ptr = &(*ptr)->next;

		*ptr = target->next;
		delete target;
		len--;
	};

	void print() {
		std::cout << "[";
		if (head == nullptr) {
			std::cout << "]" << std::endl;
			return;
		}
		NamedPtr<Node> temp = head;
		while (temp != nullptr) {
			std::cout << temp->data << ", ";
			temp = temp->next;
		}

		std::cout << "\b\b]" << std::endl;
	};
};
