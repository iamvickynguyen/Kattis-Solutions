from itertools import permutations


def IsPrime(n):
    if n < 5:
        return n == 2 or n == 3
    if not (n % 6 == 1 or n % 6 == 5):
        return False
    for m in range(5, int(n ** 0.5) + 1, 6):
        if not (n % m and n % (m + 2)):
            return False
    return True


# generate permutations from list of numbers

def permutation(number):
    l = set()
    for i in range(1, len(number)+1):
        perm = permutations(number, i)
        for item in list(perm):
            num = int(''.join(map(str, item)))
            l.add(num)
    return list(l)


line = int(input())
for i in range(line):
    number = [int(x) for x in input()]
    perm = permutation(number)
    count = 0
    for x in perm:
        if IsPrime(x):
            count += 1
    print(count)
