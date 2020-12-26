#include <iostream>
#include <string>
#include <set>
#include <unordered_map>
using namespace std;

bool check_palindrome(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != s[s.length() - 1 - i])
			return false;
	}
	return true;
}

int main() {
	string s;
	while (cin >> s) {
		set<string> palindromes;
		for (int i = 0; i < s.length(); i++) {
			for (int j = 2; i + j <= s.length(); j++) {
				string subs = s.substr(i, j);
				if (check_palindrome(subs))
					palindromes.insert(subs);
			}
		}
		
		for (auto p : palindromes)
			cout << p << endl;
		cout << endl;
	}
	return 0;
}