def checkattack(a, b, x):
    return 0 if x % (a + b) == 0 or x % (a + b) > a else 1

a, b, c, d = map(int, input().split())
for x in map(int, input().split()):
    attacks = checkattack(a, b, x) + checkattack(c, d, x)
    print('both') if attacks == 2 else print('one') if attacks == 1 else print('none')