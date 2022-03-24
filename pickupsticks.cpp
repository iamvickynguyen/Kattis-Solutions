#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef unordered_set<int> usi;
typedef unordered_map<int, vi> ivi;
typedef unordered_map<int, int> ii;
#define all(x) (x).begin(), (x).end()
#define pb push_back

vvi graph;
vi seen;
vi ans;

bool topological_sort(int v) {
	seen[v] = 2;
	for (auto &u: graph[v]) {
		if (seen[u] == 2) return false;
		if (seen[u] == 0) {
			if (!topological_sort(u)) return false;
		}
	}

	ans.pb(v);
	seen[v] = 1;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, a, b;
	cin >> n >> m;
	graph.resize(n);
	seen.assign(n, 0);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		a--; b--;
		graph[a].pb(b);
	}

	for (int i = 0; i < n; i++) {
		if (seen[i] == 0) {
			if (!topological_sort(i))
				break;
		}
	}

	if (ans.size() < n) cout << "IMPOSSIBLE";
	else {
		for (int i = n - 1; i >= 0; i--) cout << ans[i] + 1 << "\n";
	}

	return 0;
}
