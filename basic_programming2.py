import sys
n, t = map(int, input().split())
A = [int(x) for x in input().split()]
dict = {}
for i in A:
    if i in dict:
        dict[i] += 1
    else:
        dict[i] = 1
A.sort()

if t == 1:
    for k, v in dict.items():
        if (7777-k) in dict:
            print("Yes")
            sys.exit(0)
    print("No")
    sys.exit(0)

if t == 2:
    for v in dict.values():
        if v > 1:
            print("Contains duplicate")
            sys.exit(0)
    print("Unique")
    sys.exit(0)

if t == 3:
    lots = []
    for k, v in dict.items():
        if v > n/2:
            lots.append(k)
    if len(lots) > 0:
        for x in lots:
            print(x, end=' ')
        print()
    else:
        print(-1)
    sys.exit(0)

if t == 4:
    median = []
    if n % 2 != 0:
        median.append(A[n//2])
    else:
        median.append(A[n//2-1])
        median.append(A[n//2])
    if len(median) > 0:
        for x in median:
            print(x, end=' ')
        print()
    sys.exit(0)

if t == 5:
    inrange = []
    for k in A:
        if k >= 100 and k <= 999:
            inrange.append(k)
    if len(inrange) > 0:
        for x in inrange:
            print(x, end=' ')
        print()
