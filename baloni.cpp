#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	constexpr int MAXN = 1000001;
	int arrows[MAXN];
	for (int i = 0; i < MAXN; ++i) arrows[i] = 0;
	
	int ans = 0, h;
	for (int i =0; i < n; ++i) {
		cin >> h;
		if (arrows[h] == 0) ++ans;
		else --arrows[h];
		++arrows[h-1];
	}
	cout << ans;
	return 0;
}
