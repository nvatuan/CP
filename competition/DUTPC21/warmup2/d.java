import java.io.*;
import java.util.*;

class Solve {
    int n, k, t;
    ArrayList<Integer> f0;
    int m;

    ArrayList<ArrayList<Integer>> adj;

    public Solve() {
        Reader sc = new Reader();

        n = sc.nextInt();
        k = sc.nextInt();
        t = sc.nextInt();
        f0 = new ArrayList<>();

        for (int i=0; i<k; i++) {
            int x = sc.nextInt();
            x--;
            f0.add(x);
        }
        adj = new ArrayList<>();
        for (int i=0; i<n; i++) {
            adj.add(new ArrayList<>());
        }

        m = sc.nextInt();
        for (int i=0; i<m; i++) {
            int a, b;
            a = sc.nextInt();
            b = sc.nextInt();
            a--; b--;
            adj.get(a).add(b);
            adj.get(b).add(a);
        } 
    }

    int[] IdToFx;
    public void run() {
        IdToFx = new int[n];
        Arrays.fill(IdToFx, -1);

        LinkedList<Integer> nxt, nxtLabel;
        nxt = new LinkedList<>();
        nxtLabel = new LinkedList<>();

        for (Integer x : f0) {
            nxt.addLast(x);
            nxtLabel.addLast(0);
        }

        while (!nxt.isEmpty()) {
            Integer curr = nxt.removeFirst();
            Integer currLbl = nxtLabel.removeFirst();

            if (currLbl > t) continue;
            if (IdToFx[curr] != -1) continue;
            IdToFx[curr] = currLbl;

            for (int neighbor : adj.get(curr)) {
                if (IdToFx[neighbor] == -1) {
                    nxt.addLast(neighbor);
                    nxtLabel.addLast(currLbl + 1);
                }
            }
        }

        PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));
        for (int i=0; i<n; i++) {
            writer.print(IdToFx[i]);
            writer.print(" ");
        }
        writer.println("");
        writer.flush();
    }

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


public class d {
    public static void main(String[] args) {
        new Solve().run();
    }
}
