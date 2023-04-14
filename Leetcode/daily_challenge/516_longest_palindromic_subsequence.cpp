class Solution {
public:
//recursive solution
//tc:o(2^n)
bool ispalindrome(string s)
{
    int i=0,j=s.size()-1;
    while(i<=j)
    {
        if(s[i]!=s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
    int solve(string& s,string s1,int ind)
    {
        if(ind>=s.size())
        {
            if(ispalindrome(s1))
            {
                return s1.size();
            }
             else
            {
                return 0;
            }
        }
       int ans1=solve(s,s1+s[ind],ind+1);
       int ans2=solve(s,s1,ind+1);
       return max(ans1,ans2);
    }
    int longestPalindromeSubseq(string s) 
    {
          return solve(s,"",0);
    }
};


//memoisation
class Solution 
 {
 public:
 //tc:o(n^2) sc:o(n^2)
 int dp[1001][1001];
 int solve(string& s,int i,int j)
 {
     if(i>j)
     {
         return 0;
     }
     if(i==j)
     {
         return 1;
     }
     if(dp[i][j]!=-1)
     {
         return dp[i][j];
     }
     if(s[i]==s[j])
     {
         dp[i][j]=solve(s,i+1,j-1)+2;
     }
     else
     {
         dp[i][j]=max(solve(s,i+1,j),solve(s,i,j-1));
     }
     return dp[i][j];
 }
     int longestPalindromeSubseq(string s) 
     {    
         memset(dp,-1,sizeof(dp));
         return solve(s,0,s.size()-1);
     }
 };
