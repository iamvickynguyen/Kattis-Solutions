#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>>& board, int i, int j, const int height, const int width) {
	board[i][j] = 'x';
	pair<int, int> neighbors[] = {
		{i+1, j}, {i-1, j}, {i, j-1}, {i, j+1},
		{i-1, j-1}, {i-1, j+1}, {i+1, j-1}, {i+1, j+1}
	};
	for (auto &[y, x]: neighbors) {
		if (y >= 0 && y < height && x >= 0 && x < width && board[y][x] == '#') {
			dfs(board, y, x, height, width);
		}
	}
}

int main() {
	int m, n;
	cin >> m >> n;
	vector<vector<char>> board(m, vector<char>(n));
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
		}
	}

	int count = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (board[i][j] == '#') {
				dfs(board, i, j, m, n);
				++count;
			}
		}
	}

	cout << count;
}
