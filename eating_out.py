n = [int(x) for x in input().split()]
print('impossible' if n[1] + n[2] + n[3] > 2*n[0] else 'possible')
