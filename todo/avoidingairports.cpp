#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
using ll = long long int;

constexpr ll MAXVAL = 2e17;

struct flight {
	int country;
	vector<pair<int, int>> schedule;
};

vector<vector<flight>> airports;

ll explore(const int country, const int n, const ll frustration, const ll start, const ll end) {
	if (country == n) return frustration;

	ll min_frustration = MAXVAL;
	for (auto &flight: airports[country]) {
		pair<int, int> tmp = {end, end};
		int p = lower_bound(flight.schedule.begin(), flight.schedule.end(), tmp,
				[](const pair<int, int> &lhs, const pair<int, int> &rhs) -> bool {return lhs.first < rhs.first;}) - flight.schedule.begin();
		for (int i = p; i < flight.schedule.size(); ++i) {
			ll time = flight.schedule[i].first - end;
			min_frustration = min(min_frustration, explore(flight.country, n, frustration + time * time, flight.schedule[i].first, flight.schedule[i].second));
		}
	}

	return frustration + min_frustration;
}


int main() {
	int n, m, a, b, s, e;
	cin >> n >> m;
	
	airports.resize(n);
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> s >> e;
		--a; --b;
		struct flight fl;
		fl.country = b;
		fl.schedule.push_back({s, e});
		airports[a].push_back(move(fl));
	}

	// sort
	for (auto &flights: airports) {
		for (auto &flight: flights) {
			sort(flight.schedule.begin(), flight.schedule.end());
		}
	}

	// explore
	ll ans = MAXVAL;
	for (auto &flight: airports[0]) {
		for (auto &time: flight.schedule) {
			ll frustration = explore(0, n - 1, time.first * time.first, time.first, time.second);
			ans = min(ans, frustration);
		}
	}

	cout << ans;
	return 0;
}
