tests = int(input())
for _ in range(tests):
    ip = input().split()
    k = int(ip[0])
    count = 0
    word = input()
    for i in range(int(ip[1])-1):
        cur_word = word
        word = input()
        first_letter = word[0]

        # find first poisition in cur_word
        for index in range(len(cur_word)):
            if first_letter == cur_word[index] and cur_word[index:] == word[:len(cur_word[index:])]:
                break
            count += 1
    count += len(word)
    print(count)
