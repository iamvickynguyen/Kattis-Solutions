import math
def maxdivisor(n):
    for i in range(2, math.ceil(math.sqrt(n)) + 1):
        if n % i == 0:
            return n//i
    return 1

n = int(input())
print(n - maxdivisor(n))