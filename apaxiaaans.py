s = input()
c = s[0]
print(c, end='')
for i in range(1, len(s)):
    if s[i] != c:
        c = s[i]
        print(c, end='')
print()