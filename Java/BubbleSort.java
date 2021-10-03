import java.util.Arrays;
import java.util.Scanner;

public class BubbleSort {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int len=in.nextInt();
        int[] arr=new int[len];
        for(int i=0;i<len;i++){
            arr[i]=in.nextInt();
        }
        System.out.println(Arrays.toString(arr));
        sorting(arr,len);
        System.out.println(Arrays.toString(arr));

    }
    static void sorting(int[] arr,int len){
        int temp;
        boolean swapped;
        for(int i=0;i<len;i++){
            swapped=false;
            for(int j=1;j<=len-1-i;j++){
                if(arr[j-1]>arr[j]){
                 temp=arr[j-1];
                 arr[j-1]=arr[j];
                 arr[j]=temp;
                 swapped=true;
                }
            }
            if(!swapped){
                break;
            }
        }

    }
}
