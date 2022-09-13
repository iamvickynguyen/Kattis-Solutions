#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

bool solve(int count, int sum, vector<pair<int, int>>& points, const int target) {
	if (count >= 3)
		return sum == target;

	if (sum > target)
		return false;

	for (int i = 0; i <= 3; ++i) {
		for (int j = 1; j <= 20; ++j) {
			if ((sum + i * j) > target)
				break;

			pair<int, int> tmp = points[count];
			points[count] = make_pair(j, i);
			bool flag = solve(count + 1, sum + i * j, points, target);
			if (flag)
				return true;
			points[count] = tmp;
		}
	}

	return false;
}

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> points(3, {1, 1});
	if (solve(0, 0, points, n)) {
		string words[] = {"single", "double", "triple"};
		for (auto& [point, mult]: points) {
			if (mult != 0)
				cout << words[mult - 1] << " " << point << '\n';
		}
	} else
		cout << "impossible";
	return 0;
}
