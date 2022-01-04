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

	int t, n;
	cin >> t;
	string p, v;
	while (t--) {
		cin >> p >> n >> v;
		deque<int> d;
		int k = 0;
		for (int i = 1; i < v.size() - 1; i++) {
			if (v[i] != ',') {
				k = k * 10 + v[i] - '0';
			} else {
				d.pb(k);
				k = 0;
			}
		}

		if (n > 0) d.pb(k);

		bool flag = true, ok = true;
		for (char &c : p) {
			if (c == 'R') flag = !flag;
			else {
				if (d.size() == 0) {
					cout << "error\n";
					ok = false;
					break;
				} else {
					if (flag) d.pop_front();
					else d.pop_back();
				}
			}
		}

		if (ok) {
			bool first = true;
			cout << "[";
			if (flag) {
				for (int &num : d) {
					if (!first) cout << ",";
					first = false;
					cout << num;
				}
			} else {
				for (int i = d.size() - 1; i >= 0; i--) {
					if (!first) cout << ",";
					first = false;
					cout << d[i];
				}
			}

			cout << "]\n";
		}
	}

	return 0;
}
