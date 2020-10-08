#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, s, r, d;
	scanf("%d %d %d", &n, &s, &r);
	vector<int> teams(n, 0);
	for (int i = 0; i < s; i++) {
		scanf("%d", &d);
		teams[d - 1] = -1;
	}

	vector<int> reserves;
	for (int i = 0; i < r; i++) {
		scanf("%d", &d);
		if (teams[d - 1] == -1)
			teams[d - 1] = 1;
		else
			reserves.push_back(d-1);
	}
	sort(reserves.begin(), reserves.end());

	for (auto x : reserves) {
		if (x == 0) {
			if (teams[x + 1] == -1)
				teams[x + 1] = 1;
		}
		else if (teams[x - 1] == -1)
			teams[x - 1] = 1;
		else if (x + 1 < n && teams[x + 1] == -1)
			teams[x + 1] = 1;
	}
	int counter = count(teams.begin(), teams.end(), -1);
	printf("%d", counter);
	return 0;
}