#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;

int main() {
	int n, m, x;
	cin >> n >> m;
	vector<int> cans;
	for (int i = 0; i < n; i++) {
		cin >> x;
		cans.push_back(x);
	}

	sort(cans.begin(), cans.end());
	ll waste = 0;
	for (int i = 0; i < m; i++) {
		cin >> x;
		int index = lower_bound(cans.begin(), cans.end(), x) - cans.begin();
		waste += cans[index] - x;
	}

	cout << waste;
	return 0;
}