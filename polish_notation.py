import sys

ops = set(['+', '-', '*'])
for line in sys.stdin:
    line = line.strip().split()
    stack = []
    s = ''
    for i in range(len(line)):
        if line[i] in ops:
            stack.append(line[i])
        elif line[i].isalpha():
            s = line[i] + s
            while len(stack) > 0:
                s = stack.pop() + str(s)
        elif line[i].isdigit():
            if len(stack) > 0:
                while stack[-1].isdigit():
                    a = stack.pop()
                    op = stack.pop()
                    cal = a + op + line[i]
                    result = eval(cal)
                    s = result + s
                stack.append(line[i])
            while len(stack) > 0:
                s = stack.pop() + str(s)

    print(s)
