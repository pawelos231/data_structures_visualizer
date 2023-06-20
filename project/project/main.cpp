#define RAYGUI_IMPLEMENTATION
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#include "./GUI/window.h"
#include "./structures/hash_map.h"
#include "./structures/linked_list.h"
#include "./structures/min_heap.h"
#include <iostream>

const char* STRUCTURES[] = {
	"Linked list",
	"Stack",
	"Queue",
	"Disjoint set",
	"BST",
	"AVL",
	"BIT",
	"PAT",
	"Trie",
	"k-d tree"
};

int main(void)
{
	MinHeap<std::string>* min = new MinHeap<std::string>();

	min->insert("siema6", 8);
	min->insert("siema5", 4);
	min->insert("siema4", 3);
	min->insert("siema3", 2);
	min->insert("siema2", 6);
	min->insert("siema9", 22);
	min->insert("siema8", 63);
	min->insert("siema7", 14);
	min->insert("siema1", 1);
	min->remove();

	min->LogHeap();

	std::cout << min->peek() << std::endl;
	return 0;
}