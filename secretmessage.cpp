#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int get_closest_square_factor(const int L) {
	int K = ceil(sqrt(L));
	return K;
}

int main() {
	int n;
	cin >> n;
	string s;
	while (n--) {
		cin >> s;
		int K = get_closest_square_factor(s.length());

		for (int j = 0; j < K; ++j) {
			for (int i = K - 1; i >=0; --i) {
				int p = i * K + j;
				if (p < s.length())
					cout << s[p];
			}
		}
		cout << '\n';
	}

	return 0;
}
