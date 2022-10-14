#include <iostream>
#include <string>
using namespace std;

int main() {
	int h;
	string path;
	cin >> h >> path;
	int root = (1 << (h + 1)) - 1;
	int offset = 0;
	for (auto &c: path) {
		offset *= 2;
		if (c == 'L') ++offset;
		else offset += 2;
	}

	cout << (root - offset);
	return 0;
}
