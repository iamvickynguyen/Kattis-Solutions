#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t, n, m;
	int x;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		vector<int> v;
		vector<int> positions;
		for (int i = 0; i < n; i++) {
			cin >> x;
			v.push_back(x);

			if (x == m)
				positions.push_back(i);
		}

		int maxweight = 0;
		for (int p : positions) {
			int weight = v[p];

			int left = p - 1;
			while (left >= 0 && v[left] > m) {
				weight += v[left];
				left--;
			}

			int right = p + 1;
			while (right < n && v[right] > m) {
				weight += v[right];
				right++;
			}

			maxweight = max(maxweight, weight);
		}

		cout << maxweight;
		if (t > 0)
			cout << endl;
	}

	return 0;
}