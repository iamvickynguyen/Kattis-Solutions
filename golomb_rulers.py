import sys
for line in sys.stdin:
    n = [int(x) for x in line.split()]
    n.sort()
    is_ruler = True
    if n[0] != 0:
        print("not a ruler")
    else:
        _max = max(n)
        measures = [False]*_max
        for i in range(len(n)):
            if is_ruler:
                for j in range(i+1, len(n)):
                    dist = n[j] - n[i]
                    if measures[dist-1] == True:
                        print("not a ruler")
                        is_ruler = False
                        break
                    else:
                        measures[dist-1] = True

        if is_ruler:
            missing = ""
            for i in range(len(measures)):
                if measures[i] == False:
                    missing += str((i+1)) + " "

            if missing != "":
                print("missing " + missing)
            else:
                print("perfect")
