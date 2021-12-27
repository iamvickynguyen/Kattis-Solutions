#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef priority_queue<int, vector<int>, greater<int>> minpq;
typedef unordered_set<int> usi;
typedef unordered_map<int, vi> ivi;
typedef unordered_map<int, int> ii;
#define all(x) (x).begin(), (x).end()
#define pb push_back

vector<tuple<int, int, int>> robots; // tuple <x, y, direction>
int grid[101][101];

int convert(char dir) {
	if (dir == 'N') return 0;
	if (dir == 'E') return 1;
	if (dir == 'S') return 2;
	return 3;
}

string forward(int x, int y, int d, int index, int repeat, int w, int h) {
	grid[y][x] = -1;
	if (d == 0) {
		for (int i = 0; i < repeat; i++) {
			y--;
			if (y < 0) return "Robot " + to_string(index + 1) + " crashes into the wall";
			if (grid[y][x] != -1) return "Robot " + to_string(index + 1) + " crashes into robot " + to_string(grid[y][x] + 1);
		}
	} else if (d == 1) {
		for (int i = 0; i < repeat; i++) {
			x++;
			if (x >= w) return "Robot " + to_string(index + 1) + " crashes into the wall";
			if (grid[y][x] != -1) return "Robot " + to_string(index + 1) + " crashes into robot " + to_string(grid[y][x] + 1);
		}
	} else if (d == 2) {
		for (int i = 0; i < repeat; i++) {
			y++;
			if (y >= h) return "Robot " + to_string(index + 1) + " crashes into the wall";
			if (grid[y][x] != -1) return "Robot " + to_string(index + 1) + " crashes into robot " + to_string(grid[y][x] + 1);
		}
	} else {
		for (int i = 0; i < repeat; i++) {
			x--;
			if (x < 0) return "Robot " + to_string(index + 1) + " crashes into the wall";
			if (grid[y][x] != -1) return "Robot " + to_string(index + 1) + " crashes into robot " + to_string(grid[y][x] + 1);
		}
	}

	grid[y][x] = index;
	robots[index] = {x, y, d};
	return "OK";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, w, h, n, m, x, y, d;
	char dir;
	cin >> t;
	while (t--) {
		cin >> w >> h >> n >> m;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) grid[i][j] = -1;
		}
		robots.clear();

		for (int i = 0; i < n; i++) {
			cin >> x >> y >> dir;
			x--; y--;
			robots.pb({x, h - y - 1, convert(dir)});
			grid[h - y - 1][x] = i;
		}

		int robot, repeat;
		char action;
		string status = "OK";
		for (int i = 0; i < m; i++) {
			cin >> robot >> action >> repeat;

			if (status == "OK") {
				tie(x, y, d) = robots[robot - 1];

				if (action == 'F') {
					status = forward(x, y, d, robot - 1, repeat, w, h);
				} else if (action == 'L') {
					repeat %= 4;
					d = (d - repeat + 4) % 4;
					robots[robot - 1] = {x, y, d};
				} else {
					d = (d + repeat) % 4;
					robots[robot - 1] = {x, y, d};
				}
			}
		}

		cout << status << '\n';
	}

	return 0;
}
