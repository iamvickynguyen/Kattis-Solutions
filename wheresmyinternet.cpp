#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
//#define TIME

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, a, b;
	cin >> n >> m;
	vector<vi> adj(n);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	queue<int> q;
	q.push(0);
	vi seen(n, 0);
	seen[0] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto &d: adj[u]) {
			if (seen[d] == 0) {
				q.push(d);
				seen[d] = 1;
			}
		}
	}
	
	bool flag = true;
	for (int i = 0; i < n; i++) {
		if (seen[i] == 0) {
			flag = false;
			cout << (i + 1) << '\n';	
		}
	}

	if (flag) cout << "Connected";

	#ifdef TIME
		cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
	#endif

	return 0;
}
