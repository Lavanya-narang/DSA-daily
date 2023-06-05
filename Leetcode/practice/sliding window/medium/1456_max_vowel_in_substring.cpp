class Solution {
public:
    int maxVowels(string s, int k) 
    {
        int ans=0;
        int n=s.length();
        int mn=INT_MIN;
        int j=0;
       int i=0;
        while(j<n)
        {
            if(s[j]=='a'|| s[j]=='e'|| s[j]=='u'|| s[j]=='i'|| s[j]=='o')
            {
              ans++;
            }
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                mn=max(ans,mn);
                if(s[i]=='a'|| s[i]=='e'|| s[i]=='u'|| s[i]=='i'|| s[i]=='o')
                {
                    ans--;
                }
                i++;
                j++;
            }
        }
        return mn;
    }
};
