import java.util.*;
import java.io.*;

public class B_CutRope {
    public static void main(String[] args) {
        Reader in = new Reader();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        // --

        int n, k;
        double[] arr;

        n = in.nextInt();
        k = in.nextInt();
        arr = new double[n];
        for (int i=0; i<n; i++) arr[i] = in.nextDouble();

        double hi=100001.0, lo=0.01;
        for (int times=0; times < 100; times++) {
            double mid = (hi + lo) / 2;
            System.err.println("Mid=" + mid);
            long counter = 0;

            for (int i=0; i<n; i++) {
                counter += (long)(arr[i] / mid);
            }

            if (counter >= k) lo = mid;
            else hi = mid;
        }

        out.println(lo);
        out.printf("%.2f\n", lo);

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