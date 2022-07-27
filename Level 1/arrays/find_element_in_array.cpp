#include<iostream>
using namespace std;
int findelement(int* arr,int n,int d)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==d)
        {
            return i;
        }
    }
    return -1;
}

int main(){
    //write your code here
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int d;
    cin>>d;
    cout<<findelement(arr,n,d)<<endl;
}
