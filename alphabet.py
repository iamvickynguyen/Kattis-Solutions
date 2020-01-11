# longest increasing subsequence (LIS)
def LIS(s):
    table = [1]*len(s)
    for i in range(1, len(s)):
        for j in range(i):
            if s[i] > s[j] and table[i] < table[j] + 1:
                table[i] = table[j] + 1
    return max(table)


print((26-LIS(input())))
