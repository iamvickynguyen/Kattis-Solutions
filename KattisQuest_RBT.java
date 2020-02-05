import java.util.*;
import java.util.Scanner;

class QuestObj {
    int k;
    PriorityQueue<Integer> v = new PriorityQueue<Integer>();

    public QuestObj(int k, PriorityQueue<Integer> v) {
        this.k = k;
        this.v = v;
    }
}

public class KattisQuest_RBT {
    private static final boolean RED = true;
    private static final boolean BLACK = false;

    private Node root;

    private class Node {
        private int key;
        private PriorityQueue<Integer> val;
        private Node left, right;
        private boolean color; // color of parent link
        private int size; // subtree count

        public Node(int key, PriorityQueue<Integer> val, boolean color, int size) {
            this.key = key;
            this.val = val;
            this.color = color;
            this.size = size;
        }
    }

    public KattisQuest_RBT() {
    }

    /***************************************************************************
     * Node helper methods.
     ***************************************************************************/
    // is node x red; false if x is null ?
    private boolean isRed(Node x) {
        if (x == null)
            return false;
        return x.color == RED;
    }

    // number of node in subtree rooted at x; 0 if x is null
    private int size(Node x) {
        if (x == null)
            return 0;
        return x.size;
    }

    public int size() {
        return size(root);
    }

    public boolean isEmpty() {
        return root == null;
    }

    /***************************************************************************
     * Standard BST search.
     ***************************************************************************/

    public PriorityQueue<Integer> get(int key) {
        return get(root, key);
    }

    // value associated with the given key in subtree rooted at x; null if no such
    // key
    private PriorityQueue<Integer> get(Node x, int key) {
        while (x != null) {
            int cmp = key - x.key;
            if (cmp < 0)
                x = x.left;
            else if (cmp > 0)
                x = x.right;
            else
                return x.val;
        }
        return null;
    }

    public boolean contains(int key) {
        return get(key) != null;
    }

    /***************************************************************************
     * Red-black tree insertion.
     ***************************************************************************/

    public void put(int key, PriorityQueue<Integer> val) {
        if (val == null) {
            delete(key);
            return;
        }
        root = put(root, key, val);
        root.color = BLACK;
    }

    // insert the key-value pair in the subtree rooted at h
    private Node put(Node h, int key, PriorityQueue<Integer> val) {
        if (h == null)
            return new Node(key, val, RED, 1);

        int cmp = key - h.key;
        if (cmp < 0)
            h.left = put(h.left, key, val);
        else if (cmp > 0)
            h.right = put(h.right, key, val);
        else
            h.val = val;

        // fix-up any right-leaning links
        if (isRed(h.right) && !isRed(h.left))
            h = rotateLeft(h);
        if (isRed(h.left) && isRed(h.left.left))
            h = rotateRight(h);
        if (isRed(h.left) && isRed(h.right))
            flipColors(h);
        h.size = size(h.left) + size(h.right) + 1;

        return h;
    }

    /***************************************************************************
     * Red-black tree deletion.
     ***************************************************************************/
    public void delete(int key) {
        if (!contains(key))
            return;
        if (!isRed(root.left) && !isRed(root.right))
            root.color = RED;

        root = delete(root, key);
        if (!isEmpty())
            root.color = BLACK;
    }

    // delete the key-value pair with the given key rooted at h
    private Node delete(Node h, int key) {
        if (key - h.key < 0) {
            if (!isRed(h.left) && !isRed(h.left.left))
                h = moveRedLeft(h);
            h.left = delete(h.left, key);
        } else {
            if (isRed(h.left))
                h = rotateRight(h);
            if (key - h.key == 0 && (h.right == null))
                return null;
            if (!isRed(h.right) && !isRed(h.right.left))
                h = moveRedRight(h);
            if (key - h.key == 0) {
                Node x = min(h.right);
                h.key = x.key;
                h.val = x.val;
                h.right = deleteMin(h.right);
            } else
                h.right = delete(h.right, key);
        }
        return balance(h);
    }

    // the smallest key in subtree rooted at x; null if no such key
    private Node min(Node x) {
        if (x.left == null)
            return x;
        else
            return min(x.left);
    }

    // delete the key-value pair with the minimum key rooted at h
    private Node deleteMin(Node h) {
        if (h.left == null)
            return null;

        if (!isRed(h.left) && !isRed(h.left.left))
            h = moveRedLeft(h);

        h.left = deleteMin(h.left);
        return balance(h);
    }

    /***************************************************************************
     * Red-black tree helper functions.
     ***************************************************************************/

    // make a left-leaning link lean to the right
    private Node rotateRight(Node h) {
        Node x = h.left;
        h.left = x.right;
        x.right = h;
        x.color = x.right.color;
        x.right.color = RED;
        x.size = h.size;
        h.size = size(h.left) + size(h.right) + 1;
        return x;
    }

    // make a right-leaning link lean to the left
    private Node rotateLeft(Node h) {
        Node x = h.right;
        h.right = x.left;
        x.left = h;
        x.color = x.left.color;
        x.left.color = RED;
        x.size = h.size;
        h.size = size(h.left) + size(h.right) + 1;
        return x;
    }

    // flip the colors of a node and its two children
    private void flipColors(Node h) {
        h.color = !h.color;
        h.left.color = !h.left.color;
        h.right.color = !h.right.color;
    }

    // Assuming that h is red and both h.left and h.left.left
    // are black, make h.left or one of its children red.
    private Node moveRedLeft(Node h) {
        flipColors(h);
        if (isRed(h.right.left)) {
            h.right = rotateRight(h.right);
            h = rotateLeft(h);
            flipColors(h);
        }
        return h;
    }

    // Assuming that h is red and both h.right and h.right.left
    // are black, make h.right or one of its children red.
    private Node moveRedRight(Node h) {
        flipColors(h);
        if (isRed(h.left.left)) {
            h = rotateRight(h);
            flipColors(h);
        }
        return h;
    }

    // restore red-black tree invariant
    private Node balance(Node h) {
        if (isRed(h.right))
            h = rotateLeft(h);
        if (isRed(h.left) && isRed(h.left.left))
            h = rotateRight(h);
        if (isRed(h.left) && isRed(h.right))
            flipColors(h);

        h.size = size(h.left) + size(h.right) + 1;
        return h;
    }

    /***************************************************************************
     * Ordered symbol table methods.
     ***************************************************************************/
    public QuestObj floor(int key) {
        Node x = floor(root, key);
        if (x == null)
            return null;
        return new QuestObj(x.key, x.val);
    }

    // the largest key in the subtree rooted at x less than or equal to the given
    // key
    private Node floor(Node x, int key) {
        if (x == null)
            return null;
        int cmp = key - x.key;
        if (cmp == 0)
            return x;
        if (cmp < 0)
            return floor(x.left, key);
        Node t = floor(x.right, key);
        if (t != null)
            return t;
        else
            return x;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String inputString = scanner.nextLine();
        int numLine = Integer.parseInt(inputString);
        HashSet<Integer> hashset = new HashSet<Integer>();
        KattisQuest_RBT st = new KattisQuest_RBT();

        for (int i = 0; i < numLine; i++) {
            String line = scanner.nextLine();
            String[] s = line.split(" ");

            // add
            if (s[0].equals("add")) {
                int e = Integer.parseInt(s[1]);
                int g = Integer.parseInt(s[2]);
                if (hashset.contains(e)) {
                    PriorityQueue<Integer> pq = st.get(e);
                    pq.add(-g); // max queue
                    st.put(e, pq);
                } else {
                    PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
                    pq.add(-g);
                    st.put(e, pq);
                    hashset.add(e);
                }
            }

            // find and remove
            else {
                int x = Integer.parseInt(s[1]);
                long total = 0;
                while ((x > 0) && st.size() > 0) {
                    QuestObj n = st.floor(x);
                    if (n == null)
                        break;
                    int e = n.k;
                    PriorityQueue<Integer> q = n.v;
                    while ((x >= e) && (!q.isEmpty())) {
                        total -= q.poll();
                        x -= e;
                    }
                    if (q.isEmpty()) {
                        st.delete(e);
                        hashset.remove(e);
                    }
                }
                System.out.println(total);
            }
        }
        scanner.close();
    }
}