#include <stdio.h>

int main()
{
    int n, m, count;
    scanf("%d",&n);
    scanf("%d",&m);
    while ((n != 0) && (m != 0))
    {
        count = 0;
        int l[n];
        for (int i = 0; i < n; i++)
        {
            int a;
            scanf("%d", &a);
            l[i] = a;
        }

        int i1 = 0;
        int i2 = m;
        while ((i1 < n) && (i2 > 0))
        {
            i2 -= 1;
            int x;
            scanf("%d", &x);

            while ((i1 < n) && (l[i1] < x))
            {
                i1 += 1;
            }
            if (i1 >= n)
                break;
            if (l[i1] == x)
            {
                count += 1;
                i1 += 1;
            }
        }
        while (i2 > 0)
        {
            int x;
            scanf("%d", &x);
            i2 -= 1;
        }
        printf("%d\n", count);
        scanf("%d",&n);
        scanf("%d",&m);
    }
    return 0;
}