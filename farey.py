max_n = 10001
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

phi = [EulerPhi(x) for x in range(3, max_n)]
ans = [0, 0, 3]
for i in range(max_n - 3):
    ans.append(ans[-1] + phi[i])

p = int(input())
for _ in range(p):
    k, n = map(int, input().split())
    print(k, ans[n])