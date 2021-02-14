a = [int(x) for x in input().split()]
for i in range(5):
    for j in range(5-i-1):
        if a[j] > a[j+1]:
            a[j], a[j+1] = a[j+1], a[j]
            print(' '.join([str(x) for x in a]))