#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> get_gaps(vector<int> &c, const int n) {
	vector<int> gaps;
	gaps.reserve(n);
	for (int i = 1; i < n; ++i) {
		gaps.push_back(c[i] - c[i - 1]);
	}

	int last_gaps = 360000 - c[n - 1] + c[0];
	gaps.push_back(last_gaps);
	
	return gaps;	
}

vector<int> build_index_table(const vector<int> &v) {
	vector<int> lookup(v.size());
	lookup[0] = 0;

	int i = 0, j = 1;
	while (j < v.size()) {
		if (v[i] == v[j]) {
			lookup[j] = i + 1;
			++i;
			++j;
		} else {
			if (i > 0) i = lookup[i - 1];
			else {
				lookup[j] = 0;
				++j;
			}
		}
	}
	return lookup;
}

bool kmp(const vector<int> &a, const vector<int> &b, const int n) {
	vector<int> lookup = build_index_table(b);
	
	vector<int> sequence;
	sequence.reserve(n * 2);
	sequence.insert(sequence.begin(), a.begin(), a.end());
	sequence.insert(sequence.end(), a.begin(), a.end());

	int j = 0;
	for (int i = 0; i < 2 * n; ++i) {
		while (j > 0 && sequence[i] != b[j]) j = lookup[j - 1];
		if (sequence[i] == b[j]) ++j;
		if (j == n) {
			return true;
		}
	}

	return false;
}

int main() {
	int n, a;
	cin >> n;

	vector<int> c1, c2;
	c1.reserve(n);
	c2.reserve(n);
	for (int i = 0; i < n; ++i) {
		cin >> a;
		c1.push_back(a);
	}
	sort(c1.begin(), c1.end());

	for (int i = 0; i < n; ++i) {
		cin >> a;
		c2.push_back(a);
	}
	sort(c2.begin(), c2.end());
	
	vector<int> gap1 = get_gaps(c1, n);
	vector<int> gap2 = get_gaps(c2, n);

	if (kmp(gap1, gap2, n)) cout << "possible";
	else cout << "impossible";
	return 0;
}
