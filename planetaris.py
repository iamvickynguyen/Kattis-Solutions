n, a = map(int, input().split())
l = [int(x) for x in input().split()]
l.sort()
count = 0
for i in range(n):
    if l[i] < a:
        a = a - l[i] - 1
        count += 1
    else:
        break
print(count)
