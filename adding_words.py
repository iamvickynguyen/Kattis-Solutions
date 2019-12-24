import sys

def_val = {}
val_def = {}

for line in sys.stdin:
    line = line.strip()
    n = line.split()
    key = [n[x] for x in range(len(n)) if x % 2 != 0]
    if n[0] == 'def':
        if n[1] in def_val:
            del(val_def[def_val[n[1]]])
        def_val[n[1]] = n[2]
        val_def[n[2]] = n[1]
    elif n[0] == 'calc':
        # if definition is not defined
        for item in key:
            if item not in def_val:
                print(line[5:] + " unknown")
                break

        # definition is defined, check if result is defined or not
        else:
            equation = ''
            for i in range(1, len(n)-1):
                if n[i] in def_val:
                    equation += def_val[n[i]]
                else:
                    equation += n[i]

            result = str(eval(equation))
            if result in val_def:
                print(line[5:] + " " + val_def[result])
            else:
                print(line[5:] + " unknown")
    else:
        def_val.clear()
        val_def.clear()
