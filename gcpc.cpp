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

vector<pii> team;

bool is_higher(int t) {
	int a1 = -team[t].first, b1 = team[t].second;
	int a2 = -team[0].first, b2 = team[0].second;
	return a1 > a2 || (a1 == a2 && b1 < b2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, t, p;
	cin >> n >> m;
	team.assign(n, {0,0});
	multiset<pii> bst;
	while (m--) {
		cin >> t >> p;
		t--;
		if (t == 0) {
			team[t].first--;
			team[t].second += p;
			auto it = bst.lower_bound(team[0]);
			bst.erase(it, bst.end());
		} else {
			if (is_higher(t)) {
				auto it = bst.find(team[t]);
				if ((it == bst.begin() && bst.size() > 0) || it != bst.begin()) bst.erase(it);
				team[t].first--;
				team[t].second += p;
				bst.insert(team[t]);
			} else {
				team[t].first--;
				team[t].second += p;
				if (is_higher(t)) bst.insert(team[t]);
			}
		}

		cout << bst.size() + 1 << '\n';
	}

	return 0;
}
