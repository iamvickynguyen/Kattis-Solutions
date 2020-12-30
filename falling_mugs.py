# n2^2 - n1^2 = D <=> (n+x)^2 - n^2 = 2xn + x^2 = D
import math
d = int(input())
notfound = True
for x in range(1, math.ceil(math.sqrt(d)) + 1):
    n = (d - pow(x, 2))/(2*x)
    if n.is_integer():
        print(int(n), int(n+x))
        notfound = False
        break
if notfound:
    print('impossible')
