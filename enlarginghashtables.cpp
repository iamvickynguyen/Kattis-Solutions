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

bool is_prime(ll n) {
	if (n == 1) return false;
	if (n == 2) return true;
	for (ll i = 2; i < floorl(sqrtl(n)) + 1; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n;
	cin >> n;
	while (n) {
		ll i = 2 * n + 1;
		while (!is_prime(i)) i++;
		cout << i;
		if (!is_prime(n)) cout << " (" << n << " is not prime)";
		cout << '\n';
		cin >> n;
	}

	return 0;
}
