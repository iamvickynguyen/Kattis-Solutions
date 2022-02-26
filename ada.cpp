#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef unordered_set<int> usi;
typedef unordered_map<int, vi> ivi;
typedef unordered_map<int, int> ii;
typedef priority_queue<int> pq;
#define all(x) (x).begin(), (x).end()
#define pb push_back

void output(int cur, int degree, vi &last) {
	for (int i = last.size() - 1; i >= 0; i--) {
		cur += last[i];
	}
	cout << degree << " " << cur;
}

void solve(vi &v) {
	vi tmp, cur = v;
	vi last;
	int degree = 1;
	while (true) {
		tmp.clear();
		for (int i = 0; i < cur.size() - 1; i++) tmp.pb(cur[i + 1] - cur[i]);
		if (tmp.size() == 0) {
			output(v[v.size() - 1], degree, last);
			return;
		}
		bool flag = true;
		int val = tmp[0];
		for (auto &diff: tmp) {
			if (diff != val) {
				flag = false;
				break;
			}
		}

		last.pb(tmp[tmp.size() - 1]);
		if (flag) {
			output(v[v.size() - 1], degree, last);
			return;
		}
		cur = tmp;
		degree++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vi v(n);
	for (auto &d: v) cin >> d;
	solve(v);
	return 0;
}
