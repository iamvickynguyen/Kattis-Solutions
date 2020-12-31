#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
	int w, p, pre = 0, cur;
	cin >> w >> p;
	vector<int> v;
	unordered_set<int> widths;
	for (int i = 0; i < p; i++) {
		cin >> cur;
		v.push_back(cur - pre);
		widths.insert(cur - pre);
		pre = cur;
	}
	v.push_back(w - pre);
	widths.insert(w - pre);
	
	for (int i = 0; i < p + 1; i++) {
		int sum = v[i];
		for (int j = i + 1; j < p + 1; j++) {
			sum += v[j];
			widths.insert(sum);
		}
	}

	vector<int> result;
	for (auto w : widths)
		result.push_back(w);
	sort(result.begin(), result.end());
	for (auto w : result)
		cout << w << " ";

	return 0;
}