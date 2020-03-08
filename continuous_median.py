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
            if n.key < curr.key:
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

    def getmid(self, mid):
        q = []
        return self._getmid(self.root, mid, 0, q)[0]
    
    def _getmid(self, n, mid, i, q):
        if i > mid:
            return q
        if n:
            self._getmid(n.left, mid, i+1, q)
            if i == mid:
                q.append(n.key)
            self._getmid(n.right, mid, i+1, q)
        return q

    def getmids(self, mid):
        q = []
        q = self._getmids(self.root, mid, 0, q)
        return ((q[0] + q[1])//2)
    
    def _getmids(self, n, mid, i, q):
        if i > mid + 1:
            return q
        if n:
            self._getmids(n.left, mid, i+1, q)
            if i == mid:
                q.append(n.key)
            elif i == mid+1:
                q.append(n.key)
            self._getmids(n.right, mid, i+1, q)
        return q

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
        l = tree.__iter__()
        if len(l) % 2 != 0:
            total += l[len(l)//2]
        else:
            total += ((l[len(l)//2] + l[len(l)//2-1])//2)
        # mid = i // 2
        # if (i+1) % 2 == 0:
        #     total += tree.getmids(mid)
        # else:
        #     total += tree.getmid(mid)

    print(total)
