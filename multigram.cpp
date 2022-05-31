#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

vector<int> factor(int n) {
	vector<int> ans;
	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			ans.push_back(i);
			if (i * i != n && i != 1) ans.push_back(n/i);
		}
	}
	sort(ans.begin(), ans.end());
	return ans;
}

bool solve(int d, string& s) {
	string result = s.substr(0, d);
	sort(result.begin(), result.end());
	for (int i = d; i < s.length(); i += d) {
		string tmp = s.substr(i, d);
		sort(tmp.begin(), tmp.end());
		if (tmp != result) return false;
	}
	return true;
}

int main() {
	string s;
	cin >> s;
	if (s.length() < 2) cout << -1;
	else {
		vector<int> divisors = factor(s.length());

		bool ok = false;
		for (auto &d: divisors) {
			if (solve(d, s)) {
				cout << s.substr(0, d);
				ok = true;
				break;
			}
		}

		if (!ok) cout << -1;
	}
	return 0;
}
