import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;

import java.util.HashMap;
import java.util.TreeSet;
import java.lang.Comparable;

public class e {
    int H, W, M;
    HashMap<Integer, Integer> bombsOnRow, bombsOnCol;

    class Pair implements Comparable<Pair> {
        public Integer a, b;
        public Pair(Integer aa, Integer bb) { a = aa; b = bb; }

        @Override
        public int compareTo(Pair o) {
            if (this.a == o.a) return this.b.compareTo(o.b);
            else return this.a.compareTo(o.a);
        }

        public boolean equals(Pair o) {
            return (this.a.compareTo(o.a) == 0 && this.b.compareTo(o.b) == 0);
        }
    }
    TreeSet<Pair> targets = new TreeSet<>();

    void solve() {
        input();

        Integer ans = 0;
        int maxBombOnRow = 0;
        Integer row = 0;
        for (Integer key : bombsOnRow.keySet()) {
            Integer bomb = bombsOnRow.get(key);
            if (maxBombOnRow <= bomb) {
                maxBombOnRow = bomb;
                row = key;
            }
        }
        for (Integer key : bombsOnCol.keySet()) {
            ans = Math.max(ans,
                maxBombOnRow + bombsOnCol.get(key) -
                (targets.contains(new Pair(row, key)) ? 1 : 0) 
            );
        }
        System.out.println(ans);
    }

    void input() {
        Reader in = new Reader();
        bombsOnCol = new HashMap<Integer, Integer>();
        bombsOnRow = new HashMap<Integer, Integer>();
        H = in.nextInt(); W = in.nextInt(); M = in.nextInt();
        for (int a, b, i = 0; i < M; i++) {
            a = in.nextInt(); b = in.nextInt();
            bombsOnRow.put(a, bombsOnRow.getOrDefault(a, 0) + 1);
            bombsOnCol.put(b, bombsOnCol.getOrDefault(b, 0) + 1);
            targets.add(new Pair(a, b));
        }
    }

    public static void main(String[] args) {
        try {
            new e().solve();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
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