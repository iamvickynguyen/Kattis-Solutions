plane = {
    '1': [0,0],
    '2': [1,0],
    '3': [2,0],
    '4': [0,1],
    '5': [1,1],
    '6': [2,1],
    '7': [0,2],
    '8': [1,2],
    '9': [2,2],
    '0': [1,3] 
}

# generate all possible combinations
numbers = set()
for i in range(1, 201):
    s = str(i)
    valid = True
    for j in range(1, len(s)):
        if not (plane[s[j]][0] >= plane[s[j-1]][0] and plane[s[j]][1] >= plane[s[j-1]][1]):
            valid = False
            break
    if valid:
        numbers.add(i)

t = int(input())
for i in range(t):
    k = int(input())
    offset = 1
    while k not in numbers:
        if k - offset in numbers:
            k -= offset
            break
        elif k + offset in numbers:
            k += offset
            break
        offset += 1
    print(k)