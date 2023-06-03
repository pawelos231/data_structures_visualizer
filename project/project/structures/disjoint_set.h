#include <vector>

class DisjointSet {

private:
	std::vector<int> parent;
	std::vector<int> rank;

	DisjointSet(int size){
		parent.resize(size);
		rank.resize(size, 0);

		for (int i = 0; i < size; i++) {
			parent[i] = i;
		}
	}

	int find(int x) {
		if (parent[x] != x) {
			// Path compression: Make the parent of x point to the root directly
			parent[x] = find(parent[x]);
		}
		return parent[x];
	}

	void unite(int a, int b) {
		int rootA = find(a);
		int rootB = find(b);


		if (rootA == rootB) {
			return;  
		}

		if (rank[rootA] > rank[rootB]) {
			parent[rootB] = rootA;
		}
		else if (rank[rootB] > rank[rootA]) {
			parent[rootA] = rootB;
		}
		else {
			parent[rootB] = rootA;
			rank[rootA]++;
		}

	}
};