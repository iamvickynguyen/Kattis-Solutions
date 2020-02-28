def Eratosthenes(n):
    IsPrime = [True] * (n + 1)
    for i in range(2, int(n ** 0.5) + 1):
        if IsPrime[i]:
            for j in range(i ** 2, n + 1, i):
                IsPrime[j] = False
    return [i for i in range(2, n + 1) if IsPrime[i]]


max_n = int(50*51/2)
primes = Eratosthenes(max_n)
print(len(primes))
