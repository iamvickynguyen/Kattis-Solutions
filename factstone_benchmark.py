# Idea: 2**bit >= n! -> bit >= log(n!)/log(2)
# log(n!) = log(1) + log(2) + ... + log(n)
import math
n = int(input())
while n != 0:
    bit = 4 * (2**((n-1960)//10))
    i = 1
    val = math.log(i)/math.log(2)
    while bit >= val:
        bit -= val
        i += 1
        val = math.log(i)/math.log(2)
    print(i-1)
    n = int(input())
