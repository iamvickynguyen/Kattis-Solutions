# return -1:left turn, 0:straight line, 1:right turn
def turn(a, b, c):
    x = (b[1]-a[1]) * (c[0]-a[0]) + (a[0]-b[0]) * (c[1]-a[1])
    if x < 0:
        return -1
    elif x > 0:
        return 1
    else:
        return 0

# Shoelace formula to calculate area of polygon
def Shoelace(points):
    n = len(points)
    area = 0.0
    for i in range(n):
        j = (i + 1) % n
        area += (points[i][0] * points[j][1] - points[j][0] * points[i][1])
    return abs(area)/2

tests = int(input())
while tests != 0:
    points = []
    for i in range (tests):
        point = [int(x) for x in input().split()]
        points.append(point)
    
    # check turn, in case first 3 points make a straight line
    direction = 0
    for i in range(len(points)-2):
        if turn(points[i], points[i+1], points[i+2]) != 0:
            direction = turn(points[i], points[i+1], points[i+2])
            break

    # calculate area
    s = 'CW' if direction == 1 else 'CCW'
    print(s + " {:.1f}".format(Shoelace(points)))

    tests = int(input())
