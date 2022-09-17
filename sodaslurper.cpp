#include <iostream>
using namespace std;

int main() {
	int e, f, c;
	cin >> e >> f >> c;
	
	int ans = 0;
	int count = e + f;
	while (count >= c) {
		int bottles = count / c;
		ans += bottles;
		count = (count % c) + bottles;
	}
	cout << ans;
	return 0;
}
