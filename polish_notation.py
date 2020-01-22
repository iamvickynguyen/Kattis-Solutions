import sys
case = 1
ops = set(['+', '-', '*'])
for line in sys.stdin:
    line = line.strip().split()
    stack = []
    s = ''
    for i in range(len(line)):
        if not line[i].isdigit():
            stack.append(line[i])
        elif line[i].isdigit():
            if len(stack) > 1:
                while len(stack) > 1 and stack[-1].isdigit() and stack[-2] in ops:
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
