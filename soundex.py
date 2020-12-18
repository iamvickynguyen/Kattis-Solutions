import sys

coding = {'B':'1', 'F':'1', 'P':'1', 'V':'1', \
    'C':'2', 'G':'2', 'J':'2', 'K':'2', 'Q':'2', 'S':'2', 'X':'2', 'Z':'2', \
    'D':'3', 'T':'3', \
    'L':'4', \
    'M':'5', 'N':'5', \
    'R': '6'}
for line in sys.stdin:
    if len(line) > 0:
        cur = -1
        if line[0] in coding:
            cur = coding[line[0]]
            print(coding[line[0]], end='')
        for i in range(1, len(line)):
            if line[i] in coding and coding[line[i]] != cur:
                print(coding[line[i]], end='')
            cur = -1 if line[i] not in coding else coding[line[i]]
        print()