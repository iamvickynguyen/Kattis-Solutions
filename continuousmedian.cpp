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

	int t, n;
	ll x;
	cin >> t;
	while (t--) {
		cin >> n;
		ll ans = 0;
		priority_queue<ll> max_heap, min_heap;
		for (int i = 1; i <= n; i++) {
			cin >> x;
			if (max_heap.size() > min_heap.size()) {
				min_heap.push(-x);
				ll min_val = -min_heap.top();
				min_heap.pop();

				max_heap.push(min_val);
				ll max_val = max_heap.top();
				max_heap.pop();
				min_heap.push(-max_val);
			} else {
				max_heap.push(x);
				ll max_val = max_heap.top();
				max_heap.pop();

				min_heap.push(-max_val);
				ll min_val = -min_heap.top();
				min_heap.pop();
				max_heap.push(min_val);
			}

			if (i % 2 == 0) {
				ans += (max_heap.top() - min_heap.top())/2;
			} else {
				ans += max_heap.top();
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
