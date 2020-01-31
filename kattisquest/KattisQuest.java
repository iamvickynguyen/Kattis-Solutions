import java.util.Scanner;
import java.util.PriorityQueue;
import java.util.*;

public class KattisQuest {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // int numLine = scanner.nextInt();
        String inputString = scanner.nextLine();
        int numLine = Integer.parseInt(inputString);
        // PriorityQueue<Quest> q = new PriorityQueue<Quest>((x, y) -> {
        // int result = Integer.compare(y.e, x.e);
        // if (result == 0)
        // result = Integer.compare(y.g, x.g);
        // return result;
        // });
        PriorityQueue<Quest> q = new PriorityQueue<Quest>(new QuestComparator());

        for (int i = 0; i < numLine; i++) {
            String line = scanner.nextLine();
            String[] s = line.split(" ");
            if (s[0].equals("add")) {
                q.add(new Quest(Integer.parseInt(s[1]), Integer.parseInt(s[2])));
            } else {
                int x = Integer.parseInt(s[1]);
                int total = 0;
                Iterator<Quest> quest = q.iterator();
                while ((x > 0) && (quest.hasNext())) {
                    Quest item = quest.next();
                    if (item.e <= x) {
                        total += item.g;
                        x -= item.e;
                        q.remove(item);
                    }
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

    public Quest(int e, int g) {
        this.e = e;
        this.g = g;
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