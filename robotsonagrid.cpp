#include <stdio.h>
#include <math.h>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef long long int ll;
const int MOD = pow(2, 31) - 1;

int bfs(int n, vector<vector<bool>> grid) {
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	visited[0][0] = true;

	while (!q.empty()) {
		pair<int, int> p = q.front();
		int row = p.first;
		int col = p.second;
		q.pop();

		// up
		if (row > 0 && !visited[row - 1][col] && grid[row - 1][col]) {
			visited[row - 1][col] = true;
			q.push(make_pair(row - 1, col));
		}

		// down
		if (row < n - 1 && !visited[row + 1][col] && grid[row + 1][col]) {
			visited[row + 1][col] = true;
			q.push(make_pair(row + 1, col));
		}

		// left
		if (col > 0 && !visited[row][col - 1] && grid[row][col - 1]) {
			visited[row][col - 1] = true;
			q.push(make_pair(row, col - 1));
		}

		// right
		if (col < n - 1 && !visited[row][col + 1] && grid[row][col + 1]) {
			visited[row][col + 1] = true;
			q.push(make_pair(row, col + 1));
		}
	}

	return visited[n - 1][n - 1];
}

int main() {
	int n;
	char c;
	scanf("%d", &n);
	vector<vector<bool>> grid;
	vector<vector<int>> dp(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		vector<bool> row;
		for (int j = 0; j < n; j++) {
			scanf(" %c", &c);
			row.push_back(c == '.');
		}
		grid.push_back(row);
	}

	dp[0][0] = 1;
	for (int i = 1; i < n; i++) {
		if (grid[0][i])
			dp[0][i] = dp[0][i - 1];
		if (grid[i][0])
			dp[i][0] = dp[i - 1][0];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (grid[i][j]) {
				ll val = ((long long int)dp[i - 1][j] + (long long int)dp[i][j - 1]) % MOD;
				dp[i][j] = (int)val;
			}
		}
	}

	if (dp[n - 1][n - 1] > 0)
		printf("%d", dp[n - 1][n - 1]);
	else if (bfs(n, grid))
		printf("THE GAME IS A LIE");
	else
		printf("INCONCEIVABLE");

	return 0;
}