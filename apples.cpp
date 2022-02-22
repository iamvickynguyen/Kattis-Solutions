#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef unordered_set<int> usi;
typedef unordered_map<int, vi> ivi;
typedef unordered_map<int, int> ii;
#define all(x) (x).begin(), (x).end()
#define pb push_back

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int r, c;
	cin >> r >> c;
	vector<vector<char>> grid(r, vector<char>(c));
	for (auto &row: grid) {
		for (auto &cell: row) cin >> cell;
	}

	for (int j = 0; j < c; j++) {
		int empty = r - 1;
		while (empty >= 0) {
			while (empty >= 0 && grid[empty][j] == '#') empty--;
			for (int i = empty; i >= 0; i--) {
				if (grid[i][j] == '#') {
					empty = i;
					break;
				} else if (grid[i][j] == 'a') {
					swap(grid[i][j], grid[empty][j]);
					empty--;
				}

				if (i == 0) empty = -1;
			}
		}
	}

	for (auto &row: grid) {
		for (auto &cell: row) cout << cell;
		cout << '\n';
	}

	return 0;
}
