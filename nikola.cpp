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

const int inf = 1000005;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vi v(n);
	for (auto &x: v) cin >> x;

	priority_queue<tuple<int, int, int>> pq; // <cost, index, step>
	pq.push({-v[1], 1, 1});
	vvi dist(n, vi(n, inf));
	dist[1][0] = v[1];

	while (!pq.empty()) {
		int cost, index, step;
		tie(cost, index, step) = pq.top();
		pq.pop();

		if (index == n - 1) {
			cout << -cost;
			break;
		}

		if (index - step >= 0 && dist[index - step][index] > -cost + v[index - step]) {
			dist[index - step][index] = -cost + v[index - step];
			pq.push({cost - v[index - step], index - step, step});
		}

		if (index + step + 1 < n && dist[index + step + 1][index] > -cost + v[index + step + 1]) {
			dist[index + step + 1][index] = -cost + v[index + step + 1];
			pq.push({cost - v[index + step + 1], index + step + 1, step + 1});
		}
	}

	return 0;
}
