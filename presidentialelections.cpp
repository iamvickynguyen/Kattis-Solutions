#include <stdio.h>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_DEL = 2016;
const int INF = pow(10, 9);

int main() {
	int n, d, c, f, u, total_delegates = 0;
	scanf("%d", &n);
	vector<vector<int>> dp(n + 1, vector<int>(MAX_DEL + 1, INF));
	dp[0][0] = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &d, &c, &f, &u);
		total_delegates += d;

		int votes_needed = (c + f + u) / 2 - c + 1;
		for (int j = 0; j <= MAX_DEL; j++) {
			if (dp[i][j] != INF) {
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);

				if (votes_needed <= u) {
					if (votes_needed <= 0 && j + d <= MAX_DEL) {
						dp[i + 1][j + d] = min(dp[i + 1][j + d], dp[i][j]);
					}
					else if (j + d <= MAX_DEL) {
						dp[i + 1][j + d] = min(dp[i + 1][j + d], dp[i][j] + votes_needed);
					}
				}
			}
		}
	}

	int need = total_delegates / 2 + 1;
	int min_votes = INF;
	for (int i = need; i <= MAX_DEL; i++)
		min_votes = min(min_votes, dp[n][i]);

	if (min_votes == INF)
		printf("impossible");
	else
		printf("%d", min_votes);

	return 0;
}