class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) 
    {
        vector<int>ans(s.length());
        for(int i=0;i<s.length();i++)
        {
            int x=startPos[0],y=startPos[1];
            int cnt=0;
            for(int j=i;j<s.length();j++)
            {
                    if(s[j]=='R')
                    {
                        y++;
                    }
                     if(s[j]=='L')
                    {
                        y--;
                    }
                     if(s[j]=='U')
                    {
                        x--;
                    }
                     if(s[j]=='D')
                    {
                        x++;
                    }
                if(x<0 || y<0 ||x>=n ||y>=n)
                {
                    break;
                }
                else
                {
                    cnt++;
                }
            }
            ans[i]=cnt;
        }
        return ans;
    }
};
