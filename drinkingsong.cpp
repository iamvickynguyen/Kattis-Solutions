#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	string s;
	cin >> n >> s;
	for (int i = n; i > 0; i--) {
		if (i == 1) {
			cout << "1 bottle of " + s + " on the wall, 1 bottle of " + s + ".\nTake it down, pass it around, no more bottles of " + s + ".";
		}
		else {
			cout << to_string(i) + " bottles of " + s + " on the wall, " + to_string(i) + " bottles of " + s + ".\nTake one down, pass it around, ";
			if (i == 2)
				cout << "1 bottle of " + s + " on the wall.\n";
			else
				cout << to_string(i-1) + " bottles of " + s + " on the wall.\n";
			cout << endl;
		}
	}

	return 0;
}
