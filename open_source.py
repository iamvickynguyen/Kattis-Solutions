import sys
projects = {}
cur_project = ''
students = {}
for line in sys.stdin:
    line = line.strip()

    if line == '1':
        for k, v in students.items():
            if len(v) > 1:
                for proj in v:
                    projects[proj].remove(k)
        # sort
        output = []
        for k, v in projects.items():
            output.append((k, len(v)))
        output.sort(key=lambda x: (-x[1], x[0]))

        # print
        for item in output:
            print(item[0] + ' ' + str(item[1]))

        projects.clear()
        cur_project = ''
        students.clear()

    elif line == '0':
        break

    elif line.isupper():
        cur_project = line
        projects[line] = set()

    else:
        # add project to students
        if line in students:
            students[line].add(cur_project)
        else:
            students[line] = {cur_project}

        # add student to projects
        projects[cur_project].add(line)
