class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) 
    {
        int ans=0;
        int low=0;
        int n=answerKey.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(answerKey[i]=='F')
            {
                cnt++;
            }
            while(cnt>k)
            {
                if(answerKey[low]=='F')
                {
                    cnt--;
                }
                low++;
            }
            ans=max(ans,i-low+1);
        }
            low=0;cnt=0;
            for(int i=0;i<n;i++)
            {
                if(answerKey[i]=='T')
                {
                    cnt++;
                }
                while(cnt>k)
                {
                    if(answerKey[low]=='T')
                    {
                        cnt--;
                    }
                    low++;
                }
                ans=max(ans,i-low+1);
            }
        return ans;
    }
};
