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

const int maxn = 102;
vi dfs_num, dfs_low, parent;
ivi graph;
int timer, bridges;

bool dfs(int v) {
    dfs_num[v] = dfs_low[v] = timer++;
    for (auto &u : graph[v]) {
        if (dfs_num[u] == -1) {
            parent[u] = v;

            if (dfs(u)) return true;

            dfs_low[v] = min(dfs_low[v], dfs_low[u]);
            if (dfs_low[u] > dfs_num[v]) return true;
        } else if (u != parent[v]) {
            dfs_low[v] = min(dfs_low[v], dfs_num[u]);
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int p, c, u, v;
    cin >> p >> c;
    while (p || c) {
        graph.clear();
        for (int i = 0; i < c; i++) {
            cin >> u >> v;
            graph[u].pb(v);
            graph[v].pb(u);
        }

        timer = 0;
        dfs_num.assign(p, -1);
        dfs_low.assign(p, -1);
        parent.assign(p, -1);
        bool ok = true, check = false;

        if (dfs(0)) {
            ok = false;
            cout << "Yes\n";
        }

        if (ok) {
            for (int i = 0; i < p; i++) {
                if (dfs_num[i] == -1) {
                    ok = false;
                    cout << "Yes\n";
                    break;
                }
            }
        }

        if (ok) cout << "No\n";

        cin >> p >> c;
    }

    #ifdef TIME
    cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
    #endif

    return 0;
}