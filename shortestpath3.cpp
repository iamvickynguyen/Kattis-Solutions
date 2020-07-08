#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
const long long INF = 10000000;

vector<int> bellman_ford(vector<tuple<int, int, int>> &edges, int s, int n) {
	vector<int> dist(n, INF);
	dist[s] = 0;
	for (int i = 0; i < (n - 1) * 2; i++) {
		for (auto e : edges) {
			int u, v, w;
			tie(u, v, w) = e;
			if (dist[u] != INF && dist[v] > dist[u] + w) {
				dist[v] = i >= n - 1 ? -INF : dist[u] + w;
			}
		}
	}
	return dist;
}

int main() {
	int n, m, q, s, u, v, w;
	cin >> n >> m >> q >> s;
	while (n != 0 || m != 0 || q != 0 || s != 0) {
		vector<tuple<int, int, int>> edges;
		for (int i = 0; i < m; i++) {
			cin >> u >> v >> w;
			edges.push_back(make_tuple(u, v, w));
		}

		vector<int> dist = bellman_ford(edges, s, n);
		int x;
		for (int i = 0; i < q; i++) {
			cin >> x;
			if (dist[x] == INF)
				cout << "Impossible\n";
			else if (dist[x] == -INF)
				cout << "-Infinity\n";
			else
				cout << dist[x] << '\n';
		}
		cin >> n >> m >> q >> s;
	}
}