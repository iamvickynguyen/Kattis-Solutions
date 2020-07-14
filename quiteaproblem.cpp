#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string line;
	while (getline(cin, line)) {
		transform(line.begin(), line.end(), line.begin(), ::tolower);
		cout << (line.find("problem") != string::npos ? "yes\n" : "no\n");
	}
}