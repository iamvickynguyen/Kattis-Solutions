length = input()
plots = [int(x) for x in input().split()]
plots.sort()
houses = [int(x) for x in input().split()]
squares_to_round = [int(x)*(2**(1/2))*(1/2) for x in input().split()]
houses += squares_to_round
houses.sort()

count = 0
p = 0
h = 0
while p < len(plots) and h < len(houses):
    if houses[h] < plots[p]:
        count += 1
        h += 1
        p += 1
    else:
        p += 1

print(count)
