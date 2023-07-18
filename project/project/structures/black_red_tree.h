#pragma once

//its main competitor is AVL tree,
// black red tree has 2*log(n) height, hence the balance factor is more relaxed than in AVL trees


template <typename T>
class RedBlackTree {

	enum Color { RED, BLACK };

	struct Node {
		T data;
		Node* parent;
		Node* left;
		Node* right;
		Color color;

		Node(T value, Node* parent = nullptr, Color nodeColor = RED)
			: data(value), parent(parent), left(nullptr), right(nullptr), color(nodeColor) {}
	};

	Node* root;

public:
	RedBlackTree() : root(nullptr) {}

	void insert(T value) {
		root = insertNode(root, value);
		root->color = BLACK; // Root must always be black.
	}

	void remove(T value) {
		root = deleteNode(root, value);
		if (root) {
			root->color = BLACK;
		}
	}

	bool search(T value) const {
		return searchNode(root, value) != nullptr;
	}

	void inorderTraversal() const {
		inorderTraversalHelper(root);
	}

	void preorderTraversal() const {
		preorderTraversalHelper(root);
	}

	void levelOrderTraversal() const {
		levelOrderTraversalHelper(root);
	}

private:
	Node* insertNode(Node* node, T value) {
		if (node == nullptr) {
			return new Node(value);
		}

		if (value < node->data) {
			node->left = insertNode(node->left, value);
			node->left->parent = node;
		}
		else if (value > node->data) {
			node->right = insertNode(node->right, value);
			node->right->parent = node;
		}

		// Check and fix violations
		if (node->left && node->left->color == RED && node->left->left && node->left->left->color == RED) {
			return handleRedRedViolation(node, true);
		}
		if (node->left && node->left->color == RED && node->left->right && node->left->right->color == RED) {
			return handleRedRedViolation(node, false);
		}
		if (node->right && node->right->color == RED && node->right->right && node->right->right->color == RED) {
			return handleRedRedViolation(node, false);
		}
		if (node->right && node->right->color == RED && node->right->left && node->right->left->color == RED) {
			return handleRedRedViolation(node, true);
		}

		return node;
	}

	Node* handleRedRedViolation(Node* node, bool leftChildIsRed) {
		Node* grandparent = node->parent;
		Node* parent = (leftChildIsRed) ? node->left : node->right;
		Node* uncle = (leftChildIsRed) ? node->right : node->left;

		if (uncle && uncle->color == RED) {
			// Recoloring
			grandparent->color = RED;
			parent->color = BLACK;
			uncle->color = BLACK;

			// Recurse to fix violations higher up
			return insertNode(grandparent, parent->data);
		}
		else {
			if (leftChildIsRed) {
				if (node == grandparent->left) {
					// Left-Left case
					grandparent = rightRotate(grandparent);
				}
				else {
					// Left-Right case
					parent = leftRotate(parent);
					grandparent->left = parent;
				}
			}
			else {
				if (node == grandparent->right) {
					// Right-Right case
					grandparent = leftRotate(grandparent);
				}
				else {
					// Right-Left case
					parent = rightRotate(parent);
					grandparent->right = parent;
				}
			}

			// Recoloring
			parent->color = BLACK;
			grandparent->color = RED;

			return grandparent;
		}
	}

	Node* leftRotate(Node* node) {
		Node* newRoot = node->right;
		node->right = newRoot->left;

		if (newRoot->left) {
			newRoot->left->parent = node;
		}

		newRoot->parent = node->parent;
		if (!node->parent) {
			root = newRoot;
		}
		else if (node == node->parent->left) {
			node->parent->left = newRoot;
		}
		else {
			node->parent->right = newRoot;
		}

		newRoot->left = node;
		node->parent = newRoot;

		return newRoot;
	}

	Node* rightRotate(Node* node) {
		Node* newRoot = node->left;
		node->left = newRoot->right;

		if (newRoot->right) {
			newRoot->right->parent = node;
		}

		newRoot->parent = node->parent;
		if (!node->parent) {
			root = newRoot;
		}
		else if (node == node->parent->right) {
			node->parent->right = newRoot;
		}
		else {
			node->parent->left = newRoot;
		}

		newRoot->right = node;
		node->parent = newRoot;

		return newRoot;
	}

	Node* deleteNode(Node* node, T value) {
		if (!node) {
			return nullptr;
		}

		if (value < node->data) {
			node->left = deleteNode(node->left, value);
		}
		else if (value > node->data) {
			node->right = deleteNode(node->right, value);
		}
		else {
			if (!node->left && !node->right) {
				delete node;
				return nullptr;
			}
			else if (!node->left) {
				Node* temp = node->right;
				delete node;
				temp->parent = node->parent;
				temp->color = BLACK; // Replaced node is red or has a red child
				return temp;
			}
			else if (!node->right) {
				Node* temp = node->left;
				delete node;
				temp->parent = node->parent;
				temp->color = BLACK; // Replaced node is red or has a red child
				return temp;
			}
			else {
				Node* temp = findMinValue(node->right);
				node->data = temp->data;
				node->right = deleteNode(node->right, temp->data);
			}
		}

		// Fix the tree after deletion
		if (node->left && node->left->color == RED) {
			return handleRedRedViolationAfterDeletion(node, true);
		}
		if (node->right && node->right->color == RED) {
			return handleRedRedViolationAfterDeletion(node, false);
		}

		return node;
	}

	Node* handleRedRedViolationAfterDeletion(Node* node, bool leftChildIsRed) {
		Node* sibling = (leftChildIsRed) ? node->right : node->left;

		if (sibling && sibling->color == RED) {
			node->color = RED;
			sibling->color = BLACK;
			if (leftChildIsRed) {
				leftRotate(node);
			}
			else {
				rightRotate(node);
			}
			return deleteNode(node, node->data);
		}

		Node* parent = node->parent;
		if (!parent) {
			return node; // The tree is fixed
		}

		Node* parentSibling = (parent->left == node) ? parent->right : parent->left;

		if (parentSibling && parentSibling->color == RED) {
			parent->color = RED;
			parentSibling->color = BLACK;
			if (parent->left == node) {
				rightRotate(parent);
			}
			else {
				leftRotate(parent);
			}
		}

		return deleteNode(node, node->data);
	}

	Node* findMinValue(Node* root) const {
		if (!root) {
			return nullptr;
		}

		Node* current = root;
		while (current->left) {
			current = current->left;
		}

		return current;
	}

	Node* searchNode(Node* node, T value) const {
		if (node == nullptr || node->data == value) {
			return node;
		}

		if (value < node->data) {
			return searchNode(node->left, value);
		}

		return searchNode(node->right, value);
	}

	void inorderTraversalHelper(Node* root) const {
		if (!root) {
			return;
		}

		inorderTraversalHelper(root->left);
		std::cout << root->data << " ";
		inorderTraversalHelper(root->right);
	}

	void preorderTraversalHelper(Node* root) const {
		if (!root) {
			return;
		}

		std::cout << root->data << " ";
		preorderTraversalHelper(root->left);
		preorderTraversalHelper(root->right);
	}

	void levelOrderTraversalHelper(Node* root) const {
		if (!root) {
			return;
		}

		std::queue<Node*> queue;
		queue.push(root);
		while (!queue.empty()) {
			int len = queue.size();
			for (int i = 0; i < len; i++) {
				Node* frontEl = queue.front();
				std::cout << frontEl->data << " ";
				queue.pop();
				if (frontEl->left) {
					queue.push(frontEl->left);
				}
				if (frontEl->right) {
					queue.push(frontEl->right);
				}
			}
		}
	}
};
