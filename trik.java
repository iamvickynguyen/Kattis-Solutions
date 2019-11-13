import java.util.Scanner;
public class trik{
    public static int trik(char x, int pos){
        if(x=='A'){
            if(pos==1) return 2;
            if(pos==2) return 1;
            else return 3;
        }
        if(x=='B'){
            if(pos==2) return 3;
            if(pos==3) return 2;
            else return 1;
        }
        if(x=='C'){
            if(pos==1) return 3;
            if(pos==3) return 1;
            else return 2;
        }
        return 0;
    }

    public static int output(String a){
        int o = 1;
        for(int i=0; i< a.length() ; i++){
            o = trik(a.charAt(i), o);
        }
        return o;

    }

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        String abc = scanner.nextLine();

        System.out.println(""+output(abc));

    }
}