#include <iostream>
#include <cmath>
using namespace std;

const int MAXN = 10002;
const int D = pow(10, 9) + 7;

int main() {
	int dp[MAXN];
	dp[0] = 1;
	dp[1] = 2;

	for (int i = 2; i < MAXN; i++)
		dp[i] = (dp[i - 2] + dp[i - 1]) % D;

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << dp[n] << endl;
	}
	return 0;
}