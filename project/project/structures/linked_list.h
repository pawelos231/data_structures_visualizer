#pragma once
#include<iostream>

const char* INVALID_INDEX = "Index out of range";



template <typename T>
class SinglyLinkedList {
private:
	class Node {
	public:
		T data;
		Node* next;

		Node() : next(nullptr) {}
		explicit Node(T data) : data(data), next(nullptr) {}

	};
	Node* head;
	int len;
public:

	SinglyLinkedList() : head(nullptr), len(0) {}


	int length() const {
		return len;
	}

	void push(T data) {
		Node* newNode(new Node(data));
		Node* temp(head);

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
		Node* temp = head;
		while (temp != nullptr) {
			std::cout << temp->data << ", ";
			temp = temp->next;
		}

		std::cout << "\b\b]" << std::endl;
	};
};


template <typename T>
class DoublyLinkedList {
private:
	class Node {
	public:
		T data;
		Node* prev;
		Node* next;

		Node() : prev(nullptr), next(nullptr) {}
		explicit Node(T data) : data(data), prev(nullptr), next(nullptr) {}
	};

	Node* head;
	Node* tail;
	int len;

public:
	DoublyLinkedList() : head(nullptr), tail(nullptr), len(0) {}

	int length() const {
		return len;
	}

	void push(T data) {
		Node* newNode = new Node(data);

		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
		}

		len++;
	}

	void insert(int index, T data) {
		if (index < 0 || index > len) {
			throw std::out_of_range("Invalid index");
		}

		if (index == len) {
			push(data);
			return;
		}

		Node* newNode = new Node(data);

		if (index == 0) {
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
		else {
			Node* temp = head;
			for (int i = 0; i < index - 1; i++) {
				temp = temp->next;
			}

			newNode->prev = temp;
			newNode->next = temp->next;
			temp->next->prev = newNode;
			temp->next = newNode;
		}

		len++;
	}

	void remove(int index) {
		if (index < 0 || index >= len) {
			throw std::out_of_range("Invalid index");
		}

		Node* temp = head;

		if (index == 0) {
			head = head->next;
			if (head != nullptr) {
				head->prev = nullptr;
			}
			else {
				tail = nullptr;
			}
		}
		else if (index == len - 1) {
			temp = tail;
			tail = tail->prev;
			tail->next = nullptr;
		}
		else {
			for (int i = 0; i < index; i++) {
				temp = temp->next;
			}
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
		}

		delete temp;
		len--;
	}

	void print() {
		std::cout << "[";
		Node* temp = head;
		while (temp != nullptr) {
			std::cout << temp->data;
			if (temp->next != nullptr) {
				std::cout << ", ";
			}
			temp = temp->next;
		}
		std::cout << "]" << std::endl;
	}
};