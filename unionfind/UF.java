import java.util.*;
import java.util.Scanner;

public class UF {

    private int[] parent; // parent[i] = parent of i
    private byte[] rank; // rank[i] = rank of subtree rooted at i (never more than 31)
    private int count; // number of components

    public UF(int n) {
        if (n < 0)
            throw new IllegalArgumentException();
        count = n;
        parent = new int[n];
        rank = new byte[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    public int find(int p) {
        // validate(p);
        while (p != parent[p]) {
            parent[p] = parent[parent[p]]; // path compression by halving
            p = parent[p];
        }
        return p;
    }

    public int count() {
        return count;
    }

    public boolean connected(int p, int q) {
        return find(p) == find(q);
    }

    public void union(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ)
            return;

        // make root of smaller rank point to root of larger rank
        if (rank[rootP] < rank[rootQ])
            parent[rootP] = rootQ;
        else if (rank[rootP] > rank[rootQ])
            parent[rootQ] = rootP;
        else {
            parent[rootQ] = rootP;
            rank[rootP]++;
        }
        count--;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String inputString = scanner.nextLine();
        String[] info = inputString.split(" ");
        int n = Integer.parseInt(info[0]);
        int q = Integer.parseInt(info[1]);
        UF uf = new UF(n);
        for (int i = 0; i < q; i++) {
            String line = scanner.nextLine();
            String[] s = line.split(" ");
            int a = Integer.parseInt(s[1]);
            int b = Integer.parseInt(s[2]);
            if (s[0].equals("?")) {
                if (uf.find(a) != uf.find(b))
                    System.out.println("no");
                else
                    System.out.println("yes");
            } else
                uf.union(a, b);
        }
        scanner.close();
    }
}