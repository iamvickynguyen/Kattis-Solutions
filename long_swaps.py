import math
import sys
data = input().split()
s = data[0]
k = int(data[1])
s_sort = ''.join(sorted(s))
if s_sort == s:
    print("Yes")
elif k >= len(s):
    print("No")
elif k > math.ceil(len(s)/2):
    if s_sort[(len(s)-k): k] == s[(len(s)-k): k]:
        print("Yes")
    else:
        print("No")
elif len(s) - k - k + 2 >= k:
    print("Yes")
elif len(s) - k - k + 2 == 1 and s_sort[k - 1: (len(s)-k + 1)] != s[k - 1: (len(s)-k + 1)]:
    print("No")
else:
    print("Yes")
