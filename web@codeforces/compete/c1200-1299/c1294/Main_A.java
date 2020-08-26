import java.lang.*;
import java.util.*;

public class Main_A {
	public static void solve(int n, int a, int b, int c) {
		if ( (n + a + b + c) % 3 == 0 ) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] num = new int[4];
		//
		for(int t = sc.nextInt(); t > 0; t--) {
			for (int i = 0; i < 4; i++) num[i] = sc.nextInt();
			solve(num[0], num[1], num[2], num[3]);
		}
	}
}

