#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;
typedef tuple<int, int, int> iii;

int main() {
	int r, c, gr, gc, lr, lc;
	while (cin >> r >> c >> gr >> gc >> lr >> lc) {
		gr--; gc--; lr--; lc--;
		vector<vector<bool>> visited(r, vector<bool>(c, false));
		queue<iii> q;
		q.push(make_tuple(gr, gc, 0));
		visited[gr][gc] = true;

		bool impossible = true;
		while (!q.empty()) {
			int y, x, step;
			tie(y, x, step) = q.front();
			q.pop();

			if (y == lr && x == lc) {
				cout << step << endl;
				impossible = false;
				break;
			}

			if (y - 2 >= 0 && x + 1 < c && !visited[y - 2][x + 1]) {
				visited[y - 2][x + 1] = true;
				q.push(make_tuple(y - 2, x + 1, step + 1));
			}

			if (y - 1 >= 0 && x + 2 < c && !visited[y - 1][x + 2]) {
				visited[y - 1][x + 2] = true;
				q.push(make_tuple(y - 1, x + 2, step + 1));
			}

			if (y + 1 < r && x + 2 < c && !visited[y + 1][x + 2]) {
				visited[y + 1][x + 2] = true;
				q.push(make_tuple(y + 1, x + 2, step + 1));
			}

			if (y + 2 < r && x + 1 < c && !visited[y + 2][x + 1]) {
				visited[y + 2][x + 1] = true;
				q.push(make_tuple(y + 2, x + 1, step + 1));
			}

			if (y + 2 < r && x - 1 >= 0 && !visited[y + 2][x - 1]) {
				visited[y + 2][x - 1] = true;
				q.push(make_tuple(y + 2, x - 1, step + 1));
			}

			if (y + 1 < r && x - 2 >= 0 && !visited[y + 1][x - 2]) {
				visited[y + 1][x - 2] = true;
				q.push(make_tuple(y + 1, x - 2, step + 1));
			}

			if (y - 1 >= 0 && x - 2 >= 0 && !visited[y - 1][x - 2]) {
				visited[y - 1][x - 2] = true;
				q.push(make_tuple(y - 1, x - 2, step + 1));
			}

			if (y - 2 >= 0 && x - 1 >= 0 && !visited[y - 2][x - 1]) {
				visited[y - 2][x - 1] = true;
				q.push(make_tuple(y - 2, x - 1, step + 1));
			}
		}

		if (impossible)
			cout << "impossible" << endl;
	}

	return 0;
}
