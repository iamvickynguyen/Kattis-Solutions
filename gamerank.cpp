#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int stars = 0, consecutive_stars = 0, rank = 25;

	for (char &c: s) {
		if (c == 'W') {
			stars += 1 + (consecutive_stars >= 2 && rank >= 6);
			++consecutive_stars;

			if (rank >= 21 && stars > 2) {
				--rank;
				stars -= 2;
			} else if (rank >= 16 && stars > 3) {
				--rank;
				stars -= 3;
			} else if (rank >= 11 && stars > 4) {
				--rank;
				stars -= 4;
			} else if (stars > 5) {
				--rank;
				stars -= 5;
			}

			if (rank < 1)
				break;
		}	else {
			consecutive_stars = 0;
			if (rank <= 20) {
				--stars;
				if (stars < 0) {
					if (rank == 20) stars = 0;
					else {
						++rank;
						if (rank >= 21) stars = 1;
						else if (rank >= 16) stars = 2;
						else if (rank >= 11) stars = 3;
						else stars = 4;
					}
				}
			}
		}
	}
	
	if (rank < 1) {
		cout << "Legend";
	} else cout << rank;

	return 0;
}
