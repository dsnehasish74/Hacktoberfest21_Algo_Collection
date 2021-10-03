#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int compare=0;

int* generateUD(int size,int mean,int width)
{
    int start,end;
    start=mean-width;
    end=mean+width;
    int* a=malloc(size*sizeof(int));
    srand(time(0));
    for(int i=0;i<size;i++)
    {
        a[i]=rand()%(end-start+1)+start;
    }
    return a;
}

int* generateND(int mean, int width, int size)
{
    srand(time(0));
    int* a = malloc(size * sizeof(int));
    int n = 10;
    int start,end;
    start = mean-width;
    end = mean+width;
    for (int i=0; i<size; i++)
    {
        a[i] = 0;
        for (int j = 0; j < n; j++)
            a[i] += (rand() % (end - start + 1)) + start;
        a[i] /= n;
    }
    return a;
}

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2) {
		compare++;
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}
void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}
void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int main()
{
	printf("Uniform Dataset\n");
	
	//int *arr=generateUD(128,10,10);
	int arr_size =65536;

	//printf("Given array is \n");
	//printArray(arr, arr_size);

	clock_t start, end;
    double cpu_time_used=0;
	start = clock();
	int avg=655360/arr_size;
	for(int i=0;i<avg;i++)
	{
		int *arr=generateND(10,10,arr_size);
		mergeSort(arr, 0, arr_size - 1);
	}
	end = clock();
	cpu_time_used = ((double) (end) - (double)(start)) / CLOCKS_PER_SEC;
	cpu_time_used/=(double)avg;
	compare/=avg;
	printf("Execution time:%f units\n",cpu_time_used*1000);
	printf("Comparisons:%d\n",compare);
	/*printf("Normal Dataset\n");

	int *arr2=generateND(10,10,10);
	int arr_size2 = 10;

	printf("Given array is \n");
	printArray(arr2, arr_size2);

	mergeSort(arr2, 0, arr_size2 - 1);

	printf("\nSorted array is \n");
	printArray(arr2, arr_size2);*/
	return 0;
}
