#include<iostream>
using namespace std;


int main() {
  //write your code here
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int max=arr[0];
    for(int i=0;i<n;i++)
    {
        if(max<arr[i])
        {
            max=arr[i];
        }
    }
    for(int i=1;i<=max;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[j]>=i)
            {
                cout<<"*\t";
            }
            else
            {
                cout<<"\t";
            }
        }
        cout<<endl;
    }

}
