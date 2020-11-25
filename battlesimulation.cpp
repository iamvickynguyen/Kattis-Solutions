#include <stdio.h>
#include <string.h>
using namespace std;

char get_move(char c) {
	return c == 'R' ? 'S' :
		c == 'B' ? 'K' : 'H';
}

int main() {
	char s[1000000];
	scanf("%s", s);
	int n = strlen(s), i = 0;
	while (i < n) {
		if (i + 2 < n && s[i] != s[i + 1] && s[i + 1] != s[i + 2] && s[i + 2] != s[i]) {
			printf("C");
			i += 3;
		}
		else {
			printf("%c", get_move(s[i]));
			i++;
		}
	}

	return 0;
}