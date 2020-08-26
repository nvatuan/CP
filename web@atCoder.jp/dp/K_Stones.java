import java.util.Scanner;

public class K_Stones {
    static Scanner sc = new Scanner(System.in);

    public static void main (String[] args) {
        int N; N = sc.nextInt();
        int K; K = sc.nextInt();
        
        int[] A = new int[N];
        for (int i = 0; i < N; i++) A[i] = sc.nextInt();

        int[] nim = new int[K + 1];
        for (int i = 0; i <= K; i++) nim[i] = 0;

        for (int k = 0; k < K; k++)
            if (nim[k] == 0)
                for (int i = 0; i < N; i++)
                    if (k + A[i] <= K) 
                        if (nim[k + A[i]] == 0)
                            nim[k + A[i]] = 1;

        System.out.println(nim[K] == 1 ? "First" : "Second");
    }
}