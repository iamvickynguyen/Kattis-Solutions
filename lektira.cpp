#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string reverse(int start, int end, string s) {
	string reversed = "";
	for (int i = end; i >= start; i--) {
		reversed += s[i];
	}
	return reversed;
}

int main() {
	string s;
	cin >> s;
	vector<string> v;
	for (int i = 0; i < s.length(); i++) {
		for (int j = 2; j < s.length() - 1; j++) {
			if (i < j) {
				string concat = reverse(0, i, s) + reverse(i + 1, j, s) + reverse(j + 1, s.length() - 1, s);
				v.push_back(concat);
			}
		}
	}

	sort(v.begin(), v.end());
	cout << v[0];

	return 0;
}