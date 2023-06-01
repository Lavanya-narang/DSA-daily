class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) 
    {
         int cnt=0;
       
        for(int i=0;i<arr1.size();i++)
        {
             bool flag=1;
            for(int j=0;j<arr2.size();j++)
            {
                if(abs(arr1[i]-arr2[j])<=d)
                {
                    flag=0;
                }
            }
            if(flag==1)
            {
                cnt++;
            }
        }
        return cnt;
    }
};



class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) 
    {
        int ans=0;
        int n=arr1.size(),m=arr2.size();
        
        sort(arr2.begin(),arr2.end());
        for(int i=0;i<n;i++)
        {
            int low=0,high=m-1;
            while(low<=high)
            {
                
                int mid=low+(high-low)/2;
                if(abs(arr1[i]-arr2[mid])<=d)
                {
                    break;
                }
                if(arr2[mid]<arr1[i])
                {
                   low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
            }
            if(low>high)
            {
                ans++;
            }
        }
        return ans;
    }
};
