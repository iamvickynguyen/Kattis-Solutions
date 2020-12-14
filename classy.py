class Person:
    def __init__ (self, name, _class):
        self.name = name
        self._class = _class

    def __lt__ (self, other):
        return self.name < other.name if self._class == other._class else self._class > other._class

t = int(input())
for _ in range(t):
    people = []
    n = int(input())
    for i in range(n):
        person = input().split()
        p = person[1].split('-')[::-1]
        people.append(Person(person[0][:-1], '-'.join(p + ['middle'] * (10 - len(p)))))

    print('\n'.join(p.name for p in sorted(people)))
    print('=' * 30)