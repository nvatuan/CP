import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class A_BigNumMultiply {
    public static void main(String[] args) {
        Reader in = new Reader();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        // --

        String a = in.next();
        String b = in.next();
        BigInteger f1 = new BigInteger(a);
        BigInteger f2 = new BigInteger(b);

        out.println(f1.multiply(f2));

        // --
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
