#define RAYGUI_IMPLEMENTATION
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#include "./GUI/window.h"
#include "./structures/trie.h"
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
	Trie trie;
	trie.insert("apple");
	trie.insert("apply");
	trie.insert("banana");

	bool hasPrefix = trie.startsWith("app"); 
	bool hasPrefix2 = trie.startsWith("ban"); 
	bool hasPrefix3 = trie.startsWith("foo");
	std::cout << hasPrefix << hasPrefix2 << hasPrefix3 << std::endl;
	return 0;
}