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
	minHeap<std::string>* min = new minHeap<std::string>();

	min->insert("siema", 1);
	min->insert("siema", 2);
	min->insert("siema", 3);
	std::cout << min->peek() << std::endl;
	return 0;
}