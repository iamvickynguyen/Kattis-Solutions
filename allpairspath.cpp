#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll INF = 1e18 + 10;

int main() {
	ll n, m, q;
	cin >> n >> m >> q;

	while (!(n == 0 && m == 0 && q == 0)) {

		// initialize graph
		vector<vector<ll>> graph;
		graph.resize(n, vector<ll>(n, INF));
		for (ll i = 0; i < n; i++) {
			graph[i][i] = 0; // distance to itself is 0
		}

		// add edges
		for (ll i = 0; i < m; i++) {
			ll u, v, w;
			cin >> u >> v >> w;
			graph[u][v] = min(graph[u][v], w);
		}

		// Floyd Warshall
		for (ll k = 0; k < n; k++) {
			for (ll i = 0; i < n; i++) {
				for (ll j = 0; j < n; j++) {
					if (graph[i][k] < INF && graph[k][j] < INF) {
						graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
					}
				}
			}
		}

		// Check negative cycles
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < n; j++) {
				for (ll k = 0; k < n; k++) {
					if (graph[k][k] < 0 && graph[i][k] != INF && graph[k][j] != INF) {
						graph[i][j] = -INF;
					}
				}
			}
		}

		// output
		ll a, b;
		for (ll i = 0; i < q; i++) {
			cin >> a >> b;
			if (graph[a][b] == INF) {
				cout << "Impossible" << '\n';
			}
			else if (graph[a][b] == -INF) {
				cout << "-Infinity" << '\n';
			}
			else {
				cout << graph[a][b] << '\n';
			}
		}
		cout << endl;	
		cin >> n >> m >> q;
	}

	return 0;
}