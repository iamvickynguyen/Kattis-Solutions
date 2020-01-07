import math

n = int(input())
x = math.ceil(n ** (1/9))
# mathematically, math.floor makes more sense, but n**(1/9) doesn't give precise answer (ie: 12 becomes 11.9999999999)
while n % x ** 9 != 0:  # note: math.pow(x, 9) doesn't give precise answer
    x -= 1
print(x)
