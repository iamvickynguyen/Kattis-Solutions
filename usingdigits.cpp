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

const int maxn = 101;
const int inf = 1805;
int grid[maxn][maxn];
int x, y;
string code;
int ans = inf;
int dp[maxn][maxn][maxn + maxn];

int solve(int r, int c, int p) {
	if (r >= y || c >= x) return inf;
	if (r == y - 1 && c == x - 1) return grid[y - 1][x - 1];
	if (dp[r][c][p] < inf) return dp[r][c][p];

	int opt = inf;

	// try code key
	if (p < code.length()) {
		int key = code[p] - '0';
		if (r + key + 1 < y) {
			opt = min(opt, grid[r][c] + solve(r + key + 1, c, p + 1));
		}
		if (c + key + 1 < x) {
			opt = min(opt, grid[r][c] + solve(r, c + key + 1, p + 1));
		}
	}

	// try step
	if (r + 1 < y) {
		opt = min(opt, grid[r][c] + solve(r + 1, c, p));
	}

	if (c + 1 < x) {
		opt = min(opt, grid[r][c] + solve(r, c + 1, p));
	}

	dp[r][c][p] = opt;
	return dp[r][c][p];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> x >> y >> code;
	string s;
	for (int i = 0; i < y; i++) {
		cin >> s;
		for (int j = 0; j < x; j++)
			grid[y - i - 1][j] = s[j] - '0';
	}

	// init
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			for (int k = 0; k < maxn + maxn; k++) {
				dp[i][j][k] = inf;
			}
		}
	}

	cout << solve(0, 0, 0);
	return 0;
}
