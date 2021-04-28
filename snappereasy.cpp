#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <utility>
#include <string>
#include <regex>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <numeric>
#include <math.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t, n, k;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> k;
		ll d = 1LL << n;
		if (k - (d - 2) - 1 == 0 || (k - (d - 2) - 1) % d == 0) {
			cout << "Case #" << i << ": ON\n";
		}
		else {
			cout << "Case #" << i << ": OFF\n";
		}
	}

	return 0;
}