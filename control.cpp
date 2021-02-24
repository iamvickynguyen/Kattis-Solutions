#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
const int MAX = 500001;
int Parent[MAX];
int Size[MAX];

void make_set() {
	for (int i = 0; i < MAX; i++) {
		Parent[i] = i;
		Size[i] = 1;
	}
}

int find(int e) {
	while (Parent[e] != e) {
		Parent[e] = Parent[Parent[e]];
		e = Parent[e];
	}
	return e;
}

void union_set(int e1, int e2) {
	int root1 = find(e1);
	int root2 = find(e2);
	if (root1 != root2) {
		if (Size[root1] < Size[root2])
			swap(root1, root2);
		Parent[root2] = root1;
		Size[root1] += Size[root2];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	make_set();

	int n, m, count = 0;
	cin >> n;
	while (n--) {
		cin >> m;
		unordered_set<int> s;
		vector<int> ingredients(m);
		for (auto &i: ingredients){
			cin >> i;
			i = find(i);
			s.insert(i);
		}

		int total = 0;
		for (auto e : s) {
			total += Size[find(e)];
		}

		if (total == m) {
			count++;
			for (int i = 1; i < ingredients.size(); i++) {
				union_set(ingredients[0], ingredients[i]);
			}
		}
	}
	cout << count;
	return 0;
}