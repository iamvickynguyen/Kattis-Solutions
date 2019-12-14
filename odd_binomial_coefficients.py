# https://oeis.org/A006046
# memoization
table = {}


def total(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    if n in table:
        return table[n]
    elif n % 2 == 0:
        table[n] = 3*total(n//2)
    else:
        k = (n-1)//2
        table[n] = 2*total(k) + total(k+1)
    return table[n]


n = int(input())
print(total(n))
