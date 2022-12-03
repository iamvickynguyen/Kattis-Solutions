#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;
using ll = long long int;

// Reference: https://cp-algorithms.com/graph/dinic.html#unit-capacities-networks
struct FlowEdge {
	int v, u;
	ll cap, flow = 0;
	FlowEdge(const int v, const int u, const ll cap): v(v), u(u), cap(cap) {}
};

class MaxFlow {
	public:
		MaxFlow(const int n, const int s, const int t): n(n), s(s), t(t) {
			adj.resize(n);
			ptr.resize(n);
			level.resize(n);
		}

		void add_edge(const int v, const int u, const ll cap) {
			edges.emplace_back(v, u, cap);
			edges.emplace_back(u, v, 0LL);
			adj[v].push_back(m);
			adj[u].push_back(m + 1);
			m += 2;
		}

		ll Dinic() {
			ll f = 0;
			while (true) {
				fill(level.begin(), level.end(), -1);
				level[s] = 0;
				q.push(s);
				if (!BFS()) break;
				fill(ptr.begin(), ptr.end(), 0);
				while (ll pushed = DFS(s, INF)) {
					f += pushed;
				}
			}
			return f;
		}

		// output
		void print_targets() {
			int players = (n-2)/2;
			for (int i = 1; i <= players; ++i) {
				for (int id: adj[i]) {
					if (edges[id].flow == 1) {
						cout << (edges[id].u - players) << '\n';
						break;
					}
				}
			}
		}
	
	private:
		int n, m = 0;
		int s, t;
		const ll INF = 1e18;
		vector<int> level, ptr;
		vector<vector<int>> adj;
		vector<FlowEdge> edges;
		queue<int> q;
		
		bool BFS() {
			while (!q.empty()) {
				const int v = q.front();
				q.pop();
				for (int id: adj[v]) {
					if (edges[id].cap - edges[id].flow < 1)
						continue;
					if (level[edges[id].u] != -1)
						continue;
					level[edges[id].u] = level[v] + 1;
					q.push(edges[id].u);
				}
			}
			return level[t] != -1;
		}

		ll DFS(const int v, const ll pushed) {
			if (pushed == 0) return 0;
			if (v == t) return pushed;

			for (int &cid = ptr[v]; cid < (int)adj[v].size(); ++cid) {
				int id = adj[v][cid];
				int u = edges[id].u;
				if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
					continue;
				ll tr = DFS(u, min(pushed, edges[id].cap - edges[id].flow));
				if (tr == 0) continue;
				edges[id].flow += tr;
				edges[id ^ 1].flow -= tr;
				return tr;
			}

			return 0;
		}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, a, b;
	cin >> n >> m;

	MaxFlow mf(n * 2 + 2, 0, n * 2 + 1);
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		mf.add_edge(a, b + n, 1);
		mf.add_edge(b, a + n, 1);
	}

	// add edges from source and to sink
	for (int i = 1; i <= n; ++i) {
		mf.add_edge(0, i, 1);
		mf.add_edge(i + n, n * 2 + 1, 1);
	}

	ll maxflow = mf.Dinic();
	if (maxflow == n) {
		mf.print_targets();
	}	else {
		cout << "Impossible";
	}

	return 0;
}
