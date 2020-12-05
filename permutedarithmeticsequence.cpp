#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;

bool is_arit(vector<ll> &v, int m) {
	ll diff = v[1] - v[0];
	for (int i = 2; i < m; i++) {
		if (v[i] - v[i - 1] != diff) {
			return false;
		}
	}
	return true;
}

int main() {
	int n, m;
	ll x;
	cin >> n;
	while (n--) {
		vector<ll> v;
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> x;
			v.push_back(x);
		}

		if (is_arit(v, m))
			cout << "arithmetic" << endl;
		else {
			sort(v.begin(), v.end());
			if (is_arit(v, m))
				cout << "permuted arithmetic" << endl;
			else
				cout << "non-arithmetic" << endl;
		}
	}

	return 0;
}