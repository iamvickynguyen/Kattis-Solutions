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

vector<tuple<int, int, int, int>> papers;
int ans;

void solve(int i, vector<tuple<int, int, int, int>> &taken) {
	if (i == papers.size()) {
		int area = 0;
		for (auto &[wt, ht, xt, yt]: taken) area += wt * ht;
		ans = max(ans, area);
		return;
	}

	int w, h, x, y;
	tie(w, h, x, y) = papers[i];
	bool ok = true;
	for (auto &[wt, ht, xt, yt]: taken) {
		bool right = x >= xt + wt;
		bool left = x + w <= xt;
		bool above = y + h <= yt;
		bool below = y >= yt + ht;
		if (!right && !left && !above && !below) {
			ok = false;
			break;
		}
	}

	// try to take
	if (ok) {
		taken.pb(papers[i]);
		solve(i + 1, taken);
		taken.pop_back();
	}
	
	// try not to take
	solve(i + 1, taken);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, w, h, x, y;
	cin >> n;
	while (n) {
		papers.clear();
		ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> w >> h >> x >> y;
			papers.pb({w, h, x, y});
		}

		vector<tuple<int, int, int, int>> taken;
		solve(0, taken);
		cout << ans << '\n';
		cin >> n;
	}

	return 0;
}
