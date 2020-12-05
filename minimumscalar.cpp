#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;

int main() {
	int t, n, x;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		vector<int> v1;
		vector<int> v2;
		for (int j = 0; j < n; j++) {
			cin >> x;
			v1.push_back(x);
		}
		for (int j = 0; j < n; j++) {
			cin >> x;
			v2.push_back(x);
		}

		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		reverse(v2.begin(), v2.end());

		ll result = 0;
		for (int j = 0; j < n; j++) {
			result += (ll)v1[j] * (ll)v2[j];
		}

		cout << "Case #" << i << ": " << result << endl;
	}

	return 0;
}