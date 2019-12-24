import sys
length = int(input())
n = [int(x) for x in input().split()]
max_left = [-1]
min_right = [sys.maxsize]

# fill max_left array
_max = -1
for i in range(length-1):
    if _max < n[i]:
        _max = n[i]
    max_left.append(_max)

# fill min_right array
_min = sys.maxsize
for i in range(length-1, 0, -1):
    if _min > n[i]:
        _min = n[i]
    min_right.append(_min)
# if max_left[j] <= n[j] <= min_right[length - j - 1] , increment count
count = 0
for j in range(length):
    if max_left[j] <= n[j] and n[j] <= min_right[length - j - 1]:
        count += 1

print(count)
