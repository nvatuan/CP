import java.util.*;
import java.io.*;

public class TemplateOld { 
    public static void main(String[] args) {
        Reader in = new Reader();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        // ------------------ WRITE CODE HERE ---------------------
        /*
        int     n = in.nextInt(); long  l = in.nextLong();
        float   f = in.nextFloat(); double d = in.nextDouble();
        String  st = in.next();     String s = in.nextLine();
        
        int result = 69;
        out.println(result);
        */
        long a = in.nextInt(), b = in.nextInt(), c = in.nextInt();
        System.out.println(a * (b+c));

        // --------------- YOUR PROGRAM STOPS HERE ---------------
        out.close();
    }

    public static PrintWriter out;

    public static class Reader {
        BufferedReader   br;
        StringTokenizer  st;

        public Reader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        float nextFloat() {
            return Float.parseFloat(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}
