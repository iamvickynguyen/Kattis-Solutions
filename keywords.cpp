#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main() {
	int n;
	string s;
	unordered_set<string> u;
	cin >> n;
	getline(cin, s);
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == ' ') {
				s[j] = '-';
			}
		}
		if (u.find(s) == u.end())
			u.insert(s);
	}
	cout << u.size() << '\n';
	return 0;
}
