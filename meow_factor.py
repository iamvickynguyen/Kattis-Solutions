import math


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


n = int(input())
result = 1
factors = PrimeFactor(n)
for k, v in factors.items():
    if v >= 9:
        x = v//9
        result *= math.pow(k, x)

print(int(result))
