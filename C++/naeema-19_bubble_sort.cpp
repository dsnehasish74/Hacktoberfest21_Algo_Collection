#include <stdio.h>

int main() {
  int n,i,temp;
  printf("Enter the value of n : ");
  scanf("%i",&n);
  int a[n];
  printf("Enter the %i numbers  : ",n);
  for(i=0;i<n;i++)
  {
   scanf("%i",&a[i]);
  }
  for(i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(a[i]<a[j])
      {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
      }
    }
  }
  printf("Sorted Array  \n");
  for(i=0;i<n;i++)
  {
    printf("%i   ",a[i]);
  }
  return 0;
}
