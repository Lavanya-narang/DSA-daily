bool ssep(int arr[],int sum,int n)
{
    int arrsum=0;
    for(int i=0;i<n;i++)
    {
        arrsum+=arr[i];
    }
    if(arrsum%2!=0)
    {
        return false;
    }
    else
    {
        return ssep(arr,sum/2,n);
    }
}
