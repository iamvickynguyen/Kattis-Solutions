s = input()
t = []
for i in range(len(s)):
    if s[i] == '<':
        if len(t) > 0:
            t.pop()
    else:
        t.append(s[i])
if len(t) > 0:
    print(''.join(t))
