n, m = map(int, input().split())
plain = input()[::-1]
cipher = list(input()[::-1])
out = []
for i in range(n):
    out.append(chr( (ord(cipher[i]) - ord(plain[i])) % 26 + 97 ))
    cipher[i] = plain[i]
for i in range(n, m):
    out.append(chr( (ord(cipher[i]) - ord(out[i - n])) % 26 + 97 ))
    cipher[i] = out[i - n]
print(''.join((cipher)[::-1]))