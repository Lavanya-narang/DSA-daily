// class Solution {
// public:
// 	int minimumDeleteSum(string s1, string s2) {
// 		int n=s1.size();
// 		int m=s2.size();
// 		int sum1=0,sum2=0;
// 		for(auto i:s1) sum1+=i;
// 		for(auto i:s2) sum2+=i;
// 		vector<int> prev(m+1,0),curr(m+1,0);
// 		for(int i=1;i<=n;i++){
// 			for(int j=1;j<=m;j++){
// 				if(s1[i-1]==s2[j-1]) curr[j]=s1[i-1]+prev[j-1];
// 				else curr[j]=max(prev[j],curr[j-1]);
// 			}   
// 			prev=curr;
// 		}
// 		return (sum1+sum2)-2*prev[m];
// 	}
// };
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        
        int m=s1.size(), n=s2.size();
        int dp[m+1][n+1]; dp[0][0]=0;
        for(int i=1;i<=m;i++){
            dp[i][0]= dp[i-1][0] + s1[i-1];
        }
        for(int j=1;j<=n;j++){
            dp[0][j] = dp[0][j-1] + s2[j-1];
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=  min(dp[i-1][j] + s1[i-1] ,dp[i][j-1] + s2[j-1]);
                }
            }
        }
       
        return dp[m][n];
    }
};
