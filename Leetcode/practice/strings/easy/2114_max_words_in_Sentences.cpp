class Solution {
public:
    int mostWordsFound(vector<string>& sentences) 
    {
        int ans=0,cnt,n=sentences.size();
        for(int i=0;i<n;i++)
        {
            cnt=1;
            for(int j=0;j<sentences[i].size();j++)
            {
                if(sentences[i][j]==' ')
                {
                   cnt++;
                }
                 ans=max(ans,cnt);
            }
        }
        return ans;
    }
};
