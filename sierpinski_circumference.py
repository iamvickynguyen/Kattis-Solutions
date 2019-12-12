import sys
import math

# log(ab) = log(a) + log(b)
# log(a^i) = i*log(a)
i = 1
for line in sys.stdin:
    n = int(line)
    circumference = math.ceil(n*math.log10(3/2) + math.log10(3))
    print("Case " + str(i) + ": " + str(circumference))
    i += 1
