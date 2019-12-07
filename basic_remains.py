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
    p = int(str(data[1]), b)
    m = int(str(data[2]), b)
    k = p % m
    result = to_original_base(k, b)
    print(result)
    data = [int(x) for x in input().split()]
