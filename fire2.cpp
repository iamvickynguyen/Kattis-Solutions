#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>
using namespace std;

int main() {
	int tests, w, h;
	cin >> tests;

	const int maxn = 1001;
	char grid[maxn][maxn];

	char c;
	while (tests--) {
		cin >> w >> h;
		queue<pair<int, int>> f1, f2;
		queue<tuple<int, int, int>> p1, p2;

		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				cin >> c;
				grid[i][j] = c;
				if (c == '*') f1.push({i, j});
				else if (c == '@') p1.push({i, j, 0});
			}
		}

		// BFS
		bool ok = false, fflag = true, pflag = true;
		while (!f1.empty() || !f2.empty() || !p1.empty() || !p2.empty()) {
			// spread fire
			queue<pair<int, int>> *fa = fflag ? &f1 : &f2;
			queue<pair<int, int>> *fb = fflag ? &f2 : &f1;
			while (!fa->empty()) {
				auto [i, j] = fa->front();
				fa->pop();

				pair<int, int> neighbors[] = {{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}};
				for (auto &[y, x]: neighbors) {
					if (y >= 0 && y < h && x >= 0 && x < w && grid[y][x] == '.') {
						grid[y][x] = '*';
						fb->push({y, x});
					}
				}
			}

			fflag = !fflag;
			
			// explore rooms
			queue<tuple<int, int, int>> *pa = pflag ? &p1 : &p2;
			queue<tuple<int, int, int>> *pb = pflag ? &p2 : &p1;
			while (!pa->empty()) {
				auto [i, j, steps] = pa->front();
				pa->pop();

				if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
					cout << (steps + 1) << '\n';
					ok = true;
					break;
				}

				pair<int, int> neighbors[] = {{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}};
				for (auto &[y, x]: neighbors) {
					if (y >= 0 && y < h && x >= 0 && x < w && grid[y][x] == '.') {
						grid[y][x] = '@';
						pb->push({y, x, steps + 1});
					}
				}

			}

			if (ok) break;

			pflag = !pflag;
		}

		if (!ok) cout << "IMPOSSIBLE\n";
	}

	return 0;
}
