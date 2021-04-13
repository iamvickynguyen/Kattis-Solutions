#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <utility>
#include <string>
#include <regex>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <numeric>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
// const int MOD = 1e9 + 7;

int extended_euclidean(ll a, ll b, ll& x, ll& y) {
	x = 1, y = 0;
	ll x1 = 0, y1 = 1, a1 = a, b1 = b;
	while (b1) {
		ll q = a1 / b1;
		tie(x, x1) = make_tuple(x1, x - q * x1);
		tie(y, y1) = make_tuple(y1, y - q * y1);
		tie(a1, b1) = make_tuple(b1, a1 - q * b1);
	}
	return a1;
}

ll mod_div(ll num, ll den, ll n) {
	if (den == 0) return -1;
	num = num % n;
	ll x, y;
	ll g = extended_euclidean(den, n, x, y);
	if (g != 1)
		return -1;
	return (((x % n + n) % n) * num) % n;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, num, den;
	int t;
	char op;
	cin >> n >> t;
	while (n != 0 || t != 0) {
		for (int i = 0; i < t; i++) {
			cin >> num >> op >> den;
			if (op == '*') { cout << (((((num % n) * (den % n)) % n) + n) % n) << endl; }
			else if (op == '+') { cout << (((((num % n) + (den % n)) % n) + n) % n) << endl; }
			else if (op == '-') { cout << (((((num % n) - (den % n)) % n) + n) % n) << endl; }
			else { cout << mod_div(num, den, n) << endl; }
		}
		cin >> n >> t;
	}

	return 0;
}