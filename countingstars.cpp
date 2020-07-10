#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

void bfs(vector<vector<bool>> &graph, int i, int j) {
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	graph[i][j] = true;

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		int y = cur.first, x = cur.second;
		q.pop();

		// up
		if (y - 1 >= 0 && !graph[y-1][x]) {
			q.push(make_pair(y-1, x));
			graph[y-1][x] = true;
		}

		// left
		if (x - 1 >= 0 && !graph[y][x - 1]) {
			q.push(make_pair(y, x - 1));
			graph[y][x-1] = true;
		}

		// right
		if (x + 1 < graph[0].size() && !graph[y][x + 1]) {
			q.push(make_pair(y, x + 1));
			graph[y][x+1] = true;
		}

		// down
		if (y + 1 < graph.size() && !graph[y+1][x]) {
			q.push(make_pair(y+1, x));
			graph[y+1][x] = true;
		}
	}
}

int main() {
	int m, n;
	int k = 1;
	while (cin >> m >> n) {
		vector<vector<bool>> graph(m, vector<bool>(n, false));
		char c;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> c;
				if (c == '#')
					graph[i][j] = true;
			}
		}

		int count = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (!graph[i][j]) {
					bfs(graph, i, j);
					count += 1;
				}
			}
		}

		cout << "Case " << k << ": " << count << '\n';
		k += 1;
	}

	return 0;
}