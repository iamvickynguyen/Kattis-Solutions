#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

int main() {
	vector<vector<int>> board(8, vector<int>(8, 0));
	vector<pair<int, int>> queens;
	char q;
	for (int r = 0; r < 8; r++) {
		for (int c = 0; c < 8; c++) {
			cin >> q;
			if (q == '*') {
				board[r][c] = 1;
				queens.push_back(make_pair(r, c));
			}
		}
	}

	if (queens.size() != 8) {
		cout << "invalid\n";
		return 0;
	}

	for (auto queen : queens) {
		int r = queen.first, c = queen.second;

		// row
		for (int i = 0; i < 8; i++) {
			if (board[r][i] == 1 && i != c) {
				cout << "invalid\n";
				return 0;
			}
		}

		// column
		for (int i = 0; i < 8; i++) {
			if (board[i][c] == 1 && i != r) {
				cout << "invalid\n";
				return 0;
			}
		}

		// left diagonal
		int x = c, y = r;
		while (x - 1 >= 0 && y - 1 >= 0) {
			x -= 1;
			y -= 1;
			if (board[y][x] == 1 && y != r && x != c) {
				cout << "invalid\n";
				return 0;
			}
		}
		x = c, y = r;
		while (x + 1 < 8 && y + 1 < 8) {
			x += 1;
			y += 1;
			if (board[y][x] == 1 && y != r && x != c) {
				cout << "invalid\n";
				return 0;
			}
		}

		// right diagonal
		x = c, y = r;
		while (x + 1 < 8 && y - 1 >= 0) {
			x += 1;
			y -= 1;
			if (board[y][x] == 1 && y != r && x != c) {
				cout << "invalid\n";
				return 0;
			}
		}
		while (x - 1 >= 0 && y + 1 < 8) {
			x -= 1;
			y += 1;
			if (board[y][x] == 1 && y != r && x != c) {
				cout << "invalid\n";
				return 0;
			}
		}
	}
	cout << "valid\n";
	return 0;
}