#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

void fill_outer(vector<vector<char>>& board, const int n, const int m) {
	queue<pair<int, int>> q;
	q.push({0, 0});
	board[0][0] = 'x';

	while (!q.empty()) {
		auto &[i, j] = q.front();
		q.pop();

		pair<int, int> neighbors[] = {{i-1, j}, {i+1, j}, {i, j-1}, {i, j+1}};
		for (auto &[y, x]: neighbors) {
			if (x >= 0 && x < (m + 2) && y >= 0 && y < (n + 2) && board[y][x] == '0') {
				board[y][x] = 'x';
				q.push({y, x});
			}
		}
	}
}

int coastlength(vector<vector<char>> &board, const int n, const int m) {
	// count
	int total = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (board[i][j] != '1')
				continue;
			
			pair<int, int> neighbors[] = {{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}};
			for (auto &[y, x]: neighbors) {
				if (board[y][x] == 'x')
					++total;
			}
		}
	}

	return total;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> board(n + 2, vector<char>(m + 2, '0'));

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> board[i][j];
		}
	}

	fill_outer(board, n, m);
	cout << coastlength(board, n, m);

}
