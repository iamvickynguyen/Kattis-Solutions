#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

const int MAXSIZE = 500001;
int parent[MAXSIZE], set_size[MAXSIZE];

void make_sets() {
	for (int i = 0; i < MAXSIZE; i++) {
		parent[i] = i;
		set_size[i] = 1;
	}
}

int find(int v) {
	if (parent[v] != v) parent[v] = find(parent[v]);
	return parent[v];
}

void union_sets(int a, int b) {
	int ra = find(a), rb = find(b);
	if (ra == rb) return;
	if (set_size[ra] < set_size[rb]) swap(ra, rb);
	parent[rb] = ra;
	set_size[ra] += set_size[rb];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	make_sets();
	int n, m, count = 0, x;
	cin >> n;
	while (n--) {
		cin >> m;
		unordered_set<int> roots;
		vector<int> ingredients;
		for (int i = 0; i < m; i++) {
			cin >> x;
			ingredients.push_back(x);
			roots.insert(find(x));
		}

		int total = 0;
		for (auto &r: roots) total += set_size[find(r)];

		if (total == m) {
			count++;
			for (int i = 1; i < ingredients.size(); i++) union_sets(ingredients[0], ingredients[i]);
		}
	}
	cout << count;
	return 0;
}