#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
 * The idea is to duplicate the string, then match the original string with the duplicated one
 * The index when the string is matched for the second time (the first match happens at the beginning of the duplicated string)
 * is the length of the desired pattern
 * Divide the original string length by that index is the answer
 */

vector<int> kmp_table(const string &s) {
	vector<int> table(s.length());
	table[0] = 0;
	
	int i = 0, j = 1;
	while (j < s.length()) {
		if (s[i] == s[j]) {
			table[j] = i + 1;
			++i;
			++j;
		} else {
			if (i > 0) i = table[i - 1];
			else {
				table[j] = 0;
				++j;
			}
		}
	}

	return table;
}

int kmp(const string &s) {
	vector<int> table = kmp_table(s);
	
	int j = 0;
	for (int i = 1; i < s.length() * 2; ++i) {
		while (j > 0 && s[i % s.length()] != s[j]) j = table[j - 1];
		if (s[i % s.length()] == s[j]) ++j;
		if (j == s.length()) return (i - s.length() + 1);
	}

	return s.length();
}

int main() {
	string s;
	cin >> s;
	while (s != ".") {
		cout << (s.length() / kmp(s)) << '\n';
		cin >> s;
	}

	return 0;
}
