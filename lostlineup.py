n = int(input())
d = [int(x) for x in input().split()]
order = ["1"] * n
for f in range(n - 1):
    pos = d[f] - n + 1
    order[pos] = str(f + 2)
print(' '.join(order))