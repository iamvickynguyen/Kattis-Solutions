#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

constexpr int INF = 1e9;

struct point {
	int y;
	int x;
	int cost;
	point(int y, int x, int cost): y(y), x(x), cost(cost) {}
};

struct cmpPoint {
	bool operator() (const point &a, const point &b) {
		return a.cost > b.cost;
	}
};

int dijkstra(vector<vector<int>>& grid, const int h, const int w) {
	vector<vector<int>> dist(h, vector<int>(w, INF));
	dist[0][0] = 0;

	priority_queue<point, vector<point>, cmpPoint> q;
	q.push(point(0, 0, 0));
	
	while (!q.empty()) {
		point p = q.top(); q.pop();
		const int y = p.y, x = p.x, cost = p.cost;
		
		if (cost > dist[y][x]) continue;

		pair<int, int> neighbors[] = {{y - 1, x}, {y + 1, x}, {y, x - 1}, {y, x + 1}};
		for (auto& [row, col]: neighbors) {
			if (row >= 0 && row < h && col >= 0 && col < w) {
				const int new_cost = max(cost, max(grid[row][col] - grid[y][x], 0));
				if (new_cost < dist[row][col]) {
					dist[row][col] = new_cost;
					q.push(point(row, col, new_cost));
				}
			}
		}
	}

	return dist[h - 1][w - 1];
}

int main() {
	int m, n, coins;
	cin >> m >> n;
	vector<vector<int>> grid(m);
	for (auto& row: grid) {
		row.reserve(n);
		for (int i = 0; i < n; ++i) {
			cin >> coins;
			row.push_back(coins);
		}
	}

	cout << dijkstra(grid, m, n);
	return 0;
}
