#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	string status;
	char problem;
	cin >> n;
	int time[26], statuses[26];
	for (int i = 0; i < 26; ++i) {
		time[i] = 0;
		statuses[i] = 0;
	}

	while (n != -1) {
		cin >> problem >> status;
		int p = problem - 'A';
		if (status == "wrong") {
			time[p] += 20;
		} else {
			time[p] += n;
			statuses[p] = 1;
		}

		cin >> n;
	}

	int solve_count = 0, total_time = 0;
	for (int i = 0; i < 26; ++i) {
		if (statuses[i] == 1) {
			++solve_count;
			total_time += time[i];
		}
	}

	cout << solve_count << " " << total_time;

	return 0;
}
