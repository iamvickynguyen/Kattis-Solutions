ops = ['+', '-', '*', '/']

line = int(input())
for i in range(line):
    target = int(input())
    if target < -60 or target > 256:
        print("no solution")
    else:
        boo = True
        for a in ops:
            for b in ops:
                for c in ops:
                    cal = "4 {} 4 {} 4 {} 4".format(a,b,c)
                    if eval(cal) == target:
                        print(cal + ' = ' + str(target))
                        boo = False
                        break   
                else:
                    continue
                break
            else:
                continue
            break
        
        if boo:
            print("no solution")

