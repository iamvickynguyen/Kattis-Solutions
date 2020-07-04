import sys
s = input()
p = input()
if s == p:
    print('Yes')
elif len(s) == len(p):
    for i in range(len(s)):
        if s[i].isdigit():
            if not (p[i].isdigit() and s[i] == p[i]):
                print('No')
                sys.exit(0)
        elif s[i].islower():
            if p[i].lower() != s[i]:
                print('No')
                sys.exit(0)
        else:
            if p[i].upper() != s[i]:
                print('No')
                sys.exit(0)
    print('Yes')
elif len(p) > len(s):
    print('No')
else:
    if (s[:-1] == p and s[-1].isdigit()) or (s[1:] == p and s[0].isdigit()):
        print('Yes')
    else:
        print('No')