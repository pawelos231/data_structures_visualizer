#define RAYGUI_IMPLEMENTATION
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#include "./structures/trie.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main(void)
{

	Trie trie;

	trie.insert("apple");
	trie.insert("banana");
	trie.insert("app");

	cout << trie.search("apple") << endl;       // Output: 1 (true)
	cout << trie.search("banana") << endl;      // Output: 1 (true)
	cout << trie.search("app") << endl;         // Output: 1 (true)
	cout << trie.search("dog") << endl;         // Output: 0 (false)

	trie.remove("apple");
	cout << trie.search("apple") << endl;       // Output: 0 (false)
	cout << trie.search("app") << endl;         // Output: 1 (true)

	trie.remove("banana");
	cout << trie.search("banana") << endl;      // Output: 0 (false)

	return 0;
}