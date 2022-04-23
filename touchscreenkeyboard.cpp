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

vector<string> keyboard = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};

int bfs(char s, char t) {
	queue<tuple<int, int, int>> q;
	vector<string> seen = keyboard;
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < keyboard[i].size(); j++) {
			if (keyboard[i][j] == s) {
				q.push({i, j, 0});
				seen[i][j] = '_';
				while (!q.empty()) {
					auto &[y, x, step] = q.front(); q.pop();
					if (keyboard[y][x] == t) return step;
					vector<pii> neighbors = {{y-1, x}, {y+1, x}, {y, x-1}, {y, x+1}};
					for (auto &[row, col]: neighbors) {
						if (row >= 0 && row < 3 && col >= 0 && col < keyboard[row].size() && seen[row][col] != '_') {
							q.push({row, col, step+1});
							seen[row][col] = '_';
						}
					}
				}
			}
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, l;
	cin >> t;
	string u, v;
	while (t--) {
		cin >> u >> l;
		vector<pair<int, string>> ans;
		while (l--) {
			cin >> v;
			int cnt = 0;
			for (int i = 0; i < u.length(); i++) {
				cnt += bfs(u[i], v[i]);
			}
			ans.pb({cnt, v});
		}
		sort(all(ans));
		for (auto &item: ans) cout << item.second << " " << item.first << '\n';
	}

	#ifdef TIME
	cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
	#endif

	return 0;
}
