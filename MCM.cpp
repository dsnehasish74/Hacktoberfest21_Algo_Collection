#include<iostream>
using namespace std;
void paranthesis(int **para,int i,int j)
{
    if(i==j)
        cout<<"A"<<i<<" ";
    else
        {
            cout<<"( ";
            paranthesis(para,i,para[i][j]);
            paranthesis(para,para[i][j]+1,j);
            cout<<" ) ";
        }
}
int main()
{
    int n;
    cout<<"Enter the number of matrices";
    cin>>n;
    int dim[n+1];
    cout<<"Enter the dimensions: ";
    for(int i=0;i<=n;i++)
    {
        cin>>dim[i];
    }
    int cost[n+1][n+1]={0};
    int** para= new int*[n];
    for(int i=0;i<=n;i++){
        para[i] = new int[n+1];
        for(int j=0;j<=n;j++)
            para[i][j]=0;}
    for(int g=1;g<=n;g++)
        for(int i=1,j=g;j<=n;j++,i++)
        {
            if(i==j)
            {
                cost[i][j]=0;
                para[i][j]=0;
            }
            else
            {
                int m=INT_MAX;
                int p;
                for(int k=i;k<j;k++)
                {
                    int temp = cost[i][k]+cost[k+1][j]+dim[i-1]*dim[k]*dim[j];
                    if(m>temp)
                        {
                            m=temp;
                            p=k;
                        }
                }
                cost[i][j]=m;
                para[i][j]=p;
            }
        }
        cout<<endl;
        cout<<"************** Cost Matrix ****************"<<endl;
        for(int i=1;i<=n;i++){

            for(int j=1;j<=n;j++)
            {
                cout<<cost[i][j]<<" ";
            }
            cout<<endl;
            }
         cout<<endl;
        cout<<"************ paraenthesis Matrix ***********"<<endl;
        for(int i=1;i<=n;i++){

            for(int j=1;j<=n;j++)
            {
                cout<<para[i][j]<<" ";
            }
            cout<<endl;
            }
        paranthesis(para,1,4);
        return 0;
}