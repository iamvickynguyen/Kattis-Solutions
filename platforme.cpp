#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct platform {
	int h;
	int l;
	int r;
};

int main() {
	int n;
	cin >> n;
	vector<platform> platforms;
	vector<int> ground(10001, 0);
	for (int i = 0; i < n; i++) {
		platform p;
		cin >> p.h >> p.l >> p.r;
		p.r--;
		platforms.push_back(p);
	}

	sort(platforms.begin(), platforms.end(), [](const platform &a, const platform &b) { return a.h < b.h; });
	int total = 0;
	for (auto p : platforms) {
		total += p.h - ground[p.l];
		total += p.h - ground[p.r];

		for (int i = p.l; i <= p.r; i++) {
			ground[i] = p.h;
		}
	}

	cout << total;
	return 0;
}