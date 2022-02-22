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

const int maxN = 32000;

vector<bool> get_primes(int n) {
	vector<bool> primes(n + 1, true);
	primes[1] = false;
	int p = 2;
	while (p * p <= n) {
		if (primes[p]) {
			for (int i = p * p; i <= n; i += p) {
				primes[i] = false;
			}
		}
		p += 1;
	}
	return primes;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x;
	cin >> n;
	vector<bool> primes = get_primes(maxN);
	while (n--) {
		cin >> x;
		vector<pii> ans;
		for (int i = 2; i <= x/2; i++) {
			if (primes[i] && primes[x - i]) ans.pb({i, x - i});
		}

		sort(all(ans));
		cout << x << " has " << ans.size() << " representation(s)\n";
		for (auto &item: ans) cout << item.first << "+" << item.second << '\n';
		cout << '\n';
	}

	return 0;
}
