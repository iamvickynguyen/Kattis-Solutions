# Number of n-step closed paths on hexagonal lattice
# https://oeis.org/A002898
import math
from math import factorial as fac


def binomial(x, y):
    try:
        binom = fac(x) // fac(y) // fac(x - y)
    except ValueError:
        binom = 0
    return binom


line = int(input())
for _ in range(line):
    n = int(input())
    walks = 0
    for i in range(n+1):
        for j in range(i+1):
            walks += pow(-2, n-i)*binomial(n, i) * \
                pow(binomial(i, j), 3)

    print(walks)
