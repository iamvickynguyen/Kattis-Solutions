import sys
definition = {}
for line in sys.stdin:
    ip = line.strip().split()
    if ip[0] == 'define':
        definition[ip[2]] = int(ip[1])
    else:
        if ip[1] not in definition or ip[3] not in definition:
            print('undefined')
        else:
            a, b = definition[ip[1]], definition[ip[3]]
            if ip[2] == '<':
                print('true') if a<b else print('false')
            elif ip[2] == '>':
                print('true') if a>b else print('false')
            elif ip[2] == '=':
                print('true') if a==b else print('false')
