#include <queue>
#include <concepts>



template <typename T>
class TreeWrapper {
	TreeWrapper() {}

	virtual void inorderTraversal(T* root) {
		if (!root)return;

		inorderTraversal(root->left);
		std::cout << root->data << " ";
		inorderTraversal(root->right);
	}

	virtual void preorderTraversal(T* root) {
		if (!root) return;

		std::cout << root->data << " ";
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}

	void levelOrderTraversal(T* root) {
		if (root == nullptr) return;

		std::queue<T*> queue;
		queue.push(root);
		while (!queue.empty()) {

			int len = queue.size();
			for (int i = 0; i < len; i++) {
				T* frontEl = queue.front();
				std::cout << frontEl->data << std::endl;
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