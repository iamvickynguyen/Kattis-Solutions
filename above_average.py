line = int(input())
for _ in range(line):
    data = [int(x) for x in input().split()]
    avg = sum(data[1:])/data[0]
    n = len([x for x in data[1:] if x > avg])
    print("%.3f" % (n*100/data[0]) + "%")
