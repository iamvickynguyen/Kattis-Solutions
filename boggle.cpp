#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

bool search(char (&board)[4][4], string& s, int y, int x, int i,
		char (&seen)[4][4]) {
	if (i == s.length())
		return true;

	if (y < 0 || y >= 4 || x < 0 || x >= 4 || seen[y][x] == '1')
		return false;

	if (board[y][x] != s[i])
		return false;

	pair<int, int> neighbors[] = {{y - 1, x}, {y + 1, x}, {y, x - 1}, {y, x + 1},
		{y - 1, x - 1}, {y - 1, x + 1}, {y + 1, x + 1}, {y + 1, x - 1}};
	for (auto& [row, col]: neighbors) {
		seen[y][x] = '1';
		bool result = search(board, s, row, col, i + 1, seen);
		seen[y][x] = '0';

		if (result) return true;
	}

	return false;
}

bool found(char (&board)[4][4], string& s, char (&seen)[4][4]) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0;j < 4; ++j) {
			if (search(board, s, i, j, 0, seen))
				return true;
		}
	}
	return false;
}

int main() {
  int n;
  cin >> n;
	vector<string> words;
	words.reserve(n);

  string s;
  while (n--) {
    cin >> s;
  	words.push_back(s);
	}
	
	int scores[] = {0, 0, 0, 1, 1, 2, 3, 5, 11};

	char seen[4][4];
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			seen[i][j] = '0';
		}
	}

  cin >> n;
	char board[4][4];
	while (n--) {
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				cin >> board[i][j];
			}
		}

		int count = 0, score = 0;
		string longestword = "";
		for (auto& w: words) {
			if (found(board, w, seen)) {
				++count;
				score += scores[w.length()];
				if (w.length() > longestword.length()
						|| (w.length() == longestword.length() && w < longestword))
					longestword = w;
			}
		}

		cout << score << " " << longestword << " " << count << '\n';
	}

  return 0;
}
