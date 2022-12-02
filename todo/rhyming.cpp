#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Trie {
	public:
	Trie *children[26];
	bool is_end;
	
	Trie(): is_end(false) {
		for (int i = 0; i < 26; ++i) {
			children[i] = nullptr;
		}
	}

	// backward
	void insert(const string &s) {
		Trie *cur = this;
		for (int i = s.length() - 1; i >= 0; --i) {
			if (cur->children[s[i] - 'a'] == nullptr) {
				cur->children[s[i] - 'a'] = new Trie();
			}
			cur = cur->children[s[i] - 'a'];
		}
		cur->is_end = true;
	}

	bool exist(const string &s) {
		Trie *cur = this;
		for (int i = s.length() - 1; i >= 0; --i) {
			if (s[i] == ' ') return true;
			if (cur->is_end) return true;
			if (cur->children[s[i] - 'a'] == nullptr) return false;
			cur = cur->children[s[i] - 'a'];
		}
		return cur->is_end;
	}
};

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

	Trie *trie = new Trie();

	// insert rhyming words to the trie
	for (int i = 0; i < n; ++i) {
		getline(cin, line);
		bool flag = false;
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
			trie->insert(token);
		}
	}

	// output
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; ++i) {
		getline(cin, line);
		if (trie->exist(line)) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;	
}
