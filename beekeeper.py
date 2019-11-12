def check_vowel(w):
    if w == 'a' or w=='e' or w=='i' or w=='o' or w=='u' or w=='y':
        return True
    return False


_input=int(input())
while  _input!= 0:
    _max = -1
    s = ''
    for i in range (_input):
        word = input()
        count = 0
        for x in range(len(word)-1):
            if check_vowel(word[x]) and word[x]==word[x+1]:
                count += 1
        if count > _max:
            _max = count
            s = word
    print(s)
    _input = int(input())



