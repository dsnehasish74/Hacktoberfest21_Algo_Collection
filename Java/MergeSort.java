// Java program to perform Merge Sort algorithm on a array
public class MergeSort
{
    static void mergeSort(int arr[],int l,int r)
    {
        if(r>l)
        {
            int mid = l+(r-l)/2;
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            merge(arr,l,mid,r);
        }
    }

    static void merge(int arr[],int l,int m,int r)
    {
        int l1 = m+1-l;
        int l2 = r-m;
        int[] arr1 = new int[l1];
        int[] arr2 = new int[l2];
        int i = 0,j = 0;
        for(int f=0;f<l1;f++)
        {
            arr1[f] = arr[l+f];
        }
        for(int f=0;f<l2;f++)
        {
            arr2[f] = arr[m+1+f];
        }
        int k = l;
        while(i<l1 && j<l2)
        {
            if(arr1[i]<arr2[j])
            {
                arr[k] = arr1[i];
                k++;
                i++;
            }
            else
            {
                arr[k] = arr2[j];
                k++;
                j++;
            }
        }
        while(i<l1)
        {
            arr[k] = arr1[i];
            i++;
            k++;
        }
        while(j<l2)
        {
            arr[k] = arr2[j];
            j++;
            k++;
        }
    }

    public static void main(String[] args) {
        int arr[] = {10,9,8,7,6,5,4,3,2,1};
        mergeSort(arr,0,arr.length-1);
        for(int num: arr)
            System.out.print(num + " "); 
    }
}