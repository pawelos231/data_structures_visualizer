#define RAYGUI_IMPLEMENTATION
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#include "./GUI/window.h"
#include "./structures/max_heap.h"
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
	MaxHeap<std::string>* max = new MaxHeap<std::string>();

	max->insert("siema8", 63);
	max->insert("siema6", 8);
	max->insert("siema5", 4);
	max->insert("siema4", 3);
	max->insert("siema3", 2);
	max->insert("siema2", 6);
	max->insert("siema9", 22);
	max->insert("siema7", 14);
	max->insert("siema1", 1);

	max->logHeap();

	std::cout << max->peek() << std::endl;
	return 0;
}