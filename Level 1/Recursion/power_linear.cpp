#include<iostream>
using namespace std;
int power(int x,int n)
{
     if(n==0)
    {
        return 1; 
    }
    int nm1=power(x,n-1);
    return nm1*x;
}
int main()
{
    int n,x; cin>>x>>n;
    cout<<power(x,n);
}
