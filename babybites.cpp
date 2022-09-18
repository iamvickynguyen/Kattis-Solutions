#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	string count;
	bool ok = true;
	for (int i = 1; i <= n; ++i) {
		cin >> count;

		if (ok) {
			if (count == "mumble")
				continue;

			int x = stoi(count);
			if (x != i) {
				ok = false;
				cout << "something is fishy";
			}	
		}
	}

	if (ok) cout << "makes sense";
}
