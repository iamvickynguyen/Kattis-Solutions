p, s = map(str, input().split())
orders = [set(p[x:]) for x in range(len(p))]
p_index = 0
valid = True
for i in range(len(s)):
    if s[i] == p[p_index]:
        p_index += 1
    elif s[i] in orders[p_index]:
        valid = False
        break  
    if p_index == len(p):
        break

if not valid or p_index < len(p):
    print("FAIL")
else:
    print("PASS")