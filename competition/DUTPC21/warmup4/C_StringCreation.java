import java.util.*;
import java.io.*;

public class C_StringCreation {
    static boolean chooseLeft(String s, int l, int r) {
        if (l >= r) return true; 
        if (s.charAt(l) == s.charAt(r)) return chooseLeft(s, l+1, r-1);
        if (s.charAt(l) < s.charAt(r)) return true;
        return false;
    }

    public static void main(String[] args) {
        Reader in = new Reader();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        // --

        int n = in.nextInt();
        String s = in.next();

        String t = "";

        int l=0, r=n-1;
        while (l <= r) {
            if (chooseLeft(s, l, r)) {
                t += s.charAt(l);
                l++;
            } else {
                t += s.charAt(r);
                r--;
            }
        }

        out.println(t);

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
