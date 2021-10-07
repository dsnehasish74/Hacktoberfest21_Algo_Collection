#include <stdio.h>

void selectionSort(int arr[25], int count)
{
    int i, j, position, swap;
    for (i = 0; i < (count - 1); i++)
    {
        position = i;
        for (j = i + 1; j < count; j++)
        {
            if (arr[position] > arr[j])
                position = j;
        }
        if (position != i)
        {
            swap = arr[i];
            arr[i] = arr[position];
            arr[position] = swap;
        }
    }
}

int main()
{
    int i, count, number[25];

    printf("How many elements are u going to enter?: ");
    scanf("%d", &count);

    printf("Enter %d elements: ", count);
    for (i = 0; i < count; i++)
        scanf("%d", &number[i]);

    selectionSort(number, count);

    printf("Order of Sorted elements: ");
    for (i = 0; i < count; i++)
        printf("%d\t", number[i]);
    return 0;
}