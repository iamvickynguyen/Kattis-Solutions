#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	unordered_map<string, int> words;
	for (int i = 0; i < n; i++) {
		cin >> s;
		string w = "";
		for (int j = 0; j < s.size(); j++) {
			w += s[j];
			if (words.find(w) != words.end()) {
				words[w] += 1;
			}
			else {
				words[w] = 1;
			}
		}
		cout << words[w] - 1 << '\n';
	}
	return 0;
}