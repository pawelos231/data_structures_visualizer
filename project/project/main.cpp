#define RAYGUI_IMPLEMENTATION
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#include "./structures/binary_search_tree.h"
#include <iostream>
#include <cstdlib> // Include the library for rand()

int main(void)
{
	BST* bst = new BST(1);

	bst->insertNode(bst, 10);
	bst->insertNode(bst, 143);
	bst->insertNode(bst, 12);
	bst->insertNode(bst, 13);
	bst->insertNode(bst, 1421);
	bst->insertNode(bst, 2);
	bst->insertNode(bst, 142);
	bst->insertNode(bst, 5);


	bst->levelOrderTraversal(bst);

	return 0;
}