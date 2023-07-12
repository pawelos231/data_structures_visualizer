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
	int wordCount;

public:
	TrieNode(): wordCount(0) {}

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
		return this->wordCount >= 1;
	}

	void setWordCount(int val) {
		this->wordCount = val;
	}

	int getWordCount() {
		return this->wordCount;
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
		node->setWordCount(node->getWordCount() + 1);
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
private:
	bool deleteWord(const std::string& word) {
		if (!search(word)) {
			return false;
		}

		TrieNode* current = root;

		for (char ch : word) {
			current = current->getChild(ch);
		}

		current->setWordCount(current->getWordCount() - 1);

		if (current->getWordCount() == 0 && !current->hasChildren()) {
			//deleteNode(current); i need to come up with something recursive, beacuse of that for now i mark it as a private
		}

		return true;
	}

};