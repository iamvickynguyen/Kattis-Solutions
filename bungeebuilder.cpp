#include <iostream>
#include <vector>
#include <stack>
#include <utility>
using namespace std;

int process(const int i, stack<pair<int, int>>& st, vector<int>& heights) {
	int diff = 0;
	while (!st.empty() && heights[i] > st.top().first) {
		diff = max(diff, heights[i] - st.top().first + st.top().second);
		st.pop();
	}

	st.push({heights[i], diff});
	return diff;
}

int main() {
	int n, h, maxheight_index = 0;
	cin >> n;
	vector<int> heights;
	heights.reserve(n);
	for (int i = 0; i < n; ++i) {
		cin >> h;
		heights.push_back(h);
		if (heights[i] > heights[maxheight_index])
			maxheight_index = i;
	}

	int ans = 0;
	stack<pair<int, int>> st;
	st.push({heights[maxheight_index], 0});
	for (int i = maxheight_index - 1; i >= 0; --i) {
		ans = max(ans, process(i, st, heights));
	}

	while (!st.empty()) st.pop();
	st.push({heights[maxheight_index], 0});
	for (int i = maxheight_index + 1; i < n; ++i) {
		ans = max(ans, process(i, st, heights));
	}

	cout << ans;
	return 0;
}
