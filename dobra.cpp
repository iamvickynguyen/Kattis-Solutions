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
string s;
vector<int> ways;
ll ans = 0;

bool check() {
	int count = 0;
	bool vowel = true;
	bool l = false;
	char c[] = { 'A', 'E', 'I', 'O', 'U' };
	for (auto i : s) {
		if (i == 'L') {
			l = true;
		}

		bool flag = true;
		for (auto ch : c) {
			if (i == ch) {
				flag = false;
				if (vowel) {
					count++;
				} else {
					count = 1;
					vowel = true;
				}
				break;
			}
		}

		// consonant
		if (flag) {
			if (!vowel) {
				count++;
			} else {
				count = 1;
				vowel = false;
			}
		}

		if (count >= 3)
			return false;
	}

	return l;
}

void update_ans() {
	ll count = 1;
	for (auto t : ways)
		count *= t;
	ans += count;
}

void solve(int i) {
	if (i == s.length()) {
		if (check()) update_ans();
		return;
	}

	if (s[i] != '_')
		solve(i + 1);
	else {

		// try L
		s[i] = 'L';
		solve(i + 1);
		s[i] = '_';

		// try consonant
		s[i] = 'B';
		ways[i] = 20;
		solve(i + 1);
		s[i] = '_';
		ways[i] = 1;

		// try vowel
		s[i] = 'A';
		ways[i] = 5;
		solve(i + 1);
		s[i] = '_';
		ways[i] = 1;
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> s;
	ways.resize(s.length(), 1);
	solve(0);
	cout << ans;
	return 0;
}