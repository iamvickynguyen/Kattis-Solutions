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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int k, r;
	cin >> k >> r;
	vi ingredients(k);
	for (auto &i: ingredients) cin >> i;
	int ans = 0;
	
	int a, price;
	for (int i = 0; i < r; i++) {
		int cnt = 1000000;
		for (int j = 0; j < k; j++) {
			cin >> a;
			if (a != 0) cnt = min(cnt, ingredients[j]/a);
		}

		cin >> price;
		ans = max(ans, cnt*price);
	}
	cout << ans;
	return 0;
}