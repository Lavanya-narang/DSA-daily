// class Solution {
// public:
//     int dp[101][101];
//     bool solve(string s1,string s2,string s3,int l1,int l2,int n)
//     {
//         if(l1>=0&&l2>=0 &&dp[l1][l2]!=-1)return dp[l1][l2];
//         if(l1<0&&l2<0&&n<0)
//         {
//             return true;
//         }
        
//         if(l1>=0&&n>=0&&s1[l1]==s3[n]&&l2>=0&&s2[l2]==s3[n])
//         {
//             return dp[l1][l2]=(solve(s1,s2,s3,l1-1,l2,n-1) || solve(s1,s2,s3,l1,l2-1,n-1));
//         }
//         else if(l1>=0&&n>=0&&s1[l1]==s3[n])
//         {
//             return solve(s1,s2,s3,l1-1,l2,n-1);
//         }
//         else if(l2>=0&&n>=0&&s2[l2]==s3[n])
//         {
//            return solve(s1,s2,s3,l1,l2-1,n-1);
//         }
//         return false;
//     }
    
//     bool isInterleave(string s1, string s2, string s3) {
//         memset(dp,-1,sizeof(dp));
//         return solve(s1,s2,s3,s1.size()-1,s2.size()-1,s3.length()-1);
        
//     }

// };


class Solution {
public:
    bool f(int ind1,int ind2,int ind3,string &s1,string &s2,string &s3,vector<vector<int>>&dp){
        if(ind3<0){
            return true;
        }
        if(dp[ind1+1][ind2+1]!=-1){
            return dp[ind1+1][ind2+1];
        }
        bool take1=false,take2=false;
        if(ind1>=0 && s1[ind1]==s3[ind3]){
            take1=f(ind1-1,ind2,ind3-1,s1,s2,s3,dp);
        }
        if(ind2>=0 && s2[ind2]==s3[ind3]){
            take2=f(ind1,ind2-1,ind3-1,s1,s2,s3,dp);
        }
        return dp[ind1+1][ind2+1]=take1 || take2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.length();
        int m=s2.length();
        int k=s3.length();
        if(n+m!=k){
            return false;
        }
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(n-1,m-1,k-1,s1,s2,s3,dp);
    }
};
