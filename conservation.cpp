#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef priority_queue<int, vector<int>, greater<int>> minpq;
typedef unordered_set<int> usi;
typedef unordered_map<int, vi> ivi;
typedef unordered_map<int, int> ii;
#define all(x) (x).begin(), (x).end()
#define pb push_back

int solve(vvi &graph, vi degree, vi &lab, int n, int cur) {
	vector<queue<int>> q(2);
	for (int i = 0; i < n; i++) {
		if (degree[i] == 0) q[lab[i]].push(i);
	}

	int cnt = 0;
	while (!q[0].empty() || !q[1].empty()) {
		while (!q[cur].empty()) {
			int u = q[cur].front();
			q[cur].pop();

			for (auto &v: graph[u]) {
				degree[v]--;
				if (degree[v] == 0) q[lab[v]].push(v);
			}
		}

		cnt++;
		cur ^= 1;
	}

	return cnt - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, m, n, a, b;
    cin >> t;
    while (t--) {
		cin >> n >> m;
	    vi lab(n);
	    for (auto &x: lab) {
			cin >> x;
			x--;
		}
		vvi graph(n);
		vi degree(n, 0);

		while (m--) {
			cin >> a >> b;
			a--; b--;
			degree[b]++;
			graph[a].pb(b);
	    }

	    cout << min(solve(graph, degree, lab, n, 0), solve(graph, degree, lab, n, 1)) << '\n';
    }
    return 0;
}
