import math
n = int(input())
time = [0] * 43205
for _ in range(n):
    d, t = map(int, input().split())
    time[t] += 1
    time[t - d] += 1
    time[t - 2*d] += 1

more_cook = math.ceil(max(time)/2)
print(max(1, more_cook))