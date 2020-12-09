#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, h, x;
	cin >> n >> h;
	vector<int> bottom(h, 0);
	vector<int> top(h, 0);
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (i % 2 == 0)
			bottom[x - 1]++;
		else
			top[h - x]++;
	}

	int count = 0;
	for (int i = h - 1; i >= 0; i--) {
		count += bottom[i];
		bottom[i] = count;
	}

	count = 0;
	for (int i = 0; i < h; i++) {
		count += top[i];
		top[i] = count;
	}

	int obstacles = 1000000000;
	int levels = 0;
	for (int i = 0; i < h; i++) {
		if (obstacles > bottom[i] + top[i]) {
			obstacles = bottom[i] + top[i];
			levels = 1;
		} else if (obstacles == bottom[i] + top[i])
			levels++;
	}

	cout << obstacles << " " << levels;
}