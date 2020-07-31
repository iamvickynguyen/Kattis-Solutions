import math
a, b = map(int, input().split('/'))
numerator = (a - b*32)*5
denominator = b*9
gcd = math.gcd(numerator, denominator)
print(str(numerator//gcd) + '/' + str(denominator//gcd))