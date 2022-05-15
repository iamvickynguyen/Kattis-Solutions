#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define pb push_back

// Reference: https://github.com/stevenhalim/cpbook-code/blob/master/ch8/maxflow.cpp
typedef long long ll;
typedef tuple<int, ll, ll> edge;
typedef vector<int> vi;
typedef pair<int, int> ii;

const ll INF = 1e18;

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

// Reference: https://github.com/shermz-lim/kattis-problems/blob/master/unfairplay.cpp
// I could not figure out how to set up the graph

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, a, b;
    while (cin >> n, n != -1) {
        cin >> m;
        vi points(n);
        for (auto &x: points) cin >> x;
        
        vector<ii> games;
        max_flow mf(n + m + 2);
        int my_points = points[n-1];
        int source = n + m, dest = n + m + 1;
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            a--; b--;
            games.pb({a, b});
            if (a == (n - 1) || b == (n - 1)) my_points += 2;
            else {
                int game_id = n + i;
                mf.add_edge(source, game_id, 2);
                mf.add_edge(game_id, a, 2);
                mf.add_edge(game_id, b, 2);
                cnt++;
            }
        }
        
        bool ok = true;
        for (int i = 0; i < (n - 1); i++) {
            if ((my_points - points[i] - 1) < 0) {
                ok = false;
                cout << "NO\n";
                break;
            }
            
            if (ok) mf.add_edge(i, dest, my_points - points[i] - 1);
        }

        if (ok) {
            ll maxflow = mf.dinic(source, dest);
            if (maxflow == (cnt * 2)) {
                for (int i = 0; i < m; i++) {
                    a = games[i].first;
                    b = games[i].second;
                    if (a == (n - 1)) cout << 0;
                    else if (b == (n - 1)) cout << 2;
                    else {
                        if (mf.get_flow_edge(n + i, a) == 2) cout << 0;
                        else if (mf.get_flow_edge(n + i, b) == 2) cout << 2;
                        else cout << 1;
                    }
                    cout << " ";
                }
                cout << '\n';
            } else cout << "NO\n";
        }
    }

    return 0;
}

