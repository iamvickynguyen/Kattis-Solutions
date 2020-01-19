import math


def nCr(n, r):
    f = math.factorial
    return f(n) // f(r) // f(n-r)


ip = input().split()
d = int(ip[1])
l = [int(x) for x in input().split()]
quotient = {}
for i in l:
    r = int(i/d)
    if r not in quotient:
        quotient[r] = 1
    else:
        quotient[r] += 1

total = 0
for v in quotient.values():
    if v > 1:
        total += nCr(v, 2)

print(total)
