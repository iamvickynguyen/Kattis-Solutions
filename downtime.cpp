#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k, t, count = 1;
	cin >> n >> k;
	queue<int> q;
	for (int i = 0; i < n; i++) {
		cin >> t;
		q.push(t);
		if (q.front() + 1000 <= t) q.pop();
		count = max(count, (int)(q.size() / k) + ((q.size() % k) ? 1 : 0));
	}

	cout << count;
	return 0;
}