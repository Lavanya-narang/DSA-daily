#include<iostream>
using namespace std;
void reverse(int arr[],int li,int ri)
{
    while(li<ri)
    {
        int temp=arr[li];
        arr[li]=arr[ri];
        arr[ri]=temp;
        li++;
        ri--;
    }
}
void rotate(int* arr, int n, int k){
   // write your code here
   k%=n;
   if(k<0)
   {
       k+=n;
   }
   reverse(arr,0,n-k-1);
   reverse(arr,n-k,n-1);
   reverse(arr,0,n-1);
    
}

void display(int* arr, int n){
    for(int i = 0 ; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n, r;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0 ; i < n; i++){
        cin>>arr[i];
    }
    cin>>r;
    
    rotate(arr,n,r);
    display(arr,n);
}
