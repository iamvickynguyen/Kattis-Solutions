n, t = map(int, input().split())
a = [int(x) for x in input().split()]

if t == 1:
    print('7')
elif t == 2:
    print('Bigger') if a[0] > a[1] else print('Equal') if a[0] == a[1] else print('Smaller')
elif t == 3:
    print(sorted(a[:3])[1])
elif t == 4:
    print(sum(a))
elif t == 5:
    print(sum(filter(lambda x: x % 2 == 0, a)))
elif t == 6:
    mod26 = map(lambda x: x % 26, a)
    tochar = map(lambda x: chr(ord('a') + x), mod26)
    print(''.join(tochar))
else:
    index = a[0]
    a[0] = None
    while True:
        if index >= n:
            print('Out')
            break
        if index == n - 1:
            print('Done')
            break
        if a[index] == None:
            print('Cyclic')
            break
        a[index], index = None, a[index]