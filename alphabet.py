# longest increasing subsequence (LIS)
def LIS():
    table = [1]*len(s)
    for i in range(1, len(s)):
        for j in range(i):
            if s[i] > s[j] and table[i] < table[j] + 1:
                table[i] = table[j] + 1
    return max(table)


s = input()

# find first 'a'
for i in range(len(s)):
    if s[i] == a:
        s = s[i:]
        break

print((len(s)-_max))
