#include <iostream>
#include <vector>
#include <string>
using namespace std;
string bits;

char and_op(char a, char b) {
	if (a == '0' || b == '0')
		return '0';
	if (a == '1' && b == '1')
		return '1';
	return '?';
}

char or_op(char a, char b) {
	if (a == '1' || b == '1')
		return '1';
	if (a == '0' && b == '0')
		return '0';
	if (a == '0')
		return b;
	if (b == '0')
		return a;
	return '?';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, a, b;
	cin >> n;
	string unknown;
	unknown.resize(32, '?');
	while (n) {
		bits = unknown;
		string instruction;
		for (int i = 0; i < n; i++) {
			cin >> instruction >> a;
			a = 31 - a;
			if (instruction == "SET") {
				bits[a] = '1';
			}
			else if (instruction == "CLEAR") {
				bits[a] = '0';
			}
			else if (instruction == "AND") {
				cin >> b;
				b = 31 - b;
				bits[a] = and_op(bits[a], bits[b]);
			}
			else {
				cin >> b;
				b = 31 - b;
				bits[a] = or_op(bits[a], bits[b]);
			}
		}
		
		cout << bits << endl;
		cin >> n;
	}
	return 0;
}