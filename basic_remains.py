def to_base_10(num, b):
    num = [int(x) for x in str(num)]
    result = 0
    x = len(num) - 1
    for i in range(len(num)):
        result += num[i]*(b**x)
        x -= 1
    return result


def to_original_base(n, b):
    if n == 0:
        return 0
    digits = []
    while n:
        digits.append(n % b)
        n //= b
    digits = digits[::-1]
    return int(''.join(map(str, digits)))


data = [int(x) for x in input().split()]

while data[0] != 0:
    b = data[0]
    # p = to_base_10(data[1], b)
    # m = to_base_10(data[2], b)
    # k = p % m
    # print(to_original_base(k, b))
    print(int('15', 2))

    data = [int(x) for x in input().split()]
