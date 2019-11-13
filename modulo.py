def main():
    count = 0
    i = 0
    list_input = []
    list_out = [0]*42

    while i<10:
        list_input.append(input())
        i+=1

    for x in list_input:
        pos = modulo(x)
        if (list_out[pos]==0): 
            list_out[pos]=1
            count+=1
    print(count)

def modulo(x):
    return x%42

main()