// class Solution {
// public:
//     vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) 
//     {
//         int n=A.size();
//        vector<int>ans(n); 
//        for(int i=0;i<A.size();i++)
//        {
//            bool flag=false;
//            for(int j=0;j<B.size();j++)
//            {
//                if(A[i]==B[j])
//                {
//                    flag=true;
//                }
//                if(flag==true and j>=i)
//                 {
//                     ans[j]++;
//                 }
//            }
//        }
//        return ans;
//     }
// };

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) 
    {
        int n=A.size();
       vector<int>ans(n); 
       vector<int>freq(n+1);
       int cnt=0;
       for(int i=0;i<n;i++)
       {
           freq[A[i]]++;
           if(freq[A[i]]==2)
           {
               cnt++;
           }
           freq[B[i]]++;
           if(freq[B[i]]==2)
           {
               cnt++;
           }
           ans[i]=cnt;
       }
       return ans;
    }
};
