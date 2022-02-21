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

int dfs(int v, int n, vvi &graph, vi &depth) {
	if (depth[v] != 0) return depth[v];

	depth[v] = 1;
	for (int i = 0; i < 26; i++) {
		if (graph[v][i] == n) {
			if (depth[i] == 0) depth[i] = dfs(i, n, graph, depth);
			depth[v] = max(depth[v], depth[i] + 1);
		}
	}
	return depth[v];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	string s;
	vvi graph(26, vi(26, 0));
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < k; j++) {
			int a = s[j] - 'A';
			for (int p = j + 1; p < k; p++) {
				int b = s[p] - 'A';
				graph[a][b]++;
			}
		}
	}

	vi depth(26, 0);
	int ans = 1;
	for (int i = 0; i < 26; i++) {
		if (depth[i] == 0) ans = max(ans, dfs(i, n, graph, depth));
	}

	cout << ans;
	return 0;
}
