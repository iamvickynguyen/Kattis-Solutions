#include <stdio.h>
#include <string>
using namespace std;

int main() {
	int n, x, cur, count = 1;
	scanf("%d", &n);
	scanf("%d", &x);
	cur = x;
	string s = to_string(x);

	for (int i = 1; i < n; i++) {
		scanf("%d", &x);
		if (x > cur) {
			s += " " + to_string(x);
			cur = x;
			count++;
		}
	}

	printf("%d\n%s", count, s.c_str());
	return 0;
}