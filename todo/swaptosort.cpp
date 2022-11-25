#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<unordered_set<int>> graph;

bool connect(int i, const int target, vector<int> &seen) {
	if (i == target)
		return true;

	for (auto &d: graph[i]) {
		if (seen[d] == 0) {
			seen[i] = 1;
			bool is_connected = connect(d, target, seen);
			seen[i] = 0;
			if (is_connected) return true;
		}
	}

	return false;
}

int main() {
	int n, k, a, b;
	cin >> n >> k;

	graph.resize(n);
	for (int i = 0; i < k; ++i) {
		cin >> a >> b;
		--a, --b;
		graph[a].insert(b);
		graph[b].insert(a);
	}

	vector<int> seen(n, 0);
	bool ok = true;
	for (int i= 0; i < n/2; ++i) {
		if (!connect(i, n - i - 1, seen)) {
			ok = false;
			cout << "No";
			break;
		}
	}

	if (ok) cout << "Yes";
}
