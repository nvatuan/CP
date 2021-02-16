import java.util.Scanner;

public class A {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        int t = sc.nextInt();
        while (t-- > 0) {
            String st = sc.next();
            System.out.println(new StringBuilder(st).reverse().toString());
        }
    }
}