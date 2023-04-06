#pragma once
#include<iostream>


template <typename T>
class LinkedList {
private:
	class Node {
	public:
		T data;
		Node* next;
		Node() {
			data = 0;
			next = NULL;
		};
		Node(int data) {
			this->data = data;
			this->next = NULL;
		}
	};
	Node* head;
public:
	LinkedList() {
		head = NULL;
	}
	void push_node(T data) {
		Node* newNode = new Node(data);
		Node* temp = head;

		if (head == NULL) {
			head = newNode;
			return;
		}

		while (temp != NULL && temp->next != NULL) {
			temp = temp->next;
		}

		temp->next = newNode;
	};
	void insert_node(int PointToInsert, T data) {

		Node* newNode = new Node(data);
		Node* temp = head;
		Node* temp2 = NULL;
		int helperValue = 0;

		if (head == NULL) {
			head = newNode;
		}
		while (temp != NULL) {
			temp = temp->next;
			helperValue++;
		}
		if (helperValue < PointToInsert || PointToInsert < 0) {
			std::cout << "the given number is too large or too small" << std::endl;
			return;
		}
		temp = head;

		for (int i = 0; i < PointToInsert - 1; i++) {
			temp2 = temp;
			temp = temp->next;
		}
		if (temp2 == NULL || temp2->next == NULL) {
			return;
		}
		temp2->next = newNode;
		newNode->next = temp;
	};
	void log_nodes() {
		if (head == NULL) {

			std::cout << "empty list" << std::endl;
			return;
		}
		Node* temp = head;
		while (temp != NULL) {
			std::cout << temp->data << std::endl;
			temp = temp->next;
		}
	};
	void delete_node(int nodeToDelete) {
		Node* temp = head;
		Node* temp2 = NULL;
		int LinkedListLen = 0;
		if (head == NULL) {
			std::cout << "empty list" << std::endl;
			return;
		}
		while (temp->next != NULL) {
			temp = temp->next;
			LinkedListLen++;
		}
		if (LinkedListLen < nodeToDelete) {
			std::cout << "too large number" << std::endl;
			return;
		}

		temp = head;
		if (nodeToDelete == 1) {
			head = head->next;
			delete temp;
			return;
		}
		for (int i = 0; i < nodeToDelete; i++) {
			temp2 = temp;
			temp = temp->next;
		}
		if (temp2 == NULL || temp2->next == NULL) {
			return;
		}

		temp2->next = temp->next;
		delete temp;

	};
};

