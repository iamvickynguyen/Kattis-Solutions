#include <iostream>

int main() {
	int a, b, c, n;
	std::cin >> a >> b >> c >> n;
	if (a == 0 || b == 0 || c == 0 || (a + b + c) < n || n < 3)
		std::cout << "NO";
	else std::cout << "YES";
	return 0;
}
