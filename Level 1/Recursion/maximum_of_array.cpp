#include <iostream>
using namespace std;
int max(int arr[], int idx, int n)
{
    if(idx>=n)
    {
        return 0;
    }
    int m1=max(arr,idx+1,n);
    if(arr[idx]>m1)
    {
        return arr[idx];
    }
    else
    { return m1;}
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int p = max(arr, 0, n);
    cout << p << endl;
}
