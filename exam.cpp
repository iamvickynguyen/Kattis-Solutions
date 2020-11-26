#include <stdio.h>
#include <string.h>
#include <cmath>
using namespace std;

int main() {
	int k;
	scanf("%d", &k);
	char y[1000];
	scanf("%s", y);
	char f[1000];
	scanf("%s", &f);

	int same = 0;
	for (int i = 0; i < strlen(y); i++) {
		if (y[i] == f[i])
			same++;
	}

	printf("%d", strlen(y) - abs(same - k));	
	return 0;
}