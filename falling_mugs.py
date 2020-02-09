import math
d = int(input())
n1 = -1
impossible = True
for i in range(math.floor(math.sqrt(d)) + 1):
    n2 = math.sqrt(d + i**2)
    if n2.is_integer():
        print(str(i) + ' ' + str(int(n2)))
        impossible = False
if impossible:
    print("impossible")
