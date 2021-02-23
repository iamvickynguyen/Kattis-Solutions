#include <iostream>
#include <vector>
using namespace std;

int solve(int n, int k) {
	vector<bool> primes(n + 1, true);
	int p = 2;
	while (p * p <= n) {
		for (int i = p; i <= n; i += p) {
			if (primes[i]) {
				k--;
				if (k == 0) return i;
				primes[i] = false;
			}
		}
		p += 1;
	}

	for (int i = p; i <= n; i++) {
		if (primes[i]) {
			k--;
			if (k == 0) return i;
		}
	}

	return 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	cout << solve(n, k);
	return 0;
}