#include <iostream>
#include <set>
#include <string>
using namespace std;

void add_palindrome_substrings(string s, int l, int r, set<string> &substrings) {
	while (l >= 0 && r < s.length() && s[l] == s[r]) {
		substrings.insert(s.substr(l, r - l + 1));
		l--;
		r++;
	}
}

int main() {
	string s;
	while (cin >> s) {
		set<string> substrings;
		for (int i = 0; i < s.length(); i++) {
			if (i + 1 < s.length())
				add_palindrome_substrings(s, i, i + 1, substrings);
			if (i + 2 < s.length())
				add_palindrome_substrings(s, i, i + 2, substrings);
		}

		for (string substr : substrings)
			cout << substr << endl;
		cout << endl;
	}

	return 0;
}