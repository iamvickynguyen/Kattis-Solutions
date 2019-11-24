count = {chr(ord('a') + i): 0 for i in range(26)}
seen = {chr(ord('a') + i): {chr(ord('a') + i): False for i in range(26)}
        for i in range(26)}
line = input()
total = 0
for c in line:
    total += count[c]
    seen[c] = {chr(ord('a') + i): False for i in range(26)}
    count[c] = 0
    for item in seen:
        if item != c:
            if not seen[item][c]:
                seen[item][c] = True
                count[item] += 1
print(total)
