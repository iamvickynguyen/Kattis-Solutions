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

const int maxn = 12;
int cnt = 0, n;
vector<string> colors;
vector<int> favorite;
bool first = true;
int hideous[maxn][maxn];

void permute(vector<int> &s, vector<int> &ans) {
	if (s.size() == 0) {
		cnt++;
		if (first) {
			favorite = ans;
			first = false;
		}

		return;
	}

	for (int i = 0; i < s.size(); i++) {
		vector<int> rest;
		for (int j = 0; j < s.size(); j++) {
			if (j != i) rest.pb(s[j]);
		}

		if (ans.size() == 0 || hideous[ans[ans.size() - 1]][s[i]] == 0) {
			ans.pb(s[i]);
			permute(rest, ans);
			ans.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, m;
	string color;
	cin >> t;
	while (t--) {
		// reset
		colors.clear();
		favorite.clear();
		cnt = 0;
		first = true;
		for (int i = 0; i < maxn; i++) {
			for (int j = 0; j < maxn; j++) hideous[i][j] = 0;
		}

		// set up
		map<string, int> word_int; // for hideous matrix set up
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> color;
			colors.pb(color);
			word_int[color]  = i;
		}

		cin >> m;
		string a, b;
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			int u = word_int[a], v = word_int[b];
			hideous[u][v] = 1;
			hideous[v][u] = 1;
		}

		// permute
		vector<int> s(n);
		iota(all(s), 0);
		vector<int> ans;
		permute(s, ans);

		// output
		cout << cnt << '\n';
		for (auto &d: favorite) cout << colors[d] << " ";
		cout << '\n';
	}

	return 0;
}
