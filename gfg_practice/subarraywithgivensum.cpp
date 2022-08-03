        vector<int> ans;
        int cursum=arr[0];
        int start=0;
        for(int i=1;i<=n;i++)
        {
            while(cursum>s && start<i-1)
            {
                cursum=cursum-arr[start];
                start++;
            }
            if(cursum==s)
            {
                ans.push_back(start+1); //position = index + 1
                ans.push_back(i-1+1); 
                return ans;
            }
            if(i<n)
            {
                cursum=cursum+arr[i];
            }
            
        }
        ans.push_back(-1);
        return ans;
