import sys
upside_down = {'0':'0', '1':'1', '2':'2', '5':'5', '6':'9', '8':'8', '9':'6'}

def rotate(n):
    result = ''
    for i in range(len(n)-1, -1, -1):
        if n[i] not in upside_down:
            return 'no'
        result += upside_down[n[i]]
    return int(result)

def check_sum(original, updown, same):
    original_keys = original.keys()
    updown_keys = updown.keys()
    for a in original_keys:
        b = s - a
        if original[a] > 1 and (b in original_keys or b in updown_keys):
            return 'YES'
        elif original[a] == 1 and ((b != a and b in original_keys) or (b in updown_keys and (updown[b] > 1 or (updown[b] == 1 and same[a] != b)))):
            return 'YES'
    return 'NO'

n,s = map(int, input().split())
l = input().split()

# original: {original number : frequency}
# updown: {upside down number : frequency}
# same: {original number : upside down number}
# if frequency > 1, we don't need to check if 2 numbers are the same
original = {}
updown = {}
same = {}
for num in l:
    item = int(num)
    if item in original:
        original[item] += 1
    else:
        original[item] = 1

    new_num = rotate(num)
    if new_num != 'no':
        if new_num in updown:
            updown[new_num] += 1
        else:
            updown[new_num] = 1
        same[item] = new_num
        same[new_num] = item

result = check_sum(original, updown, same)
if result == 'NO':
    result = check_sum(updown, original, same)
    print(result)
    sys.exit(0)
print(result)
