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

const int maxN = 100;
int items[maxN];
int dp[maxN][30001];

void init_table(int n, int m, int max_cost) {
	for (int i = 0; i < n; i++) dp[i][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= max_cost; j++) {
			int cur, prev;
			cur = (j >= items[i]) ? dp[i][j - items[i]] : 0;
			prev = (i > 0) ? dp[i - 1][j] : 0;
			dp[i][j] = (cur + prev > 1) ? 2 : cur + prev;
		}
	}
}

void get_answer(int q, int n) {
	if (dp[n - 1][q] < 1) cout << "Impossible\n";
	else if (dp[n - 1][q] > 1) cout << "Ambiguous\n";
	else {
		vi ans;
		int i = n - 1, j = q;
		while (i >= 0 && j > 0) {
			if (j >= items[i] && dp[i][j] == dp[i][j - items[i]]) {
				ans.pb(i);
				j -= items[i];
			} else {
				i--;
			}
		}

		for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] + 1 << " ";
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, max_cost = -1, cost;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> items[i];
	cin >> m;
	vi queries;
	for (int i = 0; i < m; i++) {
		cin >> cost;
		queries.pb(cost);
		max_cost = max(max_cost, cost);
	}

	init_table(n, m, max_cost);
	for (auto &q: queries) get_answer(q, n);

	return 0;
}
