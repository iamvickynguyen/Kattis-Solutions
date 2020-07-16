#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, item, k = 2;
	long long discount = 0;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> item;
		v.push_back(item);
	}
	sort(v.begin(), v.end(), greater<int>());
	while (k < n) {
		discount += v[k];
		k += 3;
	}
	cout << discount;
	return 0;
}
