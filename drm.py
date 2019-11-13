dic={'A':0, 'B':1, 'C':2, 'D':3, 'E':4, 'F':5, 'G':6, 'H':7, 'I':8, 'J':9, 'K':10, 'L':11, 'M':12, 'N':13, 'O':14, 'P':15, 'Q':16, 'R':17, 'S':18, 'T':19, 'U':20, 'V':21, 'W':22, 'X':23, 'Y':24, 'Z':25}
valueDic={0:'A', 1:'B', 2:'C', 3:'D', 4:'E', 5:'F', 6:'G', 7:'H', 8:'I', 9:'J', 10:'K', 11:'L', 12:'M', 13:'N', 14:'O', 15:'P', 16:'Q', 17:'R', 18:'S', 19:'T', 20:'U', 21:'V', 22:'W', 23:'X', 24:'Y', 25:'Z'}

def divide(a):
    size = len(a)
    first = a[:int(size/2)]
    second = a[int(size/2):]
    return first,second

def rotate(x):
    total = 0
    newstring = ""
    for char in x:
        total+=dic[char]
    for char2 in x:
        position = dic[char2]+(total%26)
        if(position>25):
            position-=26
        newstring+=valueDic[position]
    return newstring

def merge(x1, x2):
    msg = ''
    for i in range(0,len(x1)):
        # print(str(dic[x1[i]]+dic[x2[i]]))
        position = dic[x1[i]]+dic[x2[i]]
        # print("pos: " + str(position))
        if (position > 25) :
            position-=26
        msg+=valueDic[position]
    return msg


def main():   
    x = input()
    first,second = divide(x)
    newfirst = rotate(first)
    newsecond = rotate(second)
    print(merge(newfirst,newsecond))

main()