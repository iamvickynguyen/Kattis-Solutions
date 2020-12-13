import sys
for line in sys.stdin:
    l = [int(x) for x in line.split()]
    n = l[0]
    s = set()
    jolly = True
    for i in range(1, n):
        d = abs(l[i] - l[i + 1])
        if d in s or d > n - 1:
            print('Not jolly')
            jolly = False
            break
        else:
            s.add(d)
    if jolly:
        print('Jolly')