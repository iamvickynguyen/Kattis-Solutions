#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long int;

vector<int> trips;
vector<ll> memo(1000002, -1LL);

ll solve(int i, const ll s, const ll p, const ll m) {
	if (i >= trips.size()) return 0;
	if (memo[i] != -1) return memo[i];

	// single
	ll ans = solve(i + 1, s, p, m) + s;

	// period
	int idx = upper_bound(trips.begin() + i + 1, trips.end(), trips[i] + m - 1) - trips.begin();

	ans = min(ans, solve(idx, s, p, m) + p);
	memo[i] = ans;
	return ans;
}

int main() {
	ll s, p, m, n;
	int t;
	cin >> s >> p >> m >> n;
	
	trips.reserve(n);
	for (int i = 0; i < n; ++i) {
		cin >> t;
		trips.push_back(t);
	}

	ll ans = solve(0, s, p, m);
	cout << ans;
	return 0;
}
