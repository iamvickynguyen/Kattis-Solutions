n = int(input())
a = [int(x) for x in input().split()]
a.sort()
result = []
start = a[0]
current = a[0]
for i in range(1, n):
    if current + 1 != a[i]:
        if start == current:
            result.append(str(current))
        elif start + 1 == current:
            result.append(str(start))
            result.append(str(current))
        else:
            result.append(str(start) + '-' + str(current))
        start = a[i]
        current = a[i]
    else:
        current = a[i]

# last item
if start == current:
    result.append(str(current))
elif start + 1 == current:
    result.append(str(start))
    result.append(str(current))
else:
    result.append(str(start) + '-' + str(current))
print(' '.join(result))