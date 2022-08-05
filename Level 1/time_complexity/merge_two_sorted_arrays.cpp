#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeTwoSortedArrays(vector<int> &A, vector<int> &B)
{
    int i=0,j=0,k=0;
    int n=A.size();
    int m=B.size();
    vector<int> arr(n+m,0);
    while(i<n && j<m)
    {
        if(A[i]<B[j])
        {
            arr[k]=A[i];
            i++;
            k++;
        }
        else
        {
            arr[k]=B[j];
            j++;
            k++;
        }
    }
    while(i<A.size())
    {
        arr[k]=A[i];
        i++;
        k++;
    }
    while(j<B.size())
    {
        arr[k]=B[j];
        j++;
        k++;
    }
    return arr;
}

void input(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

void output(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    int n, m;
    cin >> n;
    vector<int> A(n, 0);
    input(A);

    cin >> m;
    vector<int> B(m, 0);
    input(B);

    vector<int> ans = mergeTwoSortedArrays(A, B);
    output(ans);
    return 0;
}
