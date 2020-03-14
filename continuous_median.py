from collections import deque

class LLRBTree: 
    root = None

    def __init__(self, key = None, value = None):
        if key:
            self.root = Node(key, value)

    def search(self, key):
        curr = self.root
        while curr:
            if key < curr.key:
                curr = curr.left
            elif curr.key < key:
                curr = curr.right
            else:
                return curr
        return None

    def insert(self, key, value = None):
        n = Node(key, value)
        self.root = self._insert(n, self.root)
        self.root.is_red = False

    def add(self, key, value = None):
        self.insert(key, value)

    def _insert(self, n, curr):
        if curr:
            if n.key <= curr.key:
                curr.left = self._insert(n, curr.left)
            elif curr.key < n.key:
                curr.right = self._insert(n, curr.right)
            else:
                # don't insert the same key twice
                # or you mess up the delete
                curr.value = n.value
            return self.fix_up(curr)
        return n

    def move_red_left(self, n):
        self.flip_colors(n)
        if self.is_red(n.right.left):
            n.right = self.rotate_right(n.right)
            n = self.rotate_left(n)
            self.flip_colors(n)
        return n

    def move_red_right(self, n):
        self.flip_colors(n)
        if self.is_red(n.left.left):
            n = self.rotate_right(n)
            self.flip_colors(n)
        return n

    def is_red(self, n):
        if n:
            return n.is_red
        return False

    def fix_up(self, n):
        if self.is_red(n.right) and not self.is_red(n.left):
            n = self.rotate_left(n)
        if self.is_red(n.left) and self.is_red(n.left.left):
            n = self.rotate_right(n)
        if self.is_red(n.left) and self.is_red(n.right):
            self.flip_colors(n)
        return n

    def flip_colors(self, n):
        n.left.is_red = not n.left.is_red
        n.right.is_red = not n.right.is_red
        n.is_red = not n.is_red

    def rotate_left(self, n):
        x = n.right
        n.right = x.left
        x.left = n
        x.is_red = n.is_red
        n.is_red = True
        return x

    def rotate_right(self, n):
        x = n.left
        n.left = x.right
        x.right = n
        x.is_red = n.is_red
        n.is_red = True
        return x

    # return mid and number to the right of mid
    def find_mid(self, mid):
        q = []
        return self._find_mid(self.root, mid, -1, q)

    def _find_mid(self, n, mid, i, q):
        if i > mid + 1:
            return q
        if n is not None:
            self._find_mid(n.left, mid, i, q)
            i += 1
            if i == mid:
                q.append(n.key)
            elif i == mid + 1:
                q.append(n.key)
                return q
            else:
                self._find_mid(n.right, mid, i, q)


    # def _find_mid(self, n, mid):
    #     q = []
    #     current = n
    #     i = -1
    #     stack = []

    #     if not n.left:
    #         q = [n.key, 0]
    #         return q

    #     stack.append(current)
    #     while True:
    #         if current is not None:
    #             stack.append(current.left)
    #             current = current.left
    #         elif stack:
    #             current = stack.pop()
    #             while current is None:
    #                 current = stack.pop()
    #             i += 1
    #             if i == mid:
    #                 q.append(current.key)
    #             elif i == mid + 1:
    #                 q.append(current.key)
    #                 return q
    #             stack.append(current.right)
    #             current = current.right
    #         else:
    #             return q

class Node:

    key = None
    value = None
    left = None
    right = None
    is_red = True

    def __init__(self, key, value = None):
        self.key = key
        self.value = value

    def __repr__(self):
        return '{} Key: {} value: {}'.format('Red  ' if self.is_red else 'Black', self.key, self.value)

cases = int(input())
for _ in range(cases):
    n = int(input())
    numbers = [int(x) for x in input().split()]
    tree = LLRBTree()
    total = 0

    for i in range(n):
        tree.insert(numbers[i])
        mid = i // 2
        q = tree.find_mid(mid)

        if (i+1) % 2 == 0:
            total += (q[0] + q[1])//2
        else:
            total += q[0]

    print(total)
