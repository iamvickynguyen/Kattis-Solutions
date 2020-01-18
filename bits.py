def count_ones(n):
    count = 0
    for i in n:
        if i == '1':
            count += 1
    return count


line = int(input())
for _ in range(line):
    b = input()
    # b = str(format(int(input()), 'b'))
    s = b[0]
    _max = count_ones(str(format(int(s), 'b')))
    for i in range(1, len(b)):
        s += b[i]
        _max = max(_max, count_ones(str(format(int(s), 'b'))))

    print(_max)
