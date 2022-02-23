import sys

def is_number(s):
    return s.isdigit() or (s.startswith("-") and s[1:].isdigit())

case = 1
ops = set(['+', '-', '*'])
for line in sys.stdin:
    line = line.strip().split()
    stack = []
    s = ''
    for i in range(len(line)):
        if not is_number(line[i]):
            stack.append(line[i])
        elif is_number(line[i]):
            if len(stack) > 1:
                while len(stack) > 1 and is_number(stack[-1]) and stack[-2] in ops:
                    a = stack.pop()
                    op = stack.pop()
                    cal = a + op + line[i]
                    line[i] = str(eval(cal))
                stack.append(line[i])
            else:
                stack.append(line[i])

    while len(stack) > 0:
        s = stack.pop() + ' ' + s
    print('Case ' + str(case) + ': ' + s)
    case += 1