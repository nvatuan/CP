import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;

public class d {
    static Scanner sc = new Scanner(System.in);
    
    static int H, W, sx, sy, ex, ey;
    static boolean wall[][] = new boolean[1005][1005];
    static boolean vis[][] = new boolean[1005][1005];

    static LinkedList<Integer> queueX = new LinkedList<>(),
                            queueY = new LinkedList<>(),
                            cost = new LinkedList<>();
    static int queueSize = 0;

    public static boolean crawl(int x, int y, Integer warpUsed) {
        if (vis[x][y]) return false;
        if (wall[x][y]) return false;
        vis[x][y] = true;

        if (x == ex && y == ey) return true;

        // -- try walking first
        if (crawl(x+1, y, warpUsed)) return true;
        if (crawl(x-1, y, warpUsed)) return true;
        if (crawl(x, y+1, warpUsed)) return true;
        if (crawl(x, y-1, warpUsed)) return true;

        // -- performing Warp spell
        for (int dx = -2; dx <= 2; dx++)
            for (int dy = -2; dy <= 2; dy++)
                if (!wall[x+dx][y+dy] && !vis[x+dx][y+dy]) {
                    queueX.add(x+dx);
                    queueY.add(y+dy);
                    cost.add(warpUsed + 1);
                    queueSize++;
                }
        return false;
    }

    public static void solve() {
        queueX.add(sx); queueY.add(sy);
        cost.add(0);
        queueSize = 1;
        // --
        while (queueSize > 0) {
            Integer x = queueX.pop(), y = queueY.pop(), c = cost.pop();
            queueSize--;
            //System.out.println("Crawling.. x = " + x + " y = " + y + " c = " + c);
            //
            if (crawl(x, y, c)) {
                System.out.println(c);
                return;
            }
        }
        System.out.println(-1);
    }

    public static void main(String[] args) {
        H = sc.nextInt(); W = sc.nextInt();
        sx = sc.nextInt(); sy = sc.nextInt();
        ex = sc.nextInt(); ey = sc.nextInt();
        sx += 1; sy += 1;
        ex += 1; ey += 1;

        for (int i = 0; i < 1005; i++)
            Arrays.fill(wall[i], true);

        // start at (2, 2)
        for (int i = 0; i < H; i++) {
            String s = sc.next();
            for (int j = 0; j < W; j++) {
                wall[i+2][j+2] = (s.charAt(j) == '.' ? false : true);
            }
        }
        solve();
    }
}