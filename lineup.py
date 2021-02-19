n = int(input())
names = [input() for _ in range(n)]
inc = list(sorted(names))
if names == inc:
    print("INCREASING")
elif names == inc[::-1]:
    print("DECREASING")
else:
    print("NEITHER")