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

	int p, K, n, m, k;
	cin >> p;
	while (p--) {
		cin >> K >> n >> m >> k;
		vi dp(n + 1, 0);
		int i = 1;
		while (i <= n && ((i % k) == m)) i++;
		
		while (i <= n) {
			if ((i % k) != m) dp[i] = 1;
			for (int j = 1; j < i; j++) {
				if ((j % k) != m && (i - j) >= 0)
					dp[i] += dp[i - j];
			}
			i++;
		}
		cout << K << " " << dp[n] << '\n';
	}

	return 0;
}
