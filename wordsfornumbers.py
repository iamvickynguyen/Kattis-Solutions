import sys
num_string = {0: '', 1: 'one', 2: 'two', 3: 'three', 4: 'four', 5: 'five', 6: 'six',
              7: 'seven', 8: 'eight', 9: 'nine', 10: 'ten', 11: 'eleven', 12: 'twelve',
              13: 'thirteen', 14: 'fourteen', 15: 'fifteen', 16: 'sixteen',
              17: 'seventeen', 18: 'eighteen', 19: 'nineteen', 20: 'twenty', 30: 'thirty',
              40: 'forty', 50: 'fifty', 60: 'sixty', 70: 'seventy', 80: 'eighty', 90: 'ninety'}

def number_to_string(n):
    if n == 0:
        return 'zero'
    if n in num_string:
        return num_string[n]
    s = ''
    if n > 19:
        ten = n - n % 10
        n -= ten
        s += num_string[ten] + '-'
    s += num_string[n]
    return s

for line in sys.stdin:
    line = line.strip().split()
    result = ''
    for word in line:
        try:
            converted = number_to_string(int(word))
            if result == '':
                converted = converted.capitalize()
            result += converted + ' '
        except:
            result += word + ' '
    print(result)