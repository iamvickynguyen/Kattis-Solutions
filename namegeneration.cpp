#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

vector<string> ans;

bool is_vowel(char c) {
	return (c == 'a' || c == 'e' || c == 'i'
			|| c == 'o' || c == 'u');
}

void generate_names(int n, string s) {
	if (ans.size() == n) return;
	if (s.length() > 20) return;

	if (s.length() < 2) {
		for (int i = 0; i < 26; i++) {
			char c = i + 'a';
			generate_names(n, s + c);
		}
	} else {
		if (s.length() >= 3) ans.push_back(s);
		if (s.length() == 20) return;
		if (is_vowel(s[s.length() - 1])) {
			for (int i = 0; i < 26; i++) {
				char c = i + 'a';
				if (is_vowel(s[s.length() - 2])) {
					if (!is_vowel(c))
						generate_names(n, s + c);
				} else {
					generate_names(n, s + c);
				}
			}
		} else {
			for (int i = 0; i < 26; i++) {
				char c = i + 'a';
				if (!is_vowel(s[s.length() - 2])) {
					if (is_vowel(c))
						generate_names(n, s + c);
				} else {
					generate_names(n, s + c);
				}
			} 
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	generate_names(n, "");
	for (auto &s: ans) cout << s << '\n';
	
	return 0;
}
