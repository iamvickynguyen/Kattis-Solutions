n = int(input())
a = []
for _ in range(n):
    a.append(int(input()))
a.sort(reverse=True)
total = 0
for i in range(n):
    if i % 3 != 2:
        total += a[i]
print(total)

