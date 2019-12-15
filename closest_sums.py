import sys
count = 0
for line in sys.stdin:
    n = int(line)
    count += 1
    print("Case " + str(count) + ":")

    # sort
    numbers = []
    for _ in range(n):
        numbers.append(int(input()))
    numbers.sort()

    # sum of left and right
    m = int(input())
    for _ in range(m):
        _sum = int(input())
        cur_sum = 0
        min_error = sys.maxsize
        l = 0
        r = len(numbers) - 1
        while(l < r):
            total = numbers[l] + numbers[r]
            if abs(total - _sum) < min_error:
                min_error = abs(total - _sum)
                cur_sum = total
            if total < _sum:
                l += 1
            else:
                r -= 1
        print("Closest sum to " + str(_sum) + " is " + str(cur_sum) + ".")
