import java.util.Scanner;

public class string_matching {
    private String pattern;
    private int[][] dfa;

    public string_matching(String pattern) {
        this.pattern = pattern;
        int M = pattern.length();
        int R = 256;
        dfa = new int[R][M];
        dfa[pattern.charAt(0)][0] = 1;
        for (int X = 0, j = 1; j < M; j++) {
            for (int c = 0; c < R; c++)
                dfa[c][j] = dfa[c][X];
            dfa[pattern.charAt(j)][j] = j + 1;
            X = dfa[pattern.charAt(j)][X];
        }
    }

    public void search(String txt) {
        int M = pattern.length();
        int N = txt.length();
        int i = 0, j = 0;
        while (i < N) {
            j = dfa[txt.charAt(i)][j];
            i += 1;
            if (j == M) {
                System.out.print((i - M) + " "); // found
                j = 0;
            }
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        while (s.hasNext()) {
            string_matching k = new string_matching(s.nextLine());
            k.search(s.nextLine());
        }
        s.close();
    }
}