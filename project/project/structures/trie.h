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
	bool isEndOfWord;

public:
	TrieNode(): isEndOfWord(false) {}

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
		return children;
	}

	bool isEnd() const {
		return isEndOfWord;
	}

	void setEnd(bool value) {
		isEndOfWord = value;
	}

	bool hasChildren() const {
		return !children.empty();
	}

	void deleteChild(char ch) {
		children.erase(ch);
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
				node = node->insertChild(ch);
			}
			else {
				node = node->getChild(ch);
			}
		}
		node->setEnd(true);
	}

	bool search(const std::string& word) {
		TrieNode* node = root;
		for (auto ch : word) {
			if (node->containsKey(ch)) {
				node = node->getChild(ch);
			}
			else return false;
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

	void remove(const std::string& word) {
		removeHelper(root, word, 0);
	}

private:
	bool removeHelper(TrieNode* node, const std::string& word, int depth) {
		if (!node) {
			return false;
		}

		if (depth == word.size()) {
			if (!node->isEnd()) {
				return false;
			}

			node->setEnd(false);
			return !node->hasChildren();
		}

		char ch = word[depth];
		TrieNode* child = node->getChild(ch);
		if (!child) {
			return false;
		}
		bool shouldDeleteChild = removeHelper(child, word, depth + 1);
		if (shouldDeleteChild) {
			node->deleteChild(ch);
			delete child;
			return !node->isEnd() && !node->hasChildren();
		}

		return false;
	}
};