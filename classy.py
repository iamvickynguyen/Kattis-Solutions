def convert_string_reverse(s):
    result = ''
    l = s.split('-')
    for i in range(len(l)-1, -1, -1):
        if l[i] == 'upper':
            result += 'u'
        elif l[i] == 'middle':
            result += 'm'
        else:
            result += 'l'
    return result

case = int(input())
for _ in range(case):
    people = []
    n = int(input())
    for i in range(n):
        ip = input().split(':')
        converted_string = convert_string_reverse(ip[1][1:-len(' class')])
        people.append([ip[0], converted_string])
    sort_classes = sorted(people, key=lambda x: x[1])

    # sort by alphabet
    # iterate, if previous length == current length, check the last char
    # if same, continue; otherwise, sort the current list
    output = []
    if len(sort_classes) > 0:
        cur_class = sort_classes[0][1]
        cur_length = len(cur_class)
        current_list = [sort_classes[0][0]]
        for index in range(1, n):
            [person, status] = sort_classes[index]
            if len(status) <= cur_length or status > cur_class:
                # sort
                current_list.sort(key=lambda x: x[0], reverse = True)
                output += current_list
                current_list.clear()
            current_list.append(person)
            cur_length = len(status)
            cur_class = status
        current_list.sort(key=lambda x: x[0], reverse = True)
        output += current_list
    for item in output[::-1]:
        print(item)
    print('==============================')

