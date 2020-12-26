#include <iostream>
#include <string>
using namespace std;

bool check_palindrome(string s) {
	for (int i = 0; i <= s.length() / 2; i++) {
		if (s[i] != s[s.length() - i - 1])
			return false;
	}
	return true;
}

string tobase(int b, int n) {
	string s = "";
	while (n)
	{
		s += to_string(n % b);
		n /= b;
	}
	return s;
}

int main() {
	int a, b, k;
	cin >> a >> b >> k;
	int count = 0;
	for (int i = a; i <= b; i++) {
		int b = 2;
		for (; b <= k; b++) {
			if (!check_palindrome(tobase(b, i))) {
				break;
			}
		}

		if (b == k + 1)
			count++;
	}
	cout << count;
	return 0;
}