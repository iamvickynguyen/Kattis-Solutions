dict = {'0':'O', '1': 'L', '2':'Z', '3':'E', '5':'S', '6':'B', '7':'T', '8':'B'}

def convert_to_word(s):
    word = ""
    for w in s:
        if w in dict:
            word += dict[w]
        else:
            word += w
    return word

line = input().split(" ")
bad = []
for i in range (int(line[0])):
    bad.append(input())

for x in range (int(line[1])):
    word = convert_to_word(input())
    boo = True
    for item in bad:
        if item in word:
            print("INVALID")
            boo = False
            break
    if boo:
        print("VALID")