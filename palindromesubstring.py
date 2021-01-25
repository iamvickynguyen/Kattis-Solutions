import sys

def get_palindrome_substring(s, l, r, substrings):
    while l >= 0 and r < len(s) and s[l] == s[r]:
        substrings.add(s[l:r+1])
        l -= 1
        r += 1

for line in sys.stdin:
    line = line.strip()
    substrings = set()
    for i in range(len(line)):
        if i + 1 < len(line):
            get_palindrome_substring(line, i, i + 1, substrings)
        if i + 2 < len(line):
            get_palindrome_substring(line, i, i + 2, substrings)
    for s in sorted(substrings):
        print(s)
    print()