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

	int n;
	cin >> n;
	vi v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	int ans = 0;
	vi lis(n, 1), lds(n, 1);
	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j > i; j--) {
			if (v[j] > v[i]) lis[i] = max(lis[i], lis[j] + 1);
			if (v[j] < v[i]) lds[i] = max(lds[i], lds[j] + 1);
		}

		ans = max(ans, lis[i] + lds[i] - 1);
	}

	cout << ans;
	return 0;
}
