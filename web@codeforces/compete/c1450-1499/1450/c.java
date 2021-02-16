import java.util.Scanner;

public class c {
    public static int test(int mod, char label, char[][] grid, boolean flag) {
        int chg = 0;
        for (int i=0; i < grid.length; i++) {
            for (int j=0; j < grid[i].length; j++) {
                if ( ((i+j)%3 == mod) && (grid[i][j] != '.') && (grid[i][j] != label)) {
                    chg += 1;
                    if (flag) grid[i][j] = label;
                }
            }
        }
        return chg;
    }

    public static Scanner sc = new Scanner (System.in);
    public static void solve() {
        int n = sc.nextInt();
        char[][] grid = new char[n][n];
        for (int i=0; i<n; i++) {
            String s = sc.next();
            for (int j=0; j<n; j++) grid[i][j] = s.charAt(j);
        }
        
        int totalAccum = n*n;
        int oi = 0, xi = 0;

        for (int modo = 0; modo < 3; modo ++) {
            int ochange = test(modo, 'O', grid, false);

            for (int modx = 0; modx < 3; modx ++) {
                if (modo != modx) {
                    int xchange = test(modx, 'X', grid, false);
                    if (xchange + ochange < totalAccum) {
                        totalAccum = xchange + ochange;
                        oi = modo;
                        xi = modx;
                    }
                }
            }
        }

        test(oi, 'O', grid, true);
        test(xi, 'X', grid, true);

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                System.out.print(grid[i][j]);
            }
            System.out.println("");
        }
    }
    public static void main(String[] args) {
        int t = sc.nextInt(); 
        for (int it=0; it < t; it++) solve();
    }
}