#include <iostream>
#include <algorithm>
using namespace std;
int dp[151][151][51]; // dp[numCokes][n5][n10]

int solver(int c, int n1, int n5, int n10) {
	if (c == 0) return 0;

	if (dp[c][n5][n10] != -1) return dp[c][n5][n10];

	// all 1s
	if (n5 == 0 && n10 == 0) return c * 8;

	int result = c * 8;

	// 10 -> 1 1
	if (n10 > 0)
		result = min(result, 1 + solver(c - 1, n1 + 2, n5, n10 - 1));

	// 10 1 1 1 -> 5
	if (n10 > 0 && n1 >= 3)
		result = min(result, 4 + solver(c - 1, n1 - 3, n5 + 1, n10 - 1));

	// 5 5 -> 1 1
	if (n5 >= 2)
		result = min(result, 2 + solver(c - 1, n1 + 2, n5 - 2, n10));

	// 5 1 1 1 -> 0
	if (n5 > 0 && n1 >= 3)
		result = min(result, 4 + solver(c - 1, n1 - 3, n5 - 1, n10));

	dp[c][n5][n10] = result;
	return dp[c][n5][n10];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, c, n1, n5, n10;
	cin >> t;
	while (t--) {
		cin >> c >> n1 >> n5 >> n10;

		// reset
		for (auto& a : dp) {
			for (auto& b : a) {
				for (auto& e : b) {
					e = -1;
				}
			}
		}

		cout << solver(c, n1, n5, n10) << endl;
	}
}