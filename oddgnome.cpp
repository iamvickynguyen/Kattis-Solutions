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

	int n, g, x;
	cin >> n;
	while (n--) {
		cin >> g;
		int prev, found = -1;
		cin >> prev;
		for (int i = 1; i < g; i++) {
			cin >> x;
			if (found == -1 && x != (prev + 1)) found = i;
			prev = x;
		}

		cout << found + 1 << '\n';
	}

	return 0;
}
