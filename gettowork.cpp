#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int c, n, t, e, h, p;
	cin >> c;
	for (int i = 1; i <= c; i++) {
		cin >> n >> t >> e;
		t--;
		vector<vector<int>> towns(n);
		for (int k = 0; k < e; k++) {
			cin >> h >> p;
			towns[h-1].push_back(p);
		}

		bool is_impossible = false;
		vector<int> result(n);
		for (int k = 0; k < n; k++) {
			if (k == t) result[t] = 0;
			else {
				sort(towns[k].begin(), towns[k].end(), greater<int>());
				int count = 0, total_employees = towns[k].size();
				for (int j = 0; j < towns[k].size(); j++) {
					if (total_employees <= 0) break;
					total_employees -= towns[k][j];
					count++;
				}

				if (total_employees > 0) {
					is_impossible = true;
					break;
				}

				result[k] = count;
			}
		}

		if (is_impossible)
			cout << "Case #" << i << ": IMPOSSIBLE" << endl;
		else {
			cout << "Case #" << i << ":";
			for (auto count : result) {
				cout << " " << count;
			}
			cout << endl;
		}
	}
	return 0;
}