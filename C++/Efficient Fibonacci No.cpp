/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;
# define lli long long int

lli I[3][3],T[3][3], a[11];
void mul(lli A[3][3],lli B[3][3],int d)
{
    lli r[d+1][d+1];
    
    for(int i=1;i<=d;i++)
    {
        for(int j=1;j<=d;j++)
        {
            r[i][j]=0;
            for(int k=1;k<=d;k++)
            {
                r[i][j] += A[i][k]*B[k][j];
            }
        }
    }
    
    for(int i=1;i<=d;i++)
    {
        for(int j=1;j<=d;j++)
        {
            A[i][j]= r[i][j];
        }
    }
}

int fib(int n)
{
        I[1][1]=I[2][2]=1;
        I[1][2]=I[2][1]=0;
        
        T[1][1]=0;
        T[1][2]=T[2][2]=T[2][1]=1;
        
        while(n)
        {
            if(n%2)
            {
                mul(I,T,2);
                n--;
            }
            else
            {
                mul(T,T,2);
                n=n/2;
            }
        }
        
        lli ans= a[1]*I[1][1] + a[2]*I[2][1];
        return ans;
}
int main()
{
    a[1]=1;
    a[2]=1;
    
    lli res=fib(9);
    cout<<res;

    return 0;
}

