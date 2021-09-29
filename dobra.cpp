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

string s;
vector<int> ways(101, 1);
ll ans = 0;

bool isvalid() {
	bool hasL = false, isvowel = true;
	int cnt = 0;
	for (char &c: s) {
		if (c == 'L') hasL = true;

		if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
			if (isvowel) cnt++;
			else {
				isvowel = true;
				cnt = 1;
			}
		} else {
			if (isvowel) {
				isvowel = false;
				cnt = 1;
			} else cnt++;
		}

		if (cnt >= 3) return false;
	}

	return hasL;
}

void solve(int i) {
	if (i == s.length()) {
		if (isvalid()) {
			ll count = 1;
			for (int j = 0; j < s.size(); j++) count *= ways[j];
			ans += count;
		}

		return;
	}

	if (s[i] != '_') solve(i + 1);
	else {
		// try L
		s[i] = 'L';
		solve(i + 1);

		// try consonant
		s[i] = 'B';
		ways[i] = 20;
		solve(i + 1);

		// try vowel
		s[i] = 'A';
		ways[i] = 5;
		solve(i + 1);

		s[i] = '_';
		ways[i] = 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> s;
	solve(0);
	cout << ans;
	return 0;
}