// class Solution {
// public:
//     int findLongestChain(vector<vector<int>>& pairs) {
//         if(!pairs.size()) return 0;
//         sort(pairs.begin(), pairs.end());
// 		// LIS array initialized as 1. As, every element is itself an answer
//         vector<int> lis(pairs.size(), 1);
//         int longestChainNum = 1;
// 		// Finding LIS in [0-----j]i for each 'i'
//         for(int i=1;i<pairs.size();i++){
//             for(int j=0;j<i;j++){
// 				// Condition similar to LIS
//                 if((pairs[j][1] < pairs[i][0]) && (lis[i] < lis[j] + 1)){
//                     lis[i] = lis[j] + 1;
// 					// Updating maximum
//                     longestChainNum = max(longestChainNum, lis[i]);
//                 }
//             }
//         }
//         return longestChainNum;
//     }
// };

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int a,b,x,y,i,n=pairs.size(),ans=1;
        pair<int,int> p[1010];
        for(i=0;i<n;i++){
            p[i+1]={pairs[i][1],pairs[i][0]};
        }
        sort(p+1,p+1+n);
        a=p[1].second;
        b=p[1].first;
        for(i=2;i<=n;i++){
            x=p[i].second;
            y=p[i].first;
            if(x>b){
                ans++;
                a=x;
                b=y;
            }
        }
        return ans;
	}
};
