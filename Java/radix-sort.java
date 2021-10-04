import java.util.Scanner;

public class radixsort {
    static void countSort(int A[], int n, int j) {
        int B[] = new int[n];
        int Buck[] = new int[10];
        for (int i = 0; i < n; i++)
            Buck[(A[i] / j) % 10]++;
        for (int i = 1; i < 10; i++)
            Buck[i] += Buck[i - 1];

        for (int i = n - 1; i >= 0; i--) {
            B[Buck[(A[i] / j) % 10] - 1] = A[i];
            Buck[(A[i] / j) % 10]--;
        }
        for (int i = 0; i < n; i++) {
            A[i] = B[i];
        }
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int size = scan.nextInt();
        int A[] = new int[size];
        for (int i = 0; i < size; i++)
            A[i] = scan.nextInt();
        for (int j = 1; j < 1000; j *= 10)
            countSort(A, size, j);
        for (int i = 0; i < size; i++) {
            System.out.print(A[i] + " ");
        }

    }
}
