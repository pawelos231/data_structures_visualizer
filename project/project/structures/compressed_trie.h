#include <iostream>
#include <map>

//it is pretty much trie, but compressed, so often instead of singular letters you would get substrings of a given word as a node

/*
Use cases:

- Autocomplete and Text Prediction
- Spell Checking and Dictionary Lookup
- IP Routing and Longest Prefix Match
- Prefix-based Search and Directory Structures
- Auto-correction and Spelling Suggestions in Text Messaging
*/

class TrieNode {
private:
	std::map<char, TrieNode*> children;
	bool endOfWord;

public:
	TrieNode() : endOfWord(false) {}

	bool containsKey(char ch) const {
		return this->children.find(ch) != this->children.end();
	}


	TrieNode* getChild(char ch) const {
		auto it = this->children.find(ch);
		if (it != this->children.end()) {
			return it->second;
		}
		return nullptr;
	}

	TrieNode* insertChild(char ch) {
		TrieNode* newNode = new TrieNode();
		this->children[ch] = newNode;
		return newNode;
	}

	std::map<char, TrieNode*> getChildren() {
		return this->children;
	}

	bool isEnd() const {
		return this->endOfWord;
	}

	void setEnd(bool value) {
		this->endOfWord = value;
	}
};

class CompressedTrie {
	CompressedTrie() {

	}
};