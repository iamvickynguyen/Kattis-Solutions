n, b = map(int, input().split())
print("yes" if (2 ** (b + 1)) - 1>= n else "no")