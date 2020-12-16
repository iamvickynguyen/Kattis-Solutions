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

for line in sys.stdin:
    l = [int(x) for x in line.split()]
    power = {}
    for i in l:
        p = PrimeFactor(i)
        for k, v in p.items():
            if k in power:
                power[k] = max(power[k], v)
            else:
                power[k] = v
    result = 1
    for k, v in power.items():
        result *= k ** v
    print(result)