total = 0


def hailstone_sequence(n):
    global total
    total += n
    if n == 1:
        return 1
    elif n % 2 == 0:
        hailstone_sequence(n//2)
    else:
        hailstone_sequence(3*n + 1)
    return total


n = int(input())
print(hailstone_sequence(n))
