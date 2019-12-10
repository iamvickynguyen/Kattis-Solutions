
// Idea: Use KMP substring search algo
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

    public int search(String txt) {
        int M = pattern.length();
        int N = txt.length();
        int i, j;
        for (i = 0, j = 0; i < N && j < M; i++) {
            j = dfa[txt.charAt(i)][j];
        }
        if (j == M)
            return i - M; // found
        return N; // not found
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        while (s.hasNext()) {
            String pattern = s.nextLine();
            string_matching k = new string_matching(pattern);
            String text = s.nextLine();
            int index = k.search(text);
            if (index >= text.length()) {
                System.out.println();
            } else {
                int i = 0;
                while (index < text.length()) {
                    System.out.print((index + i) + " ");
                    text = text.substring(index + pattern.length());
                    i = index + pattern.length();
                    index = k.search(text);
                }
                System.out.println();
            }
        }
        s.close();
    }

}
