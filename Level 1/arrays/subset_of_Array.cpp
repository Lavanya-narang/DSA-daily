#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int main()
{
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0 ; i < n; i++){
        cin>>arr[i];
    }
    // write your code here
    int limit = int(pow(2,n));
    for(int i=0;i<limit;i++)
    {
        string set="";
        int temp=i;
        for(int j=n-1;j>=0;j--)
        {
            int rem=temp%2;
            temp=temp/2;
            if(rem==0)
            {
                set="-\t"+set;
            }
            else
            {
                string str=to_string(arr[j]);
                set=str+"\t"+set;
            }
        }
        cout<<set<<endl;
    }
}
