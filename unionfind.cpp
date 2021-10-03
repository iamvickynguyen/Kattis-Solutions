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

const int MAXSIZE = 1e6;
int parent[MAXSIZE], set_size[MAXSIZE];

int find(int v) {
	if (parent[v] != v) parent[v] = find(parent[v]);
	return parent[v];
}

void union_set(int a, int b) {
	int ra = find(a), rb = find(b);
	if (ra == rb) return;
	if (set_size[ra] < set_size[rb]) swap(ra, rb);
	parent[rb] = ra;
	if (set_size[ra] == set_size[rb]) set_size[ra]++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q, a, b;
	char c;
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		parent[i] = i;
		set_size[i] = 1;
	}

	while (q--) {
		cin >> c >> a >> b;
		if (c == '=') union_set(a, b);
		else cout << ((find(a) == find(b)) ? "yes\n" : "no\n");
	}

	return 0;
}
