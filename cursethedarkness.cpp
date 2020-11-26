#include <stdio.h>
#include <string.h>
#include <cmath>
using namespace std;

int main() {
	int m, c;
	float bx, by, cx, cy;
	scanf("%d", &m);
	while (m--) {
		scanf("%f %f %d", &bx, &by, &c);
		bool ok = false;
		while (c--) {
			scanf("%f %f", &cx, &cy);
			if (sqrt((bx - cx) * (bx - cx) + (by - cy) * (by - cy)) <= 8)
				ok = true;
		}

		if (ok)
			printf("light a candle\n");
		else
			printf("curse the darkness\n");
	}
	return 0;
}