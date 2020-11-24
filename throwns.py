n, k = map(int, input().split())
l = [x for x in input().split()]
stack = [0]
i = 0
while i < len(l):
    if l[i] != 'undo':
        p = int(l[i])
        stack.append(((p % n) + stack[-1]) % n)
        i += 1
    else:
        times = int(l[i + 1])
        for j in range(times):
            stack.pop()
        i += 2
print(stack[-1])