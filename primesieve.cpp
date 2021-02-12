#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q, x;
	cin >> n >> q;
	vector<bool> primes(n + 1, true);
	primes[1] = false;
	int count = n - 1;

	// generate primes
	int p = 2;
	while (p * p <= n) {
		if (primes[p]) {
			for (int i = p * p; i <= n; i += p) {
				if (primes[i])
					count--;
				primes[i] = false;
			}
		}
		p += 1;
	}

	cout << count << endl;
	for (int i = 0; i < q; i++) {
		cin >> x;
		if (primes[x])
			cout << "1\n";
		else
			cout << "0\n";
	}

	return 0;
}