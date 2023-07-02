#define RAYGUI_IMPLEMENTATION
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#include "./structures/binary_search_tree.h"
#include <iostream>

int main(void)
{
	BST* bst = new BST();
	for (int i = 0; i < 10; i++) {
		bst->insertNode(bst, i);
	}
	bst->levelOrderTraversal(bst);
	

	return 0;
}