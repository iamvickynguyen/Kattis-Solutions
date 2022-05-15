#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int left = n, right = n;
	while ((left % 100) != 99 && (right % 100) != 99) {
		if (left > 1) left--;
		right++;
	}

	if ((left % 100) == 99 && (right % 100) == 99) cout << right;
	else if ((left % 100) == 99) cout << left;
	else cout << right;

	return 0;
}
