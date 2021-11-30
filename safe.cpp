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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vvi safe(3, vi(3));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) cin >> safe[i][j];
	}

	queue<vvi> q;
	map<vvi, int> cnt;
	q.push(safe);
	cnt[safe] = 0;
	while (!q.empty()) {
		vvi state = q.front();
		q.pop();

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				vvi newstate = state;
				for (int r = 0; r < 3; r++) newstate[r][j]  = (newstate[r][j] + 1) % 4;
				for (int c = 0; c < 3; c++) newstate[i][c] = (newstate[i][c] + 1) % 4;
				newstate[i][j] = (newstate[i][j] - 1 + 4) % 4;

				if (cnt.count(newstate) == 0) {
					cnt[newstate] = cnt[state] + 1;
					q.push(newstate);
				}
			}
		}
	}

	vvi want(3, vi(3, 0));
	if (cnt.count(want) == 0) cout << -1;
	else cout << cnt[want];

	return 0;
}
