public class HeapSort {
	
	public HeapSort() {
		
	}
	
	private void heap(int[] array, int length, int i) {
	    int left = 2*i+1;
	    int right = 2*i+2;
	    int large = i;

	    if (left < length && array[left] > array[large]) {
	        large = left;
	    }

	    if (right < length && array[right] > array[large]) {
	        large = right;
	    }

	    if (large != i) {
	        int temp = array[i];
	        array[i] = array[large];
	        array[large] = temp;
	        heap(array, length, large);
	    }
	}

	private void sort(int[] array) {
	    if (array.length == 0) return;

	    int length = array.length;
	    
	    for (int i = length / 2-1; i >= 0; i--)
	        heap(array, length, i);

	    for (int i = length-1; i >= 0; i--) {
	        int temp = array[0];
	        array[0] = array[i];
	        array[i] = temp;

	        heap(array, i, 0);
	    }
	}
	
	private int[] createIntArray(int size){
		int[] data = new int[size];
		for(int i=0; i<data.length; i++){
			data[i] = (int)(Math.random()*1000);
		}
		return data;
	}
	
	private void print(int[] data){
		for(int i=0; i<data.length; i++){
			System.out.print(data[i] + " ");
			if(i!=0 && i%40==0) System.out.println();
		}
		System.out.println("\n"); 
	}
	
	public static void main(String[] args) {
		HeapSort hs = new HeapSort();
		int[] array = hs.createIntArray(10);
		System.out.print("Array before sorting: ");
		hs.print(array);
		hs.sort(array);
		System.out.print("Array after sorting: ");
		hs.print(array);
	}
}