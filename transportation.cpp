#include <bits/stdc++.h>
using namespace std;
const long long INF = 3000;
typedef unordered_set<int> us;
vector<vector<int>> flow_edges;
vector<vector<int>> capacity;
vector<vector<int>> adj;
us suppliers;
us factories;
unordered_map<string, int> state_int;

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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string name;
	int s, r, f, t;
	cin >> s >> r >> f >> t;

	int SIZE = 3000;
	adj.resize(SIZE);
	capacity.resize(SIZE, vector<int>(SIZE, 0)); // matrix
	flow_edges.resize(SIZE, vector<int>(SIZE, 0)); // matrix
	
	int index = 1;
	for (int i = 0; i < r; i++) {
		cin >> name;
		state_int[name] = index;
		suppliers.insert(index);
		index++;
	}

	for (int i = 0; i < f; i++) {
		cin >> name;
		state_int[name] = index;
		factories.insert(index);
		index++;
	}

	vector<vector<int>> firms;
	int x;
	for (int i = 0; i < t; i++) {
		cin >> x;
		vector<int> row;
		while (x--) {
			cin >> name;
			if (state_int.count(name) == 0) {
				state_int[name] = index;
				index++;
			}
			row.push_back(state_int[name]);
		}
		firms.push_back(row);
	}

	// build graph
	// add source
    for (auto k : suppliers) {
        adj[0].push_back(k);
        adj[k].push_back(0);
        capacity[0][k] = 1;
    }

    // add sink
    int sink = SIZE - 1;
    for (auto k : factories) {
        adj[sink].push_back(k);
        adj[k].push_back(sink);
        capacity[k][sink] = 1;
    }

	// in, out nodes
	for (auto f : firms) {
		for (auto v : f) {
			// all companies to in
			adj[index].push_back(v);
			adj[v].push_back(index);
			capacity[v][index] = 1;

			// in-out
			adj[index].push_back(index + 1);
			adj[index + 1].push_back(index);
			capacity[index][index+1] = 1;

			// out to factories
			if (suppliers.count(v) == 0) {
				adj[index+1].push_back(v);
				adj[v].push_back(index + 1);
				capacity[index + 1][v] = 1;
			}
		}
		index += 2;
	}

	int result = maxflow(0, sink, SIZE);
	cout << result;
	return 0;
}
