import sys
keys = {'A#': 'Bb', 'Bb': 'A#', 'C#': 'Db', 'Db': 'C#', 'D#': 'Eb', 'Eb': 'D#', 'F#': 'Gb', 'Gb': 'F#', 'G#': 'Ab', 'Ab': 'G#'}
i = 1
for line in sys.stdin:
    line = line.strip().split()
    try:
        print('Case {}: {} {}'.format(i, keys[line[0]], line[1]))
    except:
        print('Case {}: UNIQUE'.format(i))
    i += 1