import math
import sys
data = input().split()
# n = len(data[0])//2
# if len(data[0]) % 2 ==1:
#     real = sorted(data[0])
#     if data[0][n] == real[n]:
#         print("Yes") if int(data[1]) <= n+1 else print("No")
#         sys.exit(0)
# print("Yes") if int(data[1]) <= n else print("No")

# compare
total_error = 0
error = {}
s = sorted(data[0])
for i in range(len(s)):
    if s[i] not in error:     
        error[s[i]] = [i]
    else:
        error[s[i]].append(i)

for i in range(len(s)):
    total_error += abs(error[data[0][i]].pop(0) - i)

print(total_error)

k = int(data[1])
mid = len(s)//2
if len(data[0]) % 2 ==1:
    if data[0][mid] == s[mid]:
        if k <= mid + 1 and (total_error + 1) % k == 0:
            print("Yes")
            sys.exit(0)
print("Yes") if total_error % k == 0 and k <= mid+1 else print("No")