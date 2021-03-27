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
	
	string a, b;
	cin >> a >> b;
	int l = 0, ra = a.length() - 1, rb = b.length() - 1;
	while (l <= ra && l <= rb && a[l] == b[l]) {
		l++;
	}

	while (ra >= 0 && rb >= 0 && ra >= l && rb >= l && a[ra] == b[rb]) {
		ra--;
		rb--;
	}

	if (l == rb && a[l] == b[l])
		cout << 0;
	else {
		cout << (rb - l + 1);
	}
	
	return 0;
}