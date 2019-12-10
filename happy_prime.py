def IsPrime(n):
    if n < 5:
        return n == 2 or n == 3
    if not (n % 6 == 1 or n % 6 == 5):
        return False
    for m in range(5, int(n ** 0.5) + 1, 6):
        if not (n % m and n % (m + 2)):
            return False
    return True


def sum_square(n):
    total = 0
    for i in str(n):
        total += int(i)**2
    return total


line = int(input())
for _ in range(line):
    s = input()
    data = [int(x) for x in s.split()]
    seen = set()
    n = data[1]
    while n > 1 and n not in seen:
        seen.add(n)
        n = sum_square(n)
    if data[1] == 1 or not IsPrime(data[1]):
        print(s + " NO")
    elif n == 1:
        print(s + " YES")
    else:
        print(s + " NO")
