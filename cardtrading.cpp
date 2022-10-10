#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int main() {
	const int maxT = 100001;
	int n, t, k;
	cin >> n >> t >> k;
	
	int counter[maxT];
	for (int i = 0; i < maxT; ++i) counter[i] = 0;

	int x;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		counter[x]++;
	}

	int buy, sell;
	vector<pii> profits;
	for (int i = 1; i <= t; ++i) {
		cin >> buy >> sell;
		profits.push_back({buy * max(2 - counter[i], 0), sell * counter[i]});
	}

	sort(profits.begin(), profits.end(),
			[](const pii &a, const pii &b) { return (a.first + a.second) < (b.first + b.second); });

	long long ans = 0;
	for (int i = 0; i < k; ++i) {
		ans -= profits[i].first;
	}

	for (int i = k; i < t; ++i) {
		ans += profits[i].second;
	}

	cout << ans;
	return 0;
}
