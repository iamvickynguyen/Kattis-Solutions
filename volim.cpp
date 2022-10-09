#include <iostream>
using namespace std;

int main() {
	const int maxtime = 210;
	int k, n, t, curtime = 0, ans = -1;
	cin >> k >> n;
	char z;
	for (int i = 0; i < n; ++i) {
		cin >> t >> z;
		curtime += t;
		if (ans == -1 && curtime >= maxtime) {
			ans = k;
		} else {
			if (z == 'T') k = (k + 1) % 8;
		}
	}
	
	if (ans == 0) cout << 8;
	else cout << ans;
	return 0;
}
