# Idea: example 120 = (2^3)(3)(5)
# sum of divisors = (1+2+2^2+2^3)(1+3)(1+5) - 120
import sys


def PrimeFactor(n):
    power = {}
    while not n % 2:
        try:
            power[2] += 1
        except KeyError:
            power[2] = 1
        n //= 2
    i = 3
    while i * i <= n:
        while not n % i:
            try:
                power[i] += 1
            except KeyError:
                power[i] = 1
            n //= i
        i += 2
    if n != 1:
        power[n] = 1
    return power


for n in sys.stdin:
    n = int(n.strip())
    power = PrimeFactor(n)
    result = 1
    for k, v in power.items():
        tmp = 1
        for i in range(1, v + 1):
            tmp += k**i
        result *= tmp
    result -= n
    if result == n:
        print(str(n) + ' perfect')
    elif abs(result - n) > 2:
        print(str(n) + ' not perfect')
    else:
        print(str(n) + ' almost perfect')
