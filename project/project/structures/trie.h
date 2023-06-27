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

class TrieNode {
private:
	std::map<char, TrieNode*> children;
	bool endOfWord;

public:
	TrieNode(): endOfWord(false) {}

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

class Trie {

private:
	TrieNode* root;

public:

	Trie(): root(new TrieNode()) {}

	void insert(const std::string& word) {
		TrieNode* node = root;

		for (auto ch : word) {
			if (!node->containsKey(ch)) {
				std::cout << ch << std::endl;
				node = node->insertChild(ch);
			}
			else {
				node = node->getChild(ch);
			}
		}
	}

	bool search(const std::string& word) {
		TrieNode* node = root;
		for (auto ch : word) {
			if (node->containsKey(ch)) {
				node = node->getChild(ch);
			}
			else {
				return false;
			}
		}
		return node->isEnd() ? true : false;
	}

	bool startsWith(const std::string& prefix) {
		TrieNode* node = root;
		for (auto ch : prefix) {
			if (node->containsKey(ch)) {
				node = node->getChild(ch);
			}
			else {
				return false;
			}
		}
		return true;
	}

};