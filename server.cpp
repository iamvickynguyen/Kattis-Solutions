#include <iostream>
using namespace std;

int main() {
	int n, T, count = 0, t;
	bool not_done = true;
	cin >> n >> T;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (not_done && T - t >= 0) {
			T -= t;
			count++;
		}		
		else
			not_done = false;
	}
	cout << count << endl;
	return 0;
}