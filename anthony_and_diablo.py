import math

# idea: circle has the largest area
data = [float(x) for x in input().split()]
radius = data[1]/(2*math.pi)
area = radius**2 * math.pi

if area >= data[0]:
    print("Diablo is happy!")
else:
    print("Need more materials!")
