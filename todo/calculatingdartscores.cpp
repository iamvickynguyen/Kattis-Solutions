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

	for (int i = 1; i <= 3; ++i) {
		for (int j = 1; j <= 20; ++j) {
			if ((sum + i * j) > target)
				return false;

			const auto tmp = points[count - 1];
			points[count - 1] = {j, i};
			if (solve(count + 1, sum + i * j, points, target))
				return true;
			points[count - 1] = tmp;
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
//		for (auto& [point, mult]: points)
//			cout << words[mult - 1] << " " << point << '\n';
	} else
		cout << "impossible";
	return 0;
}
