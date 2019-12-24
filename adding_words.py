import sys
import math

def_val = {}
val_def = {}

for line in sys.stdin:
    line = line.strip()
    n = line.split()
    key = [n[x] for x in range(1, len(n)) if x % 2 != 0]
    if n[0] == 'def':
        def_val[n[1]] = n[2]
        val_def[n[2]] = n[1]
    elif n[0] == 'calc':
        for item in key:
            if item not in def_val:
                print(line[5:] + " unknown")
                break
        else:
            s = ''
            for i in range(1, len(n)-1):
                if n[i] in def_val:
                    s += def_val[n[i]]
                else:
                    s += n[i]
            if len(s) > 1:
                result = str(eval(s))
                if result not in val_def:
                    print(line[5:] + " unknown")
                else:
                    print(line[5:] + " " + val_def[result])
            else:
                if key[0] not in def_val:
                    print(line[5:] + " unknown")
                # print(line[5:] + " " + key[0])
    else:
        def_val.clear()
        val_def.clear()
