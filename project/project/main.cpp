#define RAYGUI_IMPLEMENTATION
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#include "./structures/trie.h"
#include <iostream>
#include <cstdlib> 

int main(void)
{

	Trie tr;
	tr.insert("apple");
	std::cout<<tr.startsWith("ap")<<std::endl;

	return 0;
}