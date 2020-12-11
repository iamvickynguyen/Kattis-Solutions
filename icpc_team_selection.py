t = int(input())
for _ in range(t):
    n = int(input())
    l = [int(i) for i in input().split()]
    l.sort(reverse = True)
    total = sum(l[i*2 + 1] for i in range(n))
    print(total)