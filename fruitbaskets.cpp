#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int n, x;
	long long int ans = 0;
	cin >> n;
	vector<int> fruits;
	for (int i = 0; i < n; i++) {
		cin >> x;
		fruits.push_back(x);
		ans += x * pow(2, n - 1);
	}

	for (int i = 0; i < n; i++) {
		ans -= fruits[i] < 200 ? fruits[i] : 0;
		for (int j = i + 1; j < n; j++) {
			ans -= fruits[i] + fruits[j] < 200 ? fruits[i] + fruits[j] : 0;
			for (int k = j + 1; k < n; k++) {
				ans -= fruits[i] + fruits[j] + fruits[k] < 200 ? fruits[i] + fruits[j] + fruits[k] : 0;
			}
		}
	}

	cout << ans;
	return 0;
}