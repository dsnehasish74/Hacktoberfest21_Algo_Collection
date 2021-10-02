
#include <iostream>
#include <cmath>
#define MAX 1000000.0
using namespace std;


struct Point
{
	int x, y;
};


double min(double x, double y)
{
	return (x <= y)? x : y;
}

double dist(Point p1, Point p2)
{
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) +
				(p1.y - p2.y)*(p1.y - p2.y));
}

// A utility function to find cost of a triangle. The cost is considered
// as perimeter (sum of lengths of all edges) of the triangle
double cost(Point points[], int i, int j, int k)
{
	Point p1 = points[i], p2 = points[j], p3 = points[k];
	return dist(p1, p2) + dist(p2, p3) + dist(p3, p1);
}

double mTCDP(Point points[], int n)
{

if (n < 3)
	return 0;

double table[n][n];

for (int gap = 0; gap < n; gap++)
{
	for (int i = 0, j = gap; j < n; i++, j++)
	{
		if (j < i+2)
		{
			table[i][j] = 0.0;
			//s[i][j]=0.0;
		}
		else
		{
			table[i][j] = MAX;
			//s[i][j]=MAX;
			for (int k = i+1; k < j; k++)
			{
				double val = table[i][k] + table[k][j] + cost(points,i,j,k);
				if (table[i][j] > val)
				{
					table[i][j] = val;
					//s[i][j]=k;
				}
			}
		}
	}
}
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<i;j++)
    {
        cout<<"- ";
    }
    for(int j=i;j<n;j++)
    {
      cout<<table[i][j]<<" ";
    }
    cout<<"\n";
  }
  cout<<"\n";
//   printf("\n");
// 	for (int i = 0; i < n; i++)
// 	{
// 		for (int j = 0; j < i; j++)
// 		{
// 			printf("- ");
// 		}
// 		for (int j = i; j < n; j++)
// 		{
// 			printf("%d ", s[i][j]);
// 		}
// 		printf("\n");
// 	}
return table[0][n-1];
}

// Driver program to test above functions
int main()
{
	Point points[] = {{0, 0}, {6, 0}, {0, 6}, {6, 8}, {8, 6}};
	int n = sizeof(points)/sizeof(points[0]);
	cout<<"Table alongwith the final result are : \n"<<endl;
	cout << mTCDP(points, n);
	return 0;
}