n1 = int(input())
n2 = int(input())
result1 = (n2 - n1 + 720) % 360
result2 = - ((n1 - n2 + 720) % 360)
if abs(result1) == 180:
    print(180)
elif abs(result1) < abs(result2):
    print(result1)
else:
    print(result2)