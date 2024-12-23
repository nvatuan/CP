import java.io.*;
import java.util.Scanner;

public class april1tiengviet {
    public static final String[][] list = {
        {"á", "ắ", "ấ", "é", "ế", "í", "ố", "ớ", "ó", "ứ", "ú", "ý"},
        {"à", "ằ", "ầ", "è", "ề", "ì", "ồ", "ờ", "ò", "ừ", "ù", "ỳ"},
        {"ã", "ẵ", "ẫ", "ẽ", "ễ", "ĩ", "ỗ", "ỡ", "õ", "ữ", "ũ", "ỹ"},
        {"ả", "ẳ", "ẩ", "ẻ", "ể", "ỉ", "ổ", "ở", "ỏ", "ử", "ủ", "ỷ"},
        {"ạ", "ặ", "ậ", "ẹ", "ệ", "ị", "ộ", "ợ", "ọ", "ự", "ụ", "ỵ"}
    };
    public static final int mapping[] = {
        1, 2, 4, 3, 5 
    };

    public static int getTonemark(String word) {
        for (int i=0; i<word.length(); i++) {
            for (int li=0; li<5; li++) {
                for (int chr=0; chr<list[li].length; chr++) {
                    String target = list[li][chr];

                    if (word.substring(i, i+1).equals(target)) return mapping[li];
                }
            }
        }
        return 0;
    }

    public static void main(String[] args) throws UnsupportedEncodingException {
        String input = "";
        Scanner sc = new Scanner(System.in);

        while (sc.hasNextLine()) { 
            input += sc.nextLine();
        }

        PrintWriter consoleOut = new PrintWriter(new OutputStreamWriter(System.out, "UTF-8"));

        String[] token = input.trim().split(" ");
        System.out.println(token.length);
        String answer = "";

        for (String word : token) {
            System.out.println(word);
            System.out.print(word.getBytes());
            System.out.print(" ");
            System.out.println("ẹ".getBytes());
            if (word.length() > 0) answer += String.valueOf(getTonemark(word));
        }
        System.out.println("");
        System.out.println(answer);
    }

}