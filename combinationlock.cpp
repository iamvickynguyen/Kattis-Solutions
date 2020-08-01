#include <iostream>
using namespace std;

int main() {
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	while (n || a || b || c) {
		int count = (120 + (n - a + 40) % 40 + (b - a + 40) % 40 + (b - c + 40) % 40) * 9;
		cout << count << endl;
		cin >> n >> a >> b >> c;
	}
	return 0;
}