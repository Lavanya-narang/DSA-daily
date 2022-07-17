#include<iostream>
using namespace std;
int powerLogarithmic(int x,int n)
{
    if(n==0)
    {
        return 1;
    }
    if(n%2==0)
    {
        int pl=powerLogarithmic(x,n/2);
        return pl*pl;
    }
    else
    {
        int pl=powerLogarithmic(x,n/2);
        return x*pl*pl;
    }  
}
int main()
{
    int x,n; cin>>x>>n;
    cout<<powerLogarithmic(x,n);
}
