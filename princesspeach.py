n, k = map(int, input().split())
o = {int(input()) for i in range(k)}
for i in range(n):
    if not i in o:
        print(i)
print('Mario got {} of the dangerous obstacles.'.format(len(o)))