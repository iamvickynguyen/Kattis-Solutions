n = int(input())
l = [int(x) for x in input().split()]
stack = []
stack.append(l[0])
for i in range(1, n):
    if len(stack) > 0 and (stack[-1] + l[i]) % 2 == 0:
        stack.pop()
    else:
        stack.append(l[i])
print(len(stack))