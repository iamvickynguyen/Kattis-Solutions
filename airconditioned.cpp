#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
	int n, l, u, count = 1;
	cin >> n;
	vector<pair<int, int>> minions;
	for (int i = 0; i < n; i++) {
		cin >> l >> u;
		minions.push_back(make_pair(l, u));
	}

	sort(minions.begin(), minions.end());
	int upper = minions[0].second;
	for (auto t : minions) {
		if (t.first <= upper) {
			upper = min(t.second, upper);
		}
		else {
			count++;
			upper = t.second;
		}
	}
	cout << count << endl;	
	return 0;
}