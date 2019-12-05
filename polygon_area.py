# Shoelace formula to calculate area of polygon
def Shoelace(points):
    n = len(points)
    area = 0.0
    for i in range(n):
        j = (i + 1) % n
        area += (points[i][0] * points[j][1] - points[j][0] * points[i][1])
    return area/2


tests = int(input())
while tests != 0:
    points = []
    for i in range(tests):
        point = [int(x) for x in input().split()]
        points.append(point)

    # calculate area
    area = Shoelace(points)
    print(('CW' if area < 0 else 'CCW') + " {:.1f}".format(abs(area)))

    tests = int(input())
