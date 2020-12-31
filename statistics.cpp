#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, x, c = 1;
	while (cin >> n) {
		int gmin = 1000005;
		int gmax = -1000005;
		for (int i = 0; i < n; i++) {
			cin >> x;
			gmin = min(x, gmin);
			gmax = max(x, gmax);
		}
		cout << "Case " << c << ": " << gmin << " " << gmax << " " << gmax - gmin << endl;
		c++;
	}
	return 0;
}