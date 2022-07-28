#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0 ; i < n; i++){
        cin>>arr[i];
    }
    int data;
    cin>>data;
    
    // write your code here
    int low=0;
    int high=n-1;
    int fi=-1;
    int li=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]>data)
        {
            high=mid-1;
        }
        else if(arr[mid]<data)
        {
            low=mid+1;
        }
        else
        {
            fi=mid;
            high=mid-1;
        }
    }
    low=0;
    high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]>data)
        {
            high=mid-1;
        }
        else if(arr[mid]<data)
        {
            low=mid+1;
        }
        else
        {
            li=mid;
            low=mid+1;
        }
    }
    cout<<fi<<endl;
    cout<<li<<endl;
    
}
