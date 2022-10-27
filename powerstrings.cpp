#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;

vector<int> factors;
string s;

vector<int> get_factors(const int n) {
	vector<int> facts;
	int factor = floor((n + 0.0)/2);
	while (factor != 0) {
		if (n % factor == 0)
			facts.push_back(factor);
		--factor;
	}
	return facts;
}

int get_smallest_pattern_length(const int s_len, const int p) {
	if (s_len == 1) return s_len;
	
	for (int f = p; f >= 0; --f) {
		if (s_len % factors[f] == 0) {
			const int factor = factors[f];
	
			// check if the pattern has the length = factor
			bool ok = true;
			for (int i = 0; i < s_len; i += factor) {
				for (int j = 0; j < factor; ++j) {
					if (s[j] != s[i + j]) {
						ok = false;
						break;
					}
				}

				if (!ok) break;
			}

			// if the pattern has the length = factor, call the function on the smaller string
			if (ok) {
				return get_smallest_pattern_length(factor, f - 1);
			}
		}
	}

	return s_len;
}

int main() {
	cin >> s;
	while (s != ".") {
		factors = get_factors(s.length());
		int pattern_length = get_smallest_pattern_length(s.length(), factors.size() - 1);
		cout << (s.length() / pattern_length) << '\n';
		cin >> s;
	}
  
  return 0;
}
