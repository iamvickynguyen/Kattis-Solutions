#include <iostream>
#include <vector>
#include <tuple>
#include <math.h>
#include <unordered_set>
#include <queue>
#include <algorithm>
using namespace std;
typedef tuple<double, double, double> ddd;

int get_largest_component(vector<unordered_set<int>> intersection_map, int n) {
	int max_count = 0;
	vector<bool> visited(n, false);
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			queue<int> q;
			q.push(i);
			visited[i] = true;
			int count = 0;
			while (!q.empty()) {
				int cur = q.front();
				q.pop();
				count++;

				for (auto u : intersection_map[cur]) {
					if (!visited[u]) {
						visited[u] = true;
						q.push(u);
					}
				}
			}
			max_count = max(max_count, count);
		}
	}
	return max_count;
}

double dist(double a1, double b1, double a2, double b2) {
	return sqrt(pow(a1 - a2, 2) + pow(b1 - b2, 2));
}

bool intersect(ddd c1, ddd c2) {
	double a1, b1, r1, a2, b2, r2;
	tie(a1, b1, r1) = c1;
	tie(a2, b2, r2) = c2;
	double d = dist(a1, b1, a2, b2);
	return (abs(r1 - r2) <= d && d <= r1 + r2);
}

int main() {
	int n;
	double a, b, r;
	cin >> n;
	while (n != -1) {
		vector<ddd> circles;
		for (int i = 0; i < n; i++) {
			cin >> a >> b >> r;
			circles.push_back(make_tuple(a, b, r));
		}

		if (n == 0)
			cout << "The largest component contains 0 ring." << endl;
		else if (n == 1)
			cout << "The largest component contains 1 ring." << endl;
		else {
			vector<unordered_set<int>> intersection_map(n);
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					if (intersect(circles[i], circles[j])) {
						intersection_map[i].insert(j);
						intersection_map[j].insert(i);
					}		
				}
			}

			int result = get_largest_component(intersection_map, n);
			cout << "The largest component contains " << result << (result < 2 ? " ring." : " rings.") << endl;
		}

		cin >> n;
	}

	return 0;
}