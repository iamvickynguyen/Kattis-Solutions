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
using namespace std;
typedef long long int ll;
//const int MAX = 2e5 + 5;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int v;
	cin >> v;
	int bound = floor(sqrt(v));
	int result = 1e9;
	for (int l = 1; l <= bound; l++) {
		for (int w = 1; w <= bound; w++) {
			int prod = l * w;
			if (v % prod == 0) {
				int h = v / prod;
				int total = 2 * (l * w + w * h + l * h);
				result = min(result, total);
			}
		}
	}

	cout << result;
	return 0;
}