# Idea: divide numerator and denominator by gcd, flip at each step
import math
n = int(input())
x = [int(i) for i in input().split()]
numerator, denominator = 1, x[-1]
for i in range(n-2, -1, -1):
    numerator = denominator*x[i] + numerator
    gcd = math.gcd(numerator, denominator)
    numerator, denominator = denominator//gcd, numerator//gcd

print(str(denominator) + '/' + str(numerator))
