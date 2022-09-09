#include <iostream>
using namespace std;

int main() {
	unsigned int c, n;
	cin >> c >> n;

	unsigned int x, counter = 0u;
	bool flag = true, waitlast;
	for (int i = 0; i < n; ++i) {
		cin >> x;
	  flag = flag && (counter >= x);
		if (flag) counter -= x;

		cin >> x;
		flag = flag && (counter + x) <= c;
		if (flag) counter += x;

		cin >> x;
		flag = flag && !(counter < c && x > 0);
		waitlast = x > 0;
	}

	if (flag && counter == 0 && !waitlast) cout << "possible";
	else cout << "impossible";
	return 0;
}
