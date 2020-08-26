import java.lang.*;
import java.util.*;

public class Main {
	public static void solve(int n, int a, int b, int c) {
		int equal = (n+a+b+c)/3;
		if (equal*3 == (n+a+b+c) && equal >= a && equal >= b && equal >= c) {
			System.out.println("YES");
			return;
		}
		System.out.println("NO");

	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] num = new int[4];
		//
		for(int t = sc.nextInt(); t > 0; t--) {
			for (int i = 0; i < 4; i++) num[i] = sc.nextInt();
			solve(num[3], num[1], num[2], num[0]);
		}
	}
}

