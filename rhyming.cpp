#include <iostream>
#include <string>
#include <sstream>
#include <unordered_set>
using namespace std;

bool contain(const string &text, const string &pattern) {
	if (pattern.length() > text.length())
		return false;

	for (int i = 0; i < pattern.length(); ++i) {
		if (pattern[pattern.length() - i - 1] != text[text.length() - i - 1])
			return false;

	}

	return true;
}

int main() {
	string s, line, token;
	cin >> s;

	int n;
	cin >> n;
	cin.ignore();

	// add words rhyme with the given word to set
	unordered_set<string> rhymes;
	bool flag;
	for (int i = 0; i < n; ++i) {
		getline(cin, line);
		flag = false;
		stringstream ss(line);
		while (getline(ss, token, ' ')) {
			if (contain(s, token)) {
				flag = true;
				break;
			}
		}

		if (!flag) continue;

		ss.clear();
		ss.str(line);
		while (getline(ss, token, ' ')) {
			rhymes.insert(token);
		}
	}

	// output
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; ++i) {
		getline(cin, line);
		string last;
		stringstream ss(line);
		while (getline(ss, token, ' ')) last = token;
		
		flag = false;
		for (int i = 0; i < last.length(); ++i) {
			if (rhymes.find(last.substr(i, last.length() - i)) != rhymes.end()) {
				flag = true;
				cout << "YES\n";
				break;
			}
		}
		
		if (!flag) cout << "NO\n";
	}

	return 0;	
}
