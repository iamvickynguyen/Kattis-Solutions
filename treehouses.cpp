#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef unordered_set<int> usi;
typedef unordered_map<int, vi> ivi;
typedef unordered_map<int, int> ii;
typedef priority_queue<int> pq;
#define all(x) (x).begin(), (x).end()
#define pb push_back

int n;
vector<pair<double, double>> points;
vector<tuple<double, int, int>> graph;
vi parent, set_rank;

double dist(pair<double, double> a, pair<double, double> b) {
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

void make_sets(int n) {
	parent.resize(n);
	set_rank.assign(n, 0);
	for (int i = 0; i < n; i++) parent[i]= i;
}

int find(int v) {
	if (parent[v] != v) parent[v] = find(parent[v]);
	return parent[v];
}

bool same_set(int a, int b) {
	return find(a) == find(b);
}

void union_sets(int a, int b) {
	int ra = find(a), rb = find(b);
	if (ra == rb) return;
	if (set_rank[ra] < set_rank[rb]) swap(ra, rb);
	parent[rb] = ra;
	if (set_rank[ra] == set_rank[rb]) set_rank[ra]++;
}

double minspantree() {
	sort(all(graph));
	double cost = 0.0;
	for (int i = 0; i < graph.size(); i++) {
		double d;
		int u, v;
		tie(d, u, v) = graph[i];
		if (!same_set(u, v)) {
			cost += d;
			union_sets(u, v);
		}
	}

	return cost;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int e, p;
	double x, y;
	cin >> n >> e >> p;
	
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		points.pb({x, y});
	}

	make_sets(n);

	for (int i = 0; i < e; i++) {
		for (int j = i + 1; j < e; j++) union_sets(i, j);
	}

	int a, b;
	for (int i = 0; i < p; i++) {
		cin >> a >> b;
		a--; b--;
		union_sets(a, b);
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (!same_set(i, j)) {
				double d = dist(points[i], points[j]);
				graph.pb({d, i, j});
			}
		}
	}

	double ans = minspantree();
	cout << ans;
	return 0;
}