def check(arr, x):
    n = arr.copy()
    n.append(x)
    n = sorted(n)
    return n[1] - n[0] == n[2] - n[1] and n[2] - n[1] == n[3] - n[2]

n = sorted([int(i) for i in input().split()])
mingap = min(n[1]-n[0], n[2]-n[1])
if check(n, n[0] - mingap):
    print(n[0] - mingap)
elif check(n, n[0] + mingap):
    print(n[0] + mingap)
elif check(n, n[1] - mingap):
    print(n[1] - mingap)
elif check(n, n[1] + mingap):
    print(n[1] + mingap)
elif check(n, n[2] - mingap):
    print(n[2] - mingap)
elif check(n, n[2] + mingap):
    print(n[2] + mingap)
else:
    print(n[3] + mingap)