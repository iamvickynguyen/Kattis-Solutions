import sys
import math

smallest_size = int(input())
papers = [int(x) for x in input().split()]
l = 2**(-3/4)  # longer edge, shorter edge = longer edge / sqrt(2)

# alternate edge, and take as many papers as we can
tape = l
need = 2
total = 0
for i in range(1, smallest_size):
    total += tape*(need/2)
    need -= papers[i-1]
    if need <= 0:
        break
    need *= 2
    tape = l/(math.sqrt(2)**i)

if need > 0:
    print("impossible")
else:
    print(total)
