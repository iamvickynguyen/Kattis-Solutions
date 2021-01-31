import math
def IsPrime(n):
    if n < 5:
        return n == 2 or n == 3
    if not (n % 6 == 1 or n % 6 == 5):
        return False
    for m in range(5, int(n ** 0.5) + 1, 6):
        if not (n % m and n % (m + 2)):
            return False
    return True

# https://www.geeksforgeeks.org/check-if-a-number-is-in-given-base-or-not/
def isInGivenBase(Str, base):
    letters = ['A', 'B', 'C', 'D', 'E', 'F']
    for c in Str:
        if c in letters:
            if base == 16:
                return True
            return False

    if (base > 16): 
        return False

    elif (base <= 10): 
        for i in range(len(Str)): 
            if (Str[i].isnumeric() and 
                (ord(Str[i]) >= ord('0') and 
                ord(Str[i]) < (ord('0') + base)) == False): 
                return False

    else: 
        for i in range(len(Str)): 
            if (Str[i].isnumeric() and 
                ((ord(Str[i]) >= ord('0') and 
                    ord(Str[i]) < (ord('0') + base)) or 
                (ord(Str[i]) >= ord('A') and 
                    ord(Str[i]) < (ord('A') + base - 10))) == False): 
                return False
    return True

n = int(input())
for _ in range(n):
    x = input()
    count = 0
    primes = 0
    if isInGivenBase(x, 2):
        count += 1
        if IsPrime(int(x, 2)):
            primes += 1
    if isInGivenBase(x, 8):
        count += 1
        if IsPrime(int(x, 8)):
            primes += 1
    if isInGivenBase(x, 10):
        count += 1
        if IsPrime(int(x, 10)):
            primes += 1
    if isInGivenBase(x, 16):
        count += 1
        if IsPrime(int(x, 16)):
            primes += 1
    gcd = math.gcd(primes, count)
    numerator, denominator = primes//gcd, count//gcd
    print(str(numerator) + '/' + str(denominator))