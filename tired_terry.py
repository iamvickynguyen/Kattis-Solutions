data = [int(x) for x in input().split()]
length = data[0]
p = data[1]
d = data[2]
pattern = input()
pattern += pattern
w = 0
z = 0
count = 0
for i in range(length*2):
    if pattern[i] == 'W':
        w += 1
    else:
        z += 1
    if i-p >= 0:
        if pattern[i-p] == 'W':
            w -= 1
        else:
            z -= 1
    if i>= length:
        if z < d:
            count += 1
print(count)
