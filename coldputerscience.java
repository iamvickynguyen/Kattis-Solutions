import java.util.Scanner;
import java.util.stream.*;

public class coldputerscience {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            scanner.nextLine();
            Long coldDays = Stream.of(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt)
                    .filter(temp -> temp < 0).count();
            System.out.println(coldDays);
        }
    }
}
