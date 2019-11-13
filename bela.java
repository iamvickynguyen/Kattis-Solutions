import java.util.Scanner;

public class bela {

    public static int total(String[][] cards, String dominant) {
        int count = 0;
        for (int k = 0; k < cards.length; k++) {
            String number = cards[k][0];
            String value = cards[k][1];
            if (value.equals(dominant)) {
                switch (number) {
                case "A":
                    count += 11;
                    break;
                case "K":
                    count += 4;
                    break;
                case "Q":
                    count += 3;
                    break;
                case "J":
                    count += 20;
                    break;
                case "T":
                    count += 10;
                    break;
                case "9":
                    count += 14;
                    break;
                default:
                }

            } else {
                switch (number) {
                case "A":
                    count += 11;
                    break;
                case "K":
                    count += 4;
                    break;
                case "Q":
                    count += 3;
                    break;
                case "J":
                    count += 2;
                    break;
                case "T":
                    count += 10;
                    break;
                default:
                }
            }

        }
        return count;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String[] line1 = scan.nextLine().split(" ");

        int rows = Integer.parseInt(line1[0]) * 4;
        String[][] cards = new String[rows][rows];
        for (int i = 0; i < rows; i++) {
            cards[i] = scan.nextLine().split("");
        }

        System.out.println(total(cards, line1[1]));

    }

}