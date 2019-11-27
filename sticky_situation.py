import sys


def check_triangle(a, b, c):
    if abs(a-b) < c and (a+b) > c and abs(a-c) < b and a+c > b and abs(b-c) < a and a < b+c:
        return True
    return False


n = int(input())
sticks = [int(x) for x in input().split()]
sticks.sort()

# check 3 consecutive numbers
for i in range(n-2):
    if check_triangle(sticks[i], sticks[i+1], sticks[i+2]):
        print("possible")
        sys.exit(0)
print("impossible")
