import math

p, a, b, c, d, n = map(int, input().split())
arr = []
for k in range(1, n+1):
    price = p*(math.sin(a*k+b) + math.cos(c*k+d) + 2)
    arr.append(price)

# search
cal = 0
_max = arr[0]
result = 0
for i in range(len(arr)):
    if arr[i] > _max:
        _max = arr[i]
        result = max(cal, result)
        cal = 0
    else:
        cal = max(_max - arr[i], cal)
result = max(cal, result)
print(result)
