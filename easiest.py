def cal_sum(n):
    return sum(map(lambda x: int(x), str(n)))

n = int(input())
while (n != 0):
    p = 11
    result = cal_sum(n)
    while cal_sum(n * p) != result:
        p += 1
    print(p)
    n = int(input())