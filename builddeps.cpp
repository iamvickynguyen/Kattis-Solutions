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

unordered_set<string> all_dependencies, dependencies, seen;
unordered_map<string, vector<string>> graph;
stack<string> st;

void bfs(string filename) {
    queue<string> q;
    q.push(filename);
    dependencies.insert(filename);

    while (!q.empty()) {
            string cur = q.front();
            q.pop();

            for (auto &d: graph[cur]) {
                    if (dependencies.count(d) == 0) {
                            dependencies.insert(d);
                            q.push(d);
                    }
            }
    }
}

void dfs(string v) {
    seen.insert(v);
    for (auto &d: graph[v]) {
        if (seen.count(d) == 0) dfs(d);
    }
    st.push(v);
}

void topological_sort() {
    for (auto &d: all_dependencies) {
        if (seen.count(d) == 0) {
            dfs(d);
        }
    }

    while (!st.empty()) {
        string cur = st.top();
        if (dependencies.count(cur) > 0) cout << cur << '\n';
        st.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cin.ignore();
    string line, v, u, filename;
    vector<string> mt;
    for (int i = 0; i < n; i++) {
            getline(cin, line);
            stringstream ss(line);
            ss >> v;
            v = v.substr(0, v.length() - 1);
            all_dependencies.insert(v);
            while (ss >> u) {
                graph[u].pb(v);
                all_dependencies.insert(u);
            }
    }

    getline(cin, filename);

    // find all dependencies to output
    bfs(filename);

    // output
    topological_sort();

    return 0;
}
