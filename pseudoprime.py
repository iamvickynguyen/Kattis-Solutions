import math
def checkcomposite(p):
    for i in range(2, int(math.sqrt(p)) + 1):
        if p % i == 0:
            return True
    return False

p, a = map(int, input().split())
while p != 0 or a != 0:
    print('yes') if checkcomposite(p) and pow(a, p, p) == a else print('no')
    p, a = map(int, input().split())