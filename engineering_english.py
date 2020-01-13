import sys
words = set()
for line in sys.stdin:
    line = line.strip()
    s = ''
    for x in line.split():
        if x.lower() not in words:
            s += x + ' '
            words.add(x.lower())
        else:
            s += '. '
    print(s)
