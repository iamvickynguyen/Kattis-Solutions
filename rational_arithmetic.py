# idea: compute like doing on paper, and divide by gcd
import math
line = int(input())
for _ in range(line):
    numerator = 1
    denominator = 1
    data = input().split()
    x1, y1, x2, y2, op = int(data[0]), int(
        data[1]), int(data[3]), int(data[4]), data[2]
    if op == '+':
        numerator = x1*y2 + x2*y1
        denominator = y1*y2
    elif op == '-':
        numerator = x1*y2 - x2*y1
        denominator = y1*y2
    elif op == '*':
        numerator = x1*x2
        denominator = y1*y2
    else:
        numerator = x1*y2
        denominator = y1*x2
    d = math.gcd(numerator, denominator)
    numerator //= d
    denominator //= d
    if (numerator/denominator) < 0:
        print(str(-1*abs(numerator)) + ' / ' + str(abs(denominator)))
    else:
        print(str(abs(numerator)) + ' / ' + str(abs(denominator)))
