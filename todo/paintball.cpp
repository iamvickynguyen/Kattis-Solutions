#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;
using ll = long long int;
using edge = tuple<int, int, int>;
using vi = vector<int>;
using ii = pair<int, int>;
using vvi = vector<vector<int>>;

constexpr int MAXN = 2002;
constexpr int INF = 20005;
int adj[MAXN][MAXN];
int flow_edges[MAXN][MAXN];
int capacity[MAXN][MAXN];


// check if there is a flow from s to t
int bfs(int s, int t, vector<int>& parent, int n) {
	vector<bool> visited(t - s, false);
	queue<int> q;
	q.push(s);
	parent[s] = -1; // none
	visited[s] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		
		cout << "pop: " << cur << '\n';

		for (int i = 0; i <= n * 2 + 1; ++i) {
			const int val = adj[cur][i];
			if (val == 1) {
				if (!visited[i] && capacity[cur][i] > 0) {
					parent[i] = cur;
					visited[i] = true;
					q.push(i);
					if (i == t) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

int maxflow(int s, int t, int n, int N) {
	vector<int> parent(n);
	int maxflow = 0;
	while (bfs(s, t, parent, N)) {
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

	int n, m, a, b;
	cin >> n >> m;
	
	// init
	for (int i = 1; i <= n * 2; ++i) {
		for (int j = 1; j <= n * 2; ++j) {
			adj[i][j] = 0;
			capacity[i][j] = 0;
			flow_edges[i][j] = 0;
		}
		
		adj[0][min(i, n)] = 1;
		adj[max(n + 1, i)][n * 2 + 1] = 1;
		capacity[0][min(i, n)] = 1;
		capacity[max(n + 1, i)][n * 2 + 1] = 1;
	}

	// build graph
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		adj[a][b + n] = 1;
		adj[b][a + n] = 1;
		capacity[a][b + n] = 1;
		capacity[b][a + n] = 1;
	}

	int mf = maxflow(0, n * 2 + 1, n * 2 + 2, n);
	cout << "MF: " << mf << '\n';

//	if (maxflow == n) {
//		for (int i = 1; i <= n; ++i) {
//			for (int j = n + 1; j <= (n * 2); ++j) {
//				if (i != (j - n) && mf.get_flow_edge(i, j) == 0) {
//					cout << (j - n) << '\n';
//					break;
//				}
//			}
//		}
//	} else {
//		cout << "Impossible";
//	}
	return 0;
}
