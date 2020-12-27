#include <iostream>
using namespace std;

int fib(int k) {
	if (k <= 2)
		return 1;
	int a = 1, b = 1, c = 0;
	for (int i = 3; i <=k; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}

int main() {
	int k;
	cin >> k;
	if (k == 1)
		cout << "0 1";
	else if (k == 2)
		cout << "1 1";
	else if (k == 3)
		cout << "1 2";
	else {
		int ab = fib(k - 1);
		int b = fib(k - 2);
		cout << ab << " " << ab + b;
	}
	return 0;
}