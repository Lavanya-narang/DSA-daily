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
    int ceil=-1;
    int floor=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==data)
        {
            ceil=data;
            floor=data;
            break;
        }
        else if(arr[mid]<data)
        {
            ceil=arr[mid];
            low=mid+1;
        }
        else
        {
            floor=arr[mid];
            high=mid-1;
        }
    }
    cout<<floor<<endl;
    cout<<ceil<<endl;
}
