import math
data = [int(x) for x in input().split()]
h = data[0]
theta = data[1]
if theta >= 0 and theta <= 180:
    print("safe")
elif theta == 270:  # division by 0
    print(h)
else:  # use triangle, find hypotenuse
    x = int(h/math.sin(math.pi*(theta-180)/180)
            ) if theta < 270 else int(h/math.cos(math.pi*(theta-270)/180))
    print(x)
