l = [int(x) for x in input().split()]
l = sorted(l)
s = input()
for i in range(3):
    if s[i] == 'A':
        print(l[0],end=' ')
    elif s[i] == 'B':
        print(l[1],end=' ')
    else:
        print(l[2],end=' ')
print()