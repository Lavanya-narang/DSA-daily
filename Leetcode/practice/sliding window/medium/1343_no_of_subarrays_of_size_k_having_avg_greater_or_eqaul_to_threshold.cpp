class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) 
    {
        //TC:O(N) SC:O(1)
        int i=0,j=0,sum=0,avg=0,ans=0;
        while(j<arr.size())
        {
            sum+=arr[j];
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {   
                avg=sum/k;
                if(avg>=threshold)
                {
                    ans++;
                }
                sum-=arr[i];
                i++;
                j++;
            }
        }
        return ans;
    }
};
