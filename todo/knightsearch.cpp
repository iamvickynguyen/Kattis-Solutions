#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int n, count = 10;
string board;
int counter[26];
const char letters[6] = {'I', 'C', 'P', 0, 'S', 'G'};

bool explore(const int i, const int j) {
	bool decrement = false;
	for (const char letter: letters) {
		if (board[i * n + j] == letter && counter[letter - 'A'] > 0) {
			--counter[letter - 'A'];
			--count;
			decrement = true;
			break;
		}
	}


	if (count <= 0) return true;

	//cout << "EXPLORE: " << i << " " << j << ", count: " << count << '\n';

	const char c = board[i * n + j];
	board[i * n + j] = '#';
	
	vector<pair<int, int>> moves = {
		{i - 2, j - 1}, {i - 2, j + 1}, {i - 1, j + 2}, {i + 1, j + 2},
		{i + 2, j + 1}, {i + 2, j - 1}, {i + 1, j - 2}, {i - 1, j - 2}
	};
	
	for (auto &[row, col]: moves) {
		const int p = row * n + col;
		if (row >= 0 && row < n && col >= 0 && col < n && board[p] != '#') {
			if (explore(row, col))
				return true;
		}
	}

	if (decrement) {
		++count;
		++counter[i * n + j];
	}
	
	board[i * n + j] = c;
	return false;
}

int main() {
	counter['I' - 'A'] = 2;
	counter['C' - 'A'] = 2;
	counter['P' - 'A'] = 1;
	counter['A' - 'A'] = 2;
	counter['S' - 'A'] = 2;
	counter['G' - 'A'] = 1;
			
	cin >> n >> board;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (board[i * n + j] == 'I') {
				if (explore(i, j)) {
					cout << "YES";
					return 0;
				}
			}
		}
	}
	
	cout << "NO";
	return 0;
}
