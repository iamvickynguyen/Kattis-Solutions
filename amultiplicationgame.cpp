#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long int n;
	while (cin >> n) {
		bool ollie = true;
		while (n > 1) {
			if (ollie)
				n = (n % 9 == 0) ? n / 9 : (n / 9) + 1;
			else
				n = (n % 2 == 0) ? n / 2 : n / 2 + 1;
			ollie = !ollie;
		}
		cout << (ollie ? "Ollie wins." : "Stan wins.") << endl;
	}
	return 0;
}