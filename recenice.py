num_string = {1: 'one', 2: 'two', 3: 'three', 4: 'four', 5: 'five', 6: 'six',
              7: 'seven', 8: 'eight', 9: 'nine', 10: 'ten', 11: 'eleven', 12: 'twelve',
              13: 'thirteen', 14: 'fourteen', 15: 'fifteen', 16: 'sixteen',
              17: 'seventeen', 18: 'eighteen', 19: 'nineteen', 20: 'twenty', 30: 'thirty', 40: 'forty', 50: 'fifty', 60: 'sixty',
              70: 'seventy', 80: 'eighty', 90: 'ninety', 100: 'onehundred', 200: 'twohundred', 300: 'threehundred', 400: 'fourhundred', 500: 'fivehundred', 600: 'sixhundred', 700: 'sevenhundred', 800: 'eighthundred', 900: 'ninehundred'}

string_num = {v: k for k, v in num_string.items()}


def to_string(count):
    s = ''
    if count > 99:
        hundred = count - count % 100
        count -= hundred
        s += num_string[hundred]
    if count > 19:
        ten = count - count % 10
        count -= ten
        s += num_string[ten]
    s += num_string[count]
    return s


line = int(input())
s = [None] * line
count = 0
for i in range(line):
    word = input()
    if word != '$':
        s[i] = word
        count += len(word)

# map
if count > 99:


blank = to_string(count)

for x in range(line):
    if s[x] == None:
        s[x] = blank

print(" ".join(s))
