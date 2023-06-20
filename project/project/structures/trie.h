#include <iostream>
#include <map>


/*
Use cases:

- Autocomplete and Text Prediction
- Spell Checking and Dictionary Lookup
- IP Routing and Longest Prefix Match
- Prefix-based Search and Directory Structures
- Auto-correction and Spelling Suggestions in Text Messaging
*/

template<typename T>
class Node {
private:
	std::map<std::string, T> children;
	bool endOfWord;

public:
	Node(): endOfWord(false) {}
};

template<typename T>
class Trie {

private:
	Node<T>* node;

public:

	Trie() : node(new Node<T>()) {}

	void insert() {

	}

	bool search() {

	}

	bool startsWith() {

	}

};