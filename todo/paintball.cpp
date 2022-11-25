#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;
using ll = long long int;
using edge = tuple<int, ll, ll>;
using vi = vector<int>;
using ii = pair<int, int>;
const ll INF = 1e18;

// Reference: https://github.com/stevenhalim/cpbook-code/blob/master/ch8/maxflow.cpp
class max_flow {
    private:
    int V;
    vector<edge> EL;
    vector<vi> AL;
    vi d, last;
    vector<ii> p;
    unordered_map<ll, int> AL_EL_map;

    bool BFS(int s, int t) {                       // find augmenting path
        d.assign(V, -1); d[s] = 0;
        queue<int> q({s});
        p.assign(V, {-1, -1});                       // record BFS sp tree
        while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == t) break;                       // stop as sink t reached
        for (auto &idx : AL[u]) {                    // explore neighbors of u
            auto &[v, cap, flow] = EL[idx];          // stored in EL[idx]
            if ((cap-flow > 0) && (d[v] == -1))      // positive residual edge
              d[v] = d[u]+1, q.push(v), p[v] = {u, idx}; // 3 lines in one!
            }
        }
        return d[t] != -1;                           // has an augmenting path
    }

    ll DFS(int u, int t, ll f = INF) {           // traverse from s->t
        if ((u == t) || (f == 0)) return f;
        for (int &i = last[u]; i < (int)AL[u].size(); ++i) { // from last edge
            auto &[v, cap, flow] = EL[AL[u][i]];
            if (d[v] != d[u]+1) continue;                // not part of layer graph
            if (ll pushed = DFS(v, t, min(f, cap-flow))) {
                flow += pushed;
                auto &rflow = get<2>(EL[AL[u][i]^1]);     // back edge
                rflow -= pushed;
                return pushed;
            }
        }
        return 0;
    }

    public:
    max_flow(int initialV) : V(initialV) {
        EL.clear();
        AL.assign(V, vi());
    }

    // if you are adding a bidirectional edge u<->v with weight w into your
    // flow graph, set directed = false (default value is directed = true)
    void add_edge(int u, int v, ll w, bool directed = true) {
        if (u == v) return;                          // safeguard: no self loop
        EL.emplace_back(v, w, 0);                    // u->v, cap w, flow 0
        AL[u].push_back(EL.size()-1);                // remember this index
        AL_EL_map[u*V + v] = EL.size() - 1;
        EL.emplace_back(u, directed ? 0 : w, 0);     // back edge
        AL[v].push_back(EL.size()-1);                // remember this index
        AL_EL_map[v*V + u] = EL.size() - 1;
    }

    ll dinic(int s, int t) {
        ll mf = 0;                                   // mf stands for max_flow
        while (BFS(s, t)) {                          // an O(V^2*E) algorithm
            last.assign(V, 0);                       // important speedup
            while (ll f = DFS(s, t))                     // exhaust blocking flow
                mf += f;
        }
        return mf;
    }
    
    ll get_flow_edge(int u, int v) {
        return get<2>(EL[AL_EL_map[u*V + v]]);
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, a, b;
	cin >> n >> m;

	max_flow mf(n * 2 + 2);
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

	ll maxflow = mf.dinic(0, n * 2 + 1);

	if (maxflow == n) {
		for (int i = 1; i <= n; ++i) {
			for (int j = n + 1; j <= (n * 2); ++j) {
				if (i != (j - n) && mf.get_flow_edge(i, j) == 0) {
					cout << (j - n) << '\n';
					break;
				}
			}
		}
	} else {
		cout << "Impossible";
	}
	return 0;
}
