#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *s = (char *)malloc(sizeof(char) * 100001);
    int len = 0;
    char c = '\0';
    int i = 0;
    int q = 0;
    int a = 0;
    int b = 0;
    int cnt = 0;

    while (c != '\n') {
        c = getchar();
        s[i++] = c;
    }
    s[i] = '\0';
    len = i;

    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        scanf("%d %d", &a, &b);
        cnt = 0;
        while (a + cnt < len && b + cnt < len) {
            if (s[a + cnt] == s[b + cnt]) cnt++;
            else break;
        }
        printf("%d\n", cnt);
    }

    return 0;
}