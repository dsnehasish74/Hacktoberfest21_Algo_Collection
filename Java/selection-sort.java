import java.util.Arrays;
import java.util.Scanner;

public class SelectionSort {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int l = in.nextInt();
        int[] arr = new int[l];
        int start=0;
        for(int i=0;i<l;i++) {
            arr[i] = in.nextInt();
        }
        for(int i=0;i<l;i++){
            int last=l-1-i;
            int maxi = maximum(arr,start,last);
            swap(arr,maxi,last);
        }
        System.out.println(Arrays.toString(arr));


    }
    static int maximum(int[] arr, int start, int end){
        int max=start;
        for(int i=start;i<=end;i++){
            if(arr[i]>arr[max]){
                max=i;
            }
        }
        return max;
    }
    static void swap(int[] arr,int maxi,int last){
        int temp=arr[maxi];
        arr[maxi]=arr[last];
        arr[last]=temp;
    }
}
