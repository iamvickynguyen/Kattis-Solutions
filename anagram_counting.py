import sys
import math

for line in sys.stdin:
    letters = {}
    for i in line.strip():
        if i not in letters:
            letters[i] = 1
        else:
            letters[i] += 1

    res = math.factorial(len(line.strip()))
    for v in letters.values():
        b = math.factorial(v)
        res //= math.factorial(v)

    print(res)
