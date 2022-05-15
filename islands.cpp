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

int count_islands(vi &v, int len) {
	int cnt = 0;
	for (int i = 1; i < 12 - len; i++) {
		bool flag = true;
		for (int j = i; j < i+len; j++) {
			if (v[j] <= v[i-1] || v[j] <= v[i+len]) {
				flag = false;
				break;
			}
		}
		if (flag) cnt++;
	}
	return cnt;
}

int solve(vi &v) {
	int ans = 0;
	for (int i = 1; i < 12; i++) {
		ans += count_islands(v, i);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int p, k;
	cin >> p;
	while (p--) {
		cin >> k;
		vi v(12);
		for (auto &d: v) cin >> d;
		cout << k << " " << solve(v) << '\n';
	} 

	return 0;
}
