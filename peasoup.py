n = int(input())
found = False
for i in range(n):
    k = int(input())
    name = input()
    items = [input() for j in range(k)]
    if "pea soup" in items and "pancakes" in items:
        print(name)
        found = True
        break

if not found:
    print("Anywhere is fine I guess")