#define RAYGUI_IMPLEMENTATION
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#include "./structures/avl_tree.h"
#include <iostream>
#include <cstdlib> 

int main(void)
{
	AVLTree<int>* avl = new AVLTree<int>(1);

	avl->insert(avl, 10);
	avl->insert(avl, 143);
	avl->insert(avl, 12);
	avl->insert(avl, 13);
	avl->insert(avl, 1421);
	avl->insert(avl, 2);
	avl->insert(avl, 142);
	avl->insert(avl, 5);


	avl->inorderTraversal(avl);

	return 0;
}