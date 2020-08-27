import java.util.Scanner;

public class A {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        String[] st = sc.nextLine().split("\\s+");

        String answer = "";
        for (String part : st) {
            //System.out.println(part);
            if (answer.equals("") == true) answer = part.toLowerCase();
            else answer += (" " + part.toLowerCase());
        }
        answer = answer.substring(0, 1).toUpperCase() + answer.substring(1);

        System.out.println(answer);
    }
}