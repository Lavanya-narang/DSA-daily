#include<iostream>
using namespace std;

int main(){
    int n1, n2;
    cin>>n1;
    int* a1 = new int[n1];
    for(int i = 0 ; i < n1; i++){
        cin>>a1[i];
    }
    
    cin>>n2;
    int* a2 = new int[n2];
    for(int i = 0 ; i < n2; i++){
        cin>>a2[i];
    }
    
    //write your code here
    int i=n1-1;
    int j=n2-1;
    int n=(n1>n2?n1:n2);
    int k=n-1;
    int sum[k];
    int c=0;
    while(k>=0)
    {
        int d=c;
        if(i>=0)
        {
            d+=a1[i];
        }
        if(j>=0)
        {
            d+=a2[j];
        }
        c=d/10;
        d=d%10;
        sum[k]=d;
        i--;
        j--;
        k--;
    }
    if(c!=0)
    {
        cout<<c<<endl;
    }
    for(int i=0;i<n;i++)
    {
        cout<<sum[i]<<endl;
    }
}
