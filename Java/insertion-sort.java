import java.util.Arrays;


public class InsertionSort {
    public static void main(String[] args){

        int[] array = {1,1,1,1,1,1};

        insertion(array);
        System.out.println(Arrays.toString(array));
    }
    static void insertion(int[] array){
        int temp;
        for(int i=0;i<array.length-1;i++){
            for(int j=i+1;j>0;j--){
                if(array[j]<array[j-1]){
                 temp=array[j];
                 array[j]=array[j-1];
                 array[j-1]=temp;
                }
                else {
                    break;
                }
            }
        }
    }
}
