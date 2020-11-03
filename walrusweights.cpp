#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int n, x;
	scanf("%d", &n);
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		arr.push_back(x);
	}

	vector<bool> dp(2001);
	dp[0] = true;

	for (int i = 0; i < n; i++) {
		int end = 2001 - arr[i];

		for (int j = end; j >= 0; j--) {
			if (dp[j]) {
				dp[j + arr[i]] = true;
			}
		}
	}

	for (int i = 0; i < 1000; i++) {
		if (dp[1000 + i]) {
			printf("%d\n", 1000 + i);
			break;
		}
		else if (dp[1000 - i]) {
			printf("%d\n", 1000 - i);
			break;
		}
	}

	return 0;
}