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

const int MAXN = 4713;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// build table https://oeis.org/A123578
	vi table(2);
	table[0] = 0;
	table[1] = 0;
	int k = 1;
	while (table.size() < MAXN) {
		for (int i = 0; i < k; i++) table.pb(k);
		k++;
	}

	int n;
	cin >> n;
	while (n) {
		cout << table[n] << '\n';
		cin >> n;
	}

	return 0;
}
