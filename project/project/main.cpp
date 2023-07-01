#define RAYGUI_IMPLEMENTATION
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#include "./GUI/window.h"
#include "./structures/trie.h"
#include "./vmem/vmem.h";
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
	vmem<512> memory;

	auto trie_mem = memory.allocate<Trie>();
	if (trie_mem) {
		Trie& trie = **trie_mem;
		trie.insert("apple");
		trie.insert("apply");
		trie.insert("banana");

		bool hasPrefix = trie.startsWith("app");
		bool hasPrefix2 = trie.startsWith("ban");
		bool hasPrefix3 = trie.startsWith("foo");
		std::cout << hasPrefix << hasPrefix2 << hasPrefix3 << std::endl;
	}
	else {
		std::cout << "cringe not enough memory to make a trie :(" << std::endl;
	}

	return 0;
}