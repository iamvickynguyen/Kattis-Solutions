import sys

m, n = map(int, input().split())
kg = [int(x) for x in input().split()]
fishmonger = {}
for _ in range(n):
    quantity, money = map(int, input().split())
    if money in fishmonger:
        fishmonger[money] += quantity
    else:
        fishmonger[money] = quantity

# sort and match
total = 0
kg.sort(reverse=True)
i = 0
for k, v in sorted(fishmonger.items(), reverse=True):
    while v > 0:
        if i >= len(kg):
            print(total)
            sys.exit(0)
        total += kg[i]*k
        v -= 1
        i += 1

print(total)
