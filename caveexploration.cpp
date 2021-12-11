#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef priority_queue<int, vector<int>, greater<int>> minpq;
typedef unordered_set<int> usi;
typedef unordered_map<int, vi> ivi;
typedef unordered_map<int, int> ii;
#define all(x) (x).begin(), (x).end()
#define pb push_back
// #define TIME

vi dfs_num, dfs_low, parent;
map<int, usi> graph;
int timer = 0;
vector<pii> bridges;

void find_bridges(int v) {
    dfs_num[v] = dfs_low[v] = timer++;
    for (auto &u : graph[v]) {
        if (dfs_num[u] == -1) {
            parent[u] = v;
            find_bridges(u);
            dfs_low[v] = min(dfs_low[v], dfs_low[u]);
            if (dfs_low[u] > dfs_num[v]) {
                bridges.pb({u, v});
            }
        } else if (u != parent[v]) {
            dfs_low[v] = min(dfs_low[v], dfs_num[u]);
        }
    }
}

int bfs(int v, int n) {
    queue<int> q;
    vi seen(n, 0);
    q.push(v);
    seen[v] = 1;
    int cnt = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cnt++;
        for (auto &u : graph[cur]) {
            if (!seen[u]) {
                seen[u] = 1;
                q.push(u);
            }
        }
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, u, v;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].insert(v);
        graph[v].insert(u);
    }

    dfs_num.assign(n, -1);
    dfs_low.assign(n, -1);
    parent.assign(n, -1);
    find_bridges(0);

    // remove bridges
    for (auto &b : bridges) {
        graph[b.first].erase(b.second);
        graph[b.second].erase(b.first);
    }

    cout << bfs(0, n);


    #ifdef TIME
    cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
    #endif

    return 0;
}
