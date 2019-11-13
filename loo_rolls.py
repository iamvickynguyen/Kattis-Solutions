# loo roll length: l
# use n cm
# roll k
import sys
l, n = [int(x) for x in sys.stdin.readline().split()]
# print(l)
i=1
result = l%n
while(result != 0):
    i+=1
    n-=result
    result =l%n
print(i)