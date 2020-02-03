# deque used for inorder output
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

    def min(self):
        return self._min(self.root)

    def _min(self, curr):
        if curr:
            while curr.left:
                curr = curr.left
        return curr

    def max(self):
        return self._max(self.root)

    def _max(self, curr):
        if curr:
            while curr.right:
                curr = curr.right
        return curr

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
            else:
                curr.right = self._insert(n, curr.right)
            return self.fix_up(curr)
        return n

    def delete(self, key):
        self.root = self._delete(key, self.root)
        if self.root:
            self.root.is_red = False

    def remove(self, key):
        self.delete(key)

    def _delete(self, key, curr):
        try:
            if key < curr.key:
                if not (self.is_red(curr.left) or self.is_red(curr.left.left)):
                    curr = self.move_red_left(curr)
                curr.left = self._delete(key, curr.left)
            else:
                if self.is_red(curr.left):
                    curr = self.rotate_right(curr)
                if key == curr.key and not curr.right:
                    return None
                if not (self.is_red(curr.right) or self.is_red(curr.right.left)):
                    curr = self.move_red_right(curr)
                if key == curr.key:
                    succ = self._min(curr.right)
                    curr.key, curr.value = succ.key, succ.value
                    curr.right = self.delete_min(curr.right)
                else:
                    curr.right = self._delete(key, curr.right)
        except AttributeError:
            pass
        return self.fix_up(curr)

    def delete_min(self):
        self.root = _delete_min(self.root)
        self.root.is_red = False

    def remove_min(self):
        self.delete_min()

    def _delete_min(self, curr):
        if curr.left:
            if not (self.is_red(curr.left) or self.is_red(curr.left.left)):
                curr = self.move_red_left(curr)
            curr.left = _delete_min(curr.left)
            return fix_up(curr)
        return None

    def delete_max(self):
        self.root = self._delete_max(self.root)
        self.root.is_red = False

    def remove_max(self):
        self.delete_max()

    def _delete_max(self, curr):
        return

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

    def __iter__(self):
        return iter(self.inorder())

    def inorder(self):
        Q = deque()
        self._inorder(self.root, Q)
        return Q

    def _inorder(self, n, Q):
        if n:
            self._inorder(n.left, Q)
            Q.append(n)
            self._inorder(n.right, Q)

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



def find_and_remove(node, x, node_min):
    total = 0
    current = node
    stack = []
    done = 0
    while True:
        if x < node_min.key[0] or x <= 0:
            break
        if current is not None:
            stack.append(current)
            current = current.right
        elif stack:
            current = stack.pop()
            if current.key[0] <= x and current.value == 0:
                current.value = 1
                total += current.key[1]
                x -= current.key[0]
            current = current.left
        else:
            break
    return total
        

tree = LLRBTree()
line = int(input())
for _ in range(line):
    ip = input().split()
    if ip[0] == 'add':
        tree.add((int(ip[1]), int(ip[2])), 0)
    else:
        x = int(ip[1])
        total = find_and_remove(tree.root, x, tree.min())
        print(total)