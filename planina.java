import java.util.Scanner;
public class planina{
    public static int point(int line){
        return (line+1)*(line+1);
    }

    public static int planina(int line, int iter, int n){
            if(iter==n) return point(line);
            return planina(line*2, iter+1, n);
            // return point(line*2);  
    }

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        System.out.println(planina(1,0, n));
    }
}