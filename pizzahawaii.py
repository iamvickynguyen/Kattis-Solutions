t = int(input())
for _ in range(t):
    n = int(input())
    foreign_native = {}
    native_foreign = {}
    for i in range(n):
        name = input()
        foreign = input().split()[1:]
        native = input().split()[1:]
        for word in foreign:
            native_meanings = set(native)
            if word in foreign_native:
                foreign_native[word] = foreign_native[word].intersection(native_meanings)
            else:
                foreign_native[word] = native_meanings
        
        for word in native:
            foreign_meanings = set(foreign)
            if word in native_foreign:
                native_foreign[word] = native_foreign[word].intersection(foreign_meanings)
            else:
                native_foreign[word] = foreign_meanings
    keys = list(foreign_native.keys())
    keys.sort()
    for k in keys:
        actual_meanings = []
        for fn in foreign_native[k]:
            if k in native_foreign[fn]:
                actual_meanings.append(fn)
        actual_meanings.sort()
        for m in actual_meanings:
            print('(' + k + ', ' + m + ')')
    
    if _ != t - 1:
        print()