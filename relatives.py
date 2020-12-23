def EulerPhi(n):
    primes = PrimeFactor(n)
    result = n
    for i in primes:
        result *= (1-1/i)
    return int(result)

def PrimeFactor(n):
    primes = set()
    while not n % 2:
        primes.add(2)
        n //= 2
    i = 3
    while i * i <= n:
        while not n % i:
            primes.add(i)
            n //= i
        i += 2
    if n != 1:
        primes.add(n)
    return primes

n = int(input())
while n != 0:
    print(EulerPhi(n))
    n = int(input())