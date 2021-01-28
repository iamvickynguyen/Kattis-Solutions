#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 500001;
vector<vector<int>> adj(MAX);
vector<int> color(MAX, -1);

bool bfs(int v) {
	queue<int> q;
	q.push(v);
	color[v] = 0;
	bool odd_cycle = false;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto u : adj[cur]) {
			if (color[u] == -1) {
				color[u] = color[cur] == 0 ? 1 : 0;
				q.push(u);
			}
			else if (color[u] == color[cur]) {
				odd_cycle = true;
			}
		}
	}
	return odd_cycle;
}

int main() {
	int n, m, u, v;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int count = 0;
	bool odd_cycle = false;
	for (int i = 0; i < n; i++) {
		if (color[i] == -1) {
			count++;
			if (bfs(i))
				odd_cycle = true;
		}
	}

	if (odd_cycle)
		printf("%d", count - 1);
	else
		printf("%d", count);
	return 0;
}