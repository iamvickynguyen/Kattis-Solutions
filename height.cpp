#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, h;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		vector<int> heights;
		for (int j = 0; j < 21; j++) {
			cin >> h;
			heights.push_back(h);
		}

		// insertion sort
		int count = 0;
		for (int k = 2; k < 21; k++) {
			int cur = k;
			int val = heights[k];

			while (cur > 1 && val < heights[cur - 1]) {
				count++;
				heights[cur] = heights[cur - 1];
				cur--;
			}

			heights[cur] = val;
		}

		cout << i << " " << count << endl;
	}

	return 0;
}