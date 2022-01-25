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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, l, n, x;
	cin >> t;
	while (t--) {
		cin >> l >> n;
		vi v(n);
		for (auto &x: v) cin >> x;

		int lo = min(v[0], l - v[0]);
		int hi = max(v[0], l - v[0]);
		for (int i = 1; i < n; i++) {
			lo = max(lo, min(v[i], l - v[i]));
			hi = max(hi, max(v[i], l - v[i]));
		}
		cout << lo << " " << hi << '\n';
	}

	return 0;
}
