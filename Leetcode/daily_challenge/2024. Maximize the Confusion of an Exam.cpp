// class Solution {
// public:
//     int maxConsecutiveAnswers(string answerKey, int k) 
//     {
//         int ans=0;
//         int low=0;
//         int n=answerKey.size();
//         int cnt=0;
//         for(int i=0;i<n;i++)
//         {
//             if(answerKey[i]=='F')
//             {
//                 cnt++;
//             }
//             while(cnt>k)
//             {
//                 if(answerKey[low]=='F')
//                 {
//                     cnt--;
//                 }
//                 low++;
//             }
//             ans=max(ans,i-low+1);
//         }
//             low=0;cnt=0;
//             for(int i=0;i<n;i++)
//             {
//                 if(answerKey[i]=='T')
//                 {
//                     cnt++;
//                 }
//                 while(cnt>k)
//                 {
//                     if(answerKey[low]=='T')
//                     {
//                         cnt--;
//                     }
//                     low++;
//                 }
//                 ans=max(ans,i-low+1);
//             }
//         return ans;
//     }
// };







// class Solution {
// public:
//     int maxConsecutiveAnswers(string answerKey, int k) {
//         int i = 0;
//         int j = 0;

//         string str = answerKey;
        
//         int n = answerKey.size();
        
//         int tCount = 0;
//         int fCount = 0;
//         int ans = 0;

//         while(j<n)
//         {
//            if(answerKey[j] == 'T') tCount++;
//            while(i<j && tCount>k){
//             if(answerKey[i] == 'T') {
//                  tCount--;
//             }
//             i++;
//            }
//            ans = max(ans,j-i+1);
//            j++;
//         }

//         j = 0;
//         i = 0;

//         int ans2 = 0;
//         while(j<n)
//         {
//            if(str[j] == 'F') fCount++;
//            while(i<j && fCount>k){
//             if(str[i] == 'F') {
//                  fCount--;
//             }
//             i++;
//            }
//            ans2 = max(ans2,j-i+1);
//            j++;
//         }

//         return max(ans2, ans);
//     }
// };




class Solution {
public:
     int maxConsecutiveAnswers(string s, int k){
         return max(solve(s,k,'T'),solve(s,k,'F'));
     }
     int solve(string s,int k,char c){
         int i=0;
         int count=0;
         int j=0;
         int ans=0;
         while(j<s.length()){
             if(s[j]==c){
                 count++;
             }
             while(count>k){
                 if(s[i]==c){
                     count--;
                 }
                 i++;
             }
             ans=max(ans,j-i+1);
             j++;
         }
         return ans;
     }
};
