#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
const int INF = 9999;

int main() {
	int n, m, x;
	cin >> n;
	while (n--) {
		cin >> m;
		vector<int> arr;
		int sum = 0;
		for (int i = 0; i < m ; i++) {
			cin >> x;
			sum += x;
			arr.push_back(x);
		}

		vector<vector<int>> opt_height(m, vector<int>(sum + 1, INF));
		vector<vector<int>> decision(m, vector<int>(sum + 1, 0));
		opt_height[0][arr[0]] = arr[0]; // up
		decision[0][arr[0]] = 1; // 1: up, -1: down

		for (int r = 1; r < m; r++) {
			for (int h = 0; h < sum + 1; h++) {
				if (opt_height[r - 1][h] != INF) {

					// down
					if (h >= arr[r]) {
						if (h - arr[r] < opt_height[r][h - arr[r]]) {
							if (opt_height[r][h - arr[r]] >= opt_height[r - 1][h]) {
								opt_height[r][h - arr[r]] = opt_height[r - 1][h];
								decision[r][h - arr[r]] = -1;
							}
						}
					}

					// up
					if (h + arr[r] < opt_height[r][h + arr[r]]) {
						int k = max(h + arr[r], opt_height[r - 1][h]);
						if (opt_height[r][h + arr[r]] >= k) {
							opt_height[r][h + arr[r]] = k;
							decision[r][h + arr[r]] = 1;
						}
					}
				}
			}
		}

		if (decision[m - 1][0] != -1) {
			cout << "IMPOSSIBLE" << endl;
		}
		else {
			int h = 0;
			string s = "";
			for (int i = m - 1; i >= 0; i--) {
				if (decision[i][h] == 1) {
					h -= arr[i];
					s += "U";
				}
				else {
					h += arr[i];
					s += "D";
				}
			}

			for (int i = m - 1; i >= 0; i--) {
				cout << s[i];
			}
			cout << endl;
		}
	}

	return 0;
}