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

const int INF = 2000005;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;
 	s--; g--;

	vi dp(f, INF);
	dp[s] = 0;
	for (int i = s - 1; i >= 0; i--) {
		if ((i + d) < f) dp[i] = min(dp[i], dp[i + d] + 1);
		if ((i + d - u) >= 0 && (i + d - u) < f) dp[i] = min(dp[i], dp[i + d - u] + 2);
	}

	if (g <= s) {
		if (dp[g] == INF) cout << "use the stairs";
		else cout << dp[g];
	} else {
		for (int i = s + 1; i < f; i++) {
			if ((i - u) >= 0) dp[i] = min(dp[i], dp[i - u] + 1);
			if ((i - (u - d)) >= 0 && (i - (u - d)) < f) dp[i] = min(dp[i], dp[i - u + d] + 2);
		}
		if (dp[g] == INF) cout << "use the stairs";
		else cout << dp[g];
	}
	
	return 0;
}
