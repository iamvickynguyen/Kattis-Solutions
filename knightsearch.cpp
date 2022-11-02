#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int n;
string board;
constexpr char favorite[] = "ICPCASIASG";

bool explore(const int i, const int j, const int k) {
	if (k == 10)
		return true;

	if (favorite[k] != board[i * n + j])
		return false;
	
	pair<int, int> moves[] = {
		{i - 2, j - 1}, {i - 2, j + 1}, {i - 1, j + 2}, {i + 1, j + 2},
		{i + 2, j + 1}, {i + 2, j - 1}, {i + 1, j - 2}, {i - 1, j - 2}
	};
	
	for (auto &[row, col]: moves) {
		if (row >= 0 && row < n && col >= 0 && col < n) {
			if (explore(row, col, k + 1))
				return true;
		}
	}
	
	return false;
}

int main() {
	cin >> n >> board;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (explore(i, j, 0)) {
				cout << "YES";
				return 0;
			}
		}
	}
	
	cout << "NO";
	return 0;
}
