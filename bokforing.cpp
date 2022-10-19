#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int main() {
	int n, q, x, i, count = 0, reset_value = 0;
	cin >> n >> q;
	
	vector<pair<int, int>> money(n);
	string type;
	for (int j = 0; j < q; ++j) {
		cin >> type;
		if (type == "SET") {
			cin >> i >> x;
			money[i - 1].first = x;
			money[i - 1].second = count;
		} else if (type == "RESTART") {
			cin >> x;
			reset_value = x;
			++count;
		} else {
			cin >> i;
			auto &[val, cnt] = money[i - 1];
			if (cnt != count) cout << reset_value << '\n';
			else cout << val << '\n';
		}
	}

	return 0;
}
