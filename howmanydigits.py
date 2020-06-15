import sys
import math
dict = {0:1, 1:1}
result = 0
for i in range(2, 1000001):
    result += math.log10(i)
    dict[i] = math.ceil(result)

for line in sys.stdin:
    n = int(line.strip())
    print(dict[n])