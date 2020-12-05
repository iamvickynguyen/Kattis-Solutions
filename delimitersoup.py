l = int(input())
s = input()
stack = []
ok = True
for i in range(l):
    if s[i] in ['(', '[', '{']:
        stack.append(s[i])
    elif s[i] != ' ':
        if len(stack) > 0:
            if (stack[-1] == '(' and s[i] == ')') or (stack[-1] == '[' and s[i] == ']') or (stack[-1] == '{' and s[i] == '}'):
                stack.pop()
            else:
                print(s[i] + ' ' + str(i))
                ok = False
                break
        else:
            print(s[i] + ' ' + str(i))
            ok = False
            break

if ok:
    print('ok so far')