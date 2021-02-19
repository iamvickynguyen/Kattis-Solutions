n = int(input())
s = 0
fac = 1
for i in range(1, n + 1):
    fac *= i
    s += 1/fac
print(s + 1)