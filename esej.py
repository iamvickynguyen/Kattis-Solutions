a, b = map(int, input().split())
count = 26
letters = [chr(i) for i in range(97, 97+26)]
words = [chr(i) for i in range(97, 97+26)]  # first add
essay = ' '.join(letters[:max(a, b//2 + 1)])
essay += ' '
t = 0
while count <= b//2:
    t += 1
    for letter in letters:
        for w in range(26**(t-1), 26**t):
            s = letter + words[w]
            words.append(s)
            essay += s + ' '
            count += 1

            if count > b//2:
                break
        else:
            continue
        break

if count < a:
    essay += ' '.join(words[:a - count])

print(essay)
