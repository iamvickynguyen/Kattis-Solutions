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

	int n;
	cin >> n;
	vi v(n);
	for (auto &d: v) cin >> d;

	int total = accumulate(all(v), 0);
	if (total % 3 != 0) cout << -1;
	else {
		int capacity = total/3;
		int cnt = 0;
		vi ans;
		for (int i = 0; i < n; i++) {
			cnt += v[i];
			if (cnt == capacity) {
				ans.pb(i + 1);
				cnt = 0;
			}
			else if (cnt > capacity) break;
		}

		if (ans.size() != 3) cout << -1;
		else cout << ans[0] << " " << ans[1];
	}

	return 0;
}
