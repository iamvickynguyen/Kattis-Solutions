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


def IsPrime(n):
    if n < 5:
        return n == 2 or n == 3
    if not (n % 6 == 1 or n % 6 == 5):
        return False
    for m in range(5, int(n ** 0.5) + 1, 6):
        if not (n % m and n % (m + 2)):
            return False
    return True


q = int(input())
factor = PrimeFactor(q)
if len(factor) == 1 and IsPrime(list(factor.keys())[0]):
    print('yes')
else:
    print('no')
