def main():
    num = input()
    ls = input().split()
    spend=0
    for i in ls:
        if int(i)<0:
            spend+=int(i)
    print(-spend)
main()