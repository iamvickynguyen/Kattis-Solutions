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

ll solve(vector<pii> &locations, int k) {
	ll ans = 0;
	sort(all(locations));
	int i = locations.size() - 1;
	while (i >= 0) {
		ans += 1LL * (locations[i].second/k) * locations[i].first * 2;
		int remaining = locations[i].second % k;
		if (remaining != 0) {
			ans +=  1LL * locations[i].first * 2;
			i--;
			int spares = k - remaining;
			while (spares > 0 && i >= 0) {
				if (spares > locations[i].second) {
					spares -= locations[i].second;
					i--;
				} else {
					locations[i].second -= spares;
					spares = 0;
				}
			}
		} else {
			i--;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k, x, t;
	cin >> n >> k;
	vector<pii> left_locations, right_locations;
	for (int i = 0; i < n; i++) {
		cin >> x >> t;
		if (x < 0) left_locations.pb({-x, t});
		else right_locations.pb({x, t});
	}

	ll ans = solve(left_locations, k);
	ans += solve(right_locations, k);
	cout << ans;

	return 0;
}
