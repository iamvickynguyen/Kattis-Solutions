line = input().split(" ")
a = int(line[0])
b = int(line[1])

count = 0
while a != b:
    if a < b:
        count += (b-a)
        break
    elif a % 2 == 0:
        a //=2
        count += 1
    else:
        a += 1
        count += 1

print(count)