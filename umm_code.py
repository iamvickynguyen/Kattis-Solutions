unaccepted = [chr(i) for i in range(48, 58)] + [chr(i)
                                                for i in range(65, 91)] + [chr(i) for i in range(97, 123)]


def check_word(s):
    for i in range(len(s)):
        if s[i] in unaccepted and s[i] != 'u' and s[i] != 'm':
            return False
    return True


code = input().split()
count = 6
total = 0
s = ''
for w in code:
    if check_word(w):
        for i in range(len(w)):
            if count < 0:
                s += str(chr(total))
                count = 6
                total = 0
            if w[i] == 'u':
                total += 2**count
                count -= 1
            elif w[i] == 'm':
                count -= 1
s += str(chr(total))
print(s)
