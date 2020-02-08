def compute(a, b, op):
    if op == '*':
        if a == 'T' and b == 'T':
            return 'T'
        return 'F'
    if op == '+':
        if a == 'F' and b == 'F':
            return 'F'
        return 'T'


dict = {}
stack = []
n = int(input())
x = 0
TF = input().split()
s = input().split()
# preprocess
for i in s:
    if i != '*' and i != '+' and i != '-':
        if i not in dict:
            dict[i] = TF[x]
            x += 1

for k in s:
    if k == '*' or k == '+':
        b = stack.pop()
        a = stack.pop()
        stack.append(compute(a, b, k))
    elif k == '-':
        a = stack.pop()
        a = 'T' if a == 'F' else 'F'
        stack.append(a)
    else:
        stack.append(dict[k])
print(stack[0])
