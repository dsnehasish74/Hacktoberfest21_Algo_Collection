#include<stdio.h>
#include<stdlib.h>
#define max 10
void floyd(int [][max],int);
int min(int,int);
int main()
{
    int n,d[max][max],i,j;
    printf("Enter the no of nodes: ");
    scanf("%d",&n);
    printf("Enter the weight matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&d[i][j]);
        }
    }
    floyd(d,n);
    printf("Distance Mtarix\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d ",d[i][j]);
        }
        printf("\n");
    }
    return 0;
}
void floyd(int d[][max],int n)
{
    int i,j,k;
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                d[i][j]=min(d[i][j],(d[i][k]+d[k][j]));
            }
        }
    }
}
int min(int a,int b)
{
    return (a>b)?b:a;
}
