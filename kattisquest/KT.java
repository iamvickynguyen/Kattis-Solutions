import java.util.Scanner;
import java.util.Collections;
import java.util.*;

public class KT {
    public static int BinarySearchIndex(ArrayList<Quest> sortedQuest, Quest q) {
        return Collections.binarySearch(sortedQuest, q, new QuestComparator());
    }

    // to real position
    public static int toIndex(int x) {
        if (x < 0)
            return (-x - 1);
        return x;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String inputString = scanner.nextLine();
        int numLine = Integer.parseInt(inputString);
        ArrayList<Quest> sortedQuest = new ArrayList<Quest>(200000);

        for (int i = 0; i < numLine; i++) {
            String line = scanner.nextLine();
            String[] s = line.split(" ");

            // add
            if (s[0].equals("add")) {
                Quest quest = new Quest(Integer.parseInt(s[1]), Integer.parseInt(s[2]));
                if (sortedQuest.isEmpty())
                    sortedQuest.add(quest);
                else {
                    int index = toIndex(BinarySearchIndex(sortedQuest, quest));
                    sortedQuest.add(index, quest);
                }
            }

            // find and remove
            else {
                int x = Integer.parseInt(s[1]);
                int total = 0;
                int start = toIndex(BinarySearchIndex(sortedQuest, new Quest(x, 100000)));
                while ((start < sortedQuest.size()) && (x > 0)) {
                    Quest q = sortedQuest.get(start);
                    if ((q.e <= x) && (q.boo == 0)) {
                        total += q.g;
                        x -= q.e;
                        q.boo = 1;
                        // sortedQuest.remove(q);
                    }
                    start += 1;
                }
                System.out.println(total);
            }
        }
        scanner.close();
    }
}

class Quest {
    int e;
    int g;
    int boo;

    public Quest(int e, int g) {
        this.e = e;
        this.g = g;
        this.boo = 0;
    }
}

class QuestComparator implements Comparator<Quest> {
    public int compare(Quest x, Quest y) {
        int result = Integer.compare(y.e, x.e);
        if (result == 0)
            result = Integer.compare(y.g, x.g);
        return result;
    }
}