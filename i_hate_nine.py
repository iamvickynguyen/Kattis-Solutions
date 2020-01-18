m = 1000000007
line = int(input())
for _ in range(line):
    n = int(input())
    print((8*pow(9, n-1, m) % m))
