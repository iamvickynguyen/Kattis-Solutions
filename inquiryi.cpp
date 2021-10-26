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
	ll a, total = 0;
	vector<ll> v;
	for (int i = 0; i < n; i++) {
		cin >> a;
		total += a;
		v.pb(a);
	}

	ll square = 0;
	ll ans = total * square;
	for (int i = 0; i < n; i++) {
		total -= v[i];
		square += v[i] * v[i];
		ans = max(ans, total * square);
	}

	cout << ans;

	return 0;
}
