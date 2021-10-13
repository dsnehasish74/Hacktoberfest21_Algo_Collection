import java.util.Arrays;
import java.util.Scanner;
 
public class hamiltonianCycle {
    int count;
    int path = 1;
 
    void swap(int[] arr, int x, int y) {
        int temp = arr[x];
        arr[x] = arr[y];
        arr[y] = temp;
    }
 
    void permute(int[] arr, int[][] G) {
        permute(arr, 0, arr.length - 1, G);
    }
 
    void permute(int[] arr, int i, int n, int[][] cost) {
        int j;
 
        if (i == n) {
            HamilCycle(arr, cost);
        } else {
            for (j = i; j <= n; j++) {
                swap(arr, i, j);
                permute(arr, i + 1, n, cost);
                swap(arr, i, j);
            }
        }
    }
 
    void HamilCycle(int a[], int[][] G) {
        count = 0;
 
        for (int i = 0; i < a.length - 1; i++) {
            if (G[a[i]][a[i + 1]] != 0)
                count++;
        }
 
        if (count == a.length - 1 && G[a[a.length - 1]][a[0]] == 1) {
            System.out.print("Cycle No " + path + "----> ");
 
            for (int i = 0; i < a.length; i++)
                System.out.print(a[i] + " ");
            System.out.print(a[0]);
            System.out.println();
            path++;
        }
    }
 
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
 
        System.out.println("Enter the number of nodes in graph: ");
 
        int n = s.nextInt();
 
        int graph[][] = new int[n][n];
 
        System.out.println("Enter the adjacency matrix");
 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = s.nextInt();
            }
 
        }
        int arr[] = new int[n];
 
        for (int i = 0; i < n; i++)
            arr[i] = i;
 
        System.out.println("All possible Hamiltonian Cycles in graph");
        new hamiltonianCycle().permute(arr, graph);
 
    }
 
}
