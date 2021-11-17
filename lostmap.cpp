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

vi taken;
priority_queue<tuple<int, int, int>> pq;
vector<vector<pii>> graph;

void process(int v) {
	taken[v] = 1;
	for (pii item : graph[v]) {
		if (!taken[item.first]) pq.push({-item.second, -item.first, -v});
	}
}

vector<pii> prim(vector<vector<pii>> &graph) {
	vector<pii> ans;
	taken.assign(graph.size(), 0);
	process(0);
	int cnt = 0;
	while (!pq.empty()) {
		int w, v, u;
		tie(w, u, v) = pq.top();
		pq.pop();
		v = -v; w = -w; u = -u;
		if (!taken[u]) {
			ans.pb({v, u});
			process(u);
			cnt++;

			if (cnt == graph.size() - 1) break;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, w;
	cin >> n;
	graph.resize(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> w;
			graph[i].pb({j, w});
		}
	}

	vector<pii> ans = prim(graph);
	for (auto &item: ans) cout << item.first + 1 << " " << item.second + 1 << '\n';
	return 0;
}
