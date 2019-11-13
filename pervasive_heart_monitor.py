import sys

def monitor(x):
    name = ""
    num, total = 0, 0
    line = x.split()
    for element in line:
        try:
            num+=float(element)
            total+=1
        except ValueError:
            name+=element+" "
    return '%.6f'%(num/total) + " " + name

def main():
    st=""
    for x in sys.stdin:
        st+= monitor(x) + "\n"      
    print(st)

if __name__=="__main__":
    main()