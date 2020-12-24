#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool check_palindrome(string s, unordered_map<char, int> um) {
	bool odd = false;
	for (auto item : um) {
		if (item.second % 2 != 0) {
			if (s.length() % 2 == 0 || odd)
				return false;
			odd = true;
		}		
	}
	return true;
}

void swap(string &s, int a, int b) {
	char tmp = s[a];
	s[a] = s[b];
	s[b] = tmp;
}

int count_swaps(string s, unordered_map<char, int> um) {
	int count = 0;
	while (s.length() > 1) {
		if (um[s[0]] > 1) {
			for (int i = s.length() - 1; i >= 0; i--) {
				if (s[i] == s[0]) {
					count += s.length() - i - 1;
					um[s[0]] -= 2;
					s.erase(i, 1);
					s = s.substr(1, s.length());
					break;
				}
			}
		}
		else {
			swap(s, 0, 1);
			count++;
		}
	}

	return count;
}

int main() {
	int n;
	cin >> n;
	string s;
	while (n--) {
		cin >> s;
		unordered_map<char, int> um;
		for (char c : s)
			um[c]++;

		if (check_palindrome(s, um)) {
			int count = count_swaps(s, um);
			cout << count;
		}
		else
			cout << "impossible";
		if (n != 0)
			cout << endl;
	}

	return 0;
}