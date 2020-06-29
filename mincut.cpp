// https://cp-algorithms.com/graph/edmonds_karp.html#toc-tgt-2
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <set>
using namespace std;

const long long INF = 1 << 29;
vector<vector<int>> flow_edges;
vector<vector<int>> capacity;
vector<vector<int>> adj;

// check if there is a flow from s to t
int bfs(int s, int t, vector<int>& parent) {
	vector<bool> visited(capacity.size(), false);
	queue<int> q;
	q.push(s);
	parent[s] = -1; // none
	visited[s] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int n : adj[cur]) {
			if (!visited[n] && capacity[cur][n] > 0) {
				parent[n] = cur;
				visited[n] = true;
				q.push(n);
				if (n == t) {
					return true;
				}
			}
		}
	}
	return false;
}

int maxflow(int s, int t, int n) {
	vector<int> parent(n);
	int maxflow = 0;
	while (bfs(s, t, parent)) {
		int flow = INF;

		for (int cur = t; cur != s; cur = parent[cur]) {
			int p = parent[cur];
			flow = min(flow, capacity[p][cur]);
		}

		for (int cur = t; cur != s; cur = parent[cur]) {
			int p = parent[cur];
			flow_edges[p][cur] += flow;
			flow_edges[cur][p] -= flow;
			capacity[p][cur] -= flow;
			capacity[cur][p] += flow;
		}

		maxflow += flow;
	}
	return maxflow;
}

vector<int> findMinCut(int s, int t) {
	vector<int> U;
	vector<bool> visited(capacity.size(), false);
	queue<int> q;
	q.push(s);
	visited[s] = true;
	U.push_back(s);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int n : adj[cur]) {
			if (!visited[n] && capacity[cur][n] > 0) {
				visited[n] = true;
				q.push(n);
				U.push_back(n);
			}
		}
	}
	return U;
}

int main() {
	int n, m, s, t, u, v, c;
	cin >> n >> m >> s >> t;
	adj.resize(n);
	capacity.resize(n, vector<int>(n, 0)); // matrix
	flow_edges.resize(n, vector<int>(n, 0)); // matrix
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> c;
		adj[u].push_back(v);
		adj[v].push_back(u);
		capacity[u][v] = c;
	}

	int result = maxflow(s, t, n);
	vector<int> U = findMinCut(s, t);
	cout << U.size() << '\n';
	for (int v : U) {
		cout << v << '\n';
	}

	return 0;
}