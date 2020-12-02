import sys
for line in sys.stdin:
    line = line.strip().split()
    for word in line:
        if word[0] in ['a', 'e', 'i', 'o', 'u', 'y']:
            print(word + 'yay', end=' ')
        else:
            for i, c in enumerate(word):
                if c in ['a', 'e', 'i', 'o', 'u', 'y']:
                    print(word[i:] + word[:i] + 'ay', end = ' ')
                    break
    print()