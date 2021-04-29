import java.util.*;
import java.io.*;

public class F_MatrixExpr {
    static Integer n, m, k;
    public static Matrix Ma;

    public static void main(String[] args) {
        Reader in = new Reader();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        // --
        n = in.nextInt();
        k = in.nextInt(); 
        m = in.nextInt();

        Ma = new Matrix(n);
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++){
                int v = in.nextInt();
                Ma.set(i, j, v);
            }
        }

        solve(k).print(out);
        // --
        out.close();
    }

    public static Matrix solve(int pwr) {
        if (pwr == 1) return Ma;
        Matrix rs = solve(pwr/2);
        Matrix matPwr = Ma.raiseTo((pwr+1)/2, m);

        rs = rs.add(rs.multiply(matPwr, m), m);
        if ( (pwr&1) > 0 ) rs = rs.add(matPwr, m);
        return rs;
    }

    public static class Matrix {
        public int N;
        public ArrayList<ArrayList<Integer>> A;

        public Matrix(){}
        public Matrix(int s, boolean isIdentity) {
            N = s;
            A = new ArrayList<ArrayList<Integer>>();
            for (int i=0; i<N; i++) {
                A.add(new ArrayList<Integer>());
                for (int j=0; j<N; j++)
                    A.get(i).add(0);
            }

            if (isIdentity)
                for (int i=0; i<N; i++) A.get(i).set(i, 1);
        }
        public Matrix(int s) {
            N = s;
            A = new ArrayList<ArrayList<Integer>>();
            for (int i=0; i<N; i++) {
                A.add(new ArrayList<Integer>());
                for (int j=0; j<N; j++)
                    A.get(i).add(0);
            }
        }

        public int get(int x, int y) {
            return A.get(x).get(y);
        }
        public void set(int x, int y, int v) {
            A.get(x).set(y, v);
        }

        public void print(PrintWriter out) {
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) out.print(this.get(i, j)+" ");
                out.println("");
            }
        }

        public void copy(Matrix m) {
            N = m.N;
            A = new ArrayList<ArrayList<Integer>>(N);
            for (int i=0; i<N; i++) {
                A.add(new ArrayList<Integer>());
                for (int j=0; j<N; j++)
                    A.get(i).add(0);
            }

            for (int i=0; i<N; i++)
                for (int j=0; j<N; j++)
                    this.set(i, j, m.get(i, j));
        }
        
        public Matrix add(Matrix m, int mod) {
            Matrix rs = new Matrix (N, false);
            for (int i=0; i<n; i++)
                for (int j=0; j<n; j++){
                    int v = this.get(i, j) + m.get(i, j);
                    v %= mod;
                    rs.set(i, j, v);
                }
            return rs;
        }

        public Matrix multiply(Matrix m, int mod) {
            Matrix rs = new Matrix (N, false);
            for (int i=0; i<n; i++)
                for (int j=0; j<n; j++){
                    int v = rs.get(i, j);
                    for (int k=0; k<n; k++) {
                        v += this.get(i, k) * m.get(k, j);
                        v %= mod;
                    }
                    rs.set(i, j, v);
                }
            return rs;
        }

        HashMap<Integer, Matrix> MatRaise2n = null;

        public Matrix raiseTo(int exp, int mod) {
            if (MatRaise2n == null) {
                MatRaise2n = new HashMap<>();

                int p = 1;
                Matrix tmp = new Matrix();
                tmp.copy(this);

                while (p < 1073741824) {
                    MatRaise2n.put(p, tmp);

                    tmp = tmp.multiply(tmp, mod);
                    p <<= 1;
                }
            }

            Matrix rs = new Matrix(N, true);

            for (int ib=0; ib<30; ib++) {
                if ( (exp&(1<<ib)) > 0 ) {
                    rs = rs.multiply(MatRaise2n.get(1<<(ib)), mod);
                }
            }
            return rs;
        }
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
