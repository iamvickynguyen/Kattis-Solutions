#include <iostream>
using namespace std;

int main() {
	int a, b, c, d, index1, index2;
	cin >> a >> b >> c >> d;
	int sort[] = { 21, 66, 55, 44, 33, 22, 11 };
	while (a != 0 || b != 0 || c != 0 || d != 0) {
		int index1 = -1, index2 = -1;
		int p1 = a > b ? a * 10 + b : b * 10 + a;
		int p2 = c > d ? c * 10 + d : d * 10 + c;
		for (int i = 0; i < 7; i++) {
			if (p1 == sort[i]) {
				index1 = i;
				break;
			}
		}
		for (int i = 0; i < 7; i++) {
			if (p2 == sort[i]) {
				index2 = i;
				break;
			}
		}
		if (index1 != -1) {
			if (index2 != -1)
				cout << (index1 < index2 ? "Player 1 wins.\n" : (index1 == index2 ? "Tie.\n" : "Player 2 wins.\n"));
			else
				cout << "Player 1 wins.\n";
		}
		else if (index2 != -1) {
			if (index1 != -1)
				cout << (index1 < index2 ? "Player 1 wins.\n" : (index1 == index2 ? "Tie.\n" : "Player 2 wins.\n"));
			else
				cout << "Player 2 wins.\n";
		}
		else {
			cout << (p1 > p2 ? "Player 1 wins.\n" : (p1 == p2 ? "Tie.\n" : "Player 2 wins.\n"));
		}
		cin >> a >> b >> c >> d;
	}
	return 0;
}