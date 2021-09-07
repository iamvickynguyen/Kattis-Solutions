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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int l, d, n;
	cin >> l >> d >> n;

	if (n == 0) {
		cout << (l - 12)/d + 1;
	} else {
		vi birds(n);
		for (int i = 0; i < n; i++) cin >> birds[i];
		sort(all(birds));

		int ans = 0;
		for (int i = 0; i < n - 1; i++) {
			int k = (birds[i + 1] - birds[i])/d - 1;
			if (k > 0) ans += k;
		}

		if (birds[0] != 6) {
			int k = (birds[0] - 6)/d;
			if (k > 0) ans += k;
		}

		if (birds[n - 1] != l - 6) {
			int k = (l - 6 - birds[n - 1])/d;
			if (k > 0) ans += k;
		}

		cout << ans;
	}

	return 0;
}
