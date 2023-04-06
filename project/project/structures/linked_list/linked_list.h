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
	LinkedList();
	void push_node(T data);
	void insert_node(int PointToInsert, T data);
	void log_nodes();
	void delete_node(int nodeToDelete);
};