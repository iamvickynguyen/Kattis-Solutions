import java.util.Scanner;

public class bijele {

    public static void main(String[] args) {
        Scanner obj = new Scanner(System.in);
        String[] line = obj.nextLine().split(" ");
        String out = "";
        out += (1 - Integer.parseInt(line[0])) + " ";
        out += (1 - Integer.parseInt(line[1])) + " ";
        out += (2 - Integer.parseInt(line[2])) + " ";
        out += (2 - Integer.parseInt(line[3])) + " ";
        out += (2 - Integer.parseInt(line[4])) + " ";
        out += (8 - Integer.parseInt(line[5]));
        System.out.println(out);
    }
}