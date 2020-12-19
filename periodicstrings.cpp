#include <iostream>
#include <string>
using namespace std;

bool checkperiodic(string s, int k) {
	if (s.length() % k != 0)
		return false;

	if (k == 1) {
		char c = s[0];
		for (int i = 1; i < s.length(); i++) {
			if (s[i] != c)
				return false;
		}
		return true;
	}

	int start = 0;
	int mid = k - 1;
	while (mid + k < s.length()) {
		if (s[mid] != s[mid + 1] || s.substr(start, k - 1) != s.substr(mid + 2, k - 1))
			return false;
		start += k;
		mid += k;
	}

	return true;
}

int main() {
	string s;
	cin >> s;
	for (int i = 1; i <= s.length(); i++) {
		if (checkperiodic(s, i)) {
			cout << i;
			break;
		}
	}
	return 0;
}