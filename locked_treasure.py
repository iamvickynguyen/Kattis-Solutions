import math


def nCr(n, r):
    f = math.factorial
    return f(n) // f(r) // f(n-r)


line = int(input())
for _ in range(line):
    data = [int(x) for x in input().split()]
    print(nCr(data[0], data[1]-1))
