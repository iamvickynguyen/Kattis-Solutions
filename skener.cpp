#include <iostream>
#include <vector>
using namespace std;

int main() {
	int r, c, zr, zc;
	cin >> r >> c >> zr >> zc;
	vector<vector<char>> article(r);
	char chr;
	for (auto &row: article) {
		row.reserve(c);
		for (int i = 0; i < c; ++i) {
			cin >> chr;
			row.push_back(chr);
		}
	}

	vector<vector<char>> ans(r * zr, vector<char>(c * zc));
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			chr = article[i][j];
			for (int y = 0; y < zr; ++y) {
				for (int x = 0; x < zc; ++x) {
					ans[i * zr + y][j * zc + x] = chr;
				}
			}
		}
	}

	for (auto &row: ans) {
		for (auto &letter: row) cout << letter;
		cout << '\n';
	}

	return 0;
}
