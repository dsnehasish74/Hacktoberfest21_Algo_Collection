#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
       int a,b,c,d,e,f,g=0,s=0;
        cin>>a>>b>>c>>d>>e>>f;
        if((a+b+c)>(d+e+f))
        {
           cout<<1<<"\n";
        }
        if((a+b+c)<(d+e+f))
        {
           cout<<2<<"\n";       
        }
    }
	return 0;
}
