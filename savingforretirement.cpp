#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int b, br, bs, a, as;
	cin >> b >> br >> bs >> a >> as;
	int min_saving = (br - b) * bs;
	int years = ceil((min_saving + 0.0) / as + a);
	if (((years - a) * as) <= min_saving)
		cout << (years + 1);
	else cout << years;
	return 0;
}
