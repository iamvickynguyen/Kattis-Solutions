data = input().split()
s = list(data[0])
sorted_string = sorted(s)

for i in range(len(s)):
    for j in range(i+int(data[1]), len(s)):
        if ord(s[i]) > ord(s[j]):
            s[i], s[j] = s[j], s[i]

if s == sorted_string:
    print('Yes')
else:
    print('No')
