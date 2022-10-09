#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, x;
	cin >> n;
	int orders[20];
	while (n != 0) {
		for (int i = 0; i < n; ++i) {
			cin >> x;
			--x;
			orders[i] = x;
		}

		string s;
		cin.ignore();
		getline(cin, s);
		
		for (int i = 0; i < (s.length() % n); ++i) {
			s.push_back(' ');
		}

		cout << "'";
		for (int i = 0; i < s.length() / n; ++i) {
			for (int j = 0; j < n; ++j) {
				const int p = orders[j] + i * n;
				cout << s[p];
			}
		}

		cout << "'\n";
		cin >> n;
	}
}
