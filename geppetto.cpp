#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
	int n, m, a, b;
	cin >> n >> m;
	unordered_set<int> masks;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		a--; b--;
		masks.insert((1 << a) | (1 << b));
	}

	int count = 0;
	for (int i = 0; i < (1 << n); i++) {
		bool ok = true;
		for (auto m : masks) {
			if ((i & m) == m) {
				ok = false;
				break;
			}
		}

		if (ok)
			count++;
	}

	cout << count;
}