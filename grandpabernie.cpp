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
// #define TIME

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, y, m;
	cin >> n;
	string s;
	unordered_map<string, vi> countries;
	for (int i = 0; i < n; i++) {
		cin >> s >> y;
		countries[s].pb(y);
	}

	for (auto &[name, years]: countries) sort(all(years));
	cin >> m;
	while (m--) {
		cin >> s >> y;
		cout << countries[s][y-1] << '\n';
	}

	#ifdef TIME
	cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
	#endif

	return 0;
}
