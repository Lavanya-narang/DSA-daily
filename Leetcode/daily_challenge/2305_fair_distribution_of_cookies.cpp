// class Solution {
// public:
     
//    int maxi=INT_MAX;
//     void explore(vector<int>&cookies,int n,int k,vector<int>&vec)
//     {
//       if(n==cookies.size())
//       {
//           int m=0;
//           for(int i=0;i<k;i++)
//           {
//               m=max(m,vec[i]);
              
//           }
//           maxi=min(maxi,m);
//           return;
//       }
//         for(int i=0;i<k;i++)
//         {
//             vec[i]+=cookies[n];
//             explore(cookies,n+1,k,vec);
//             vec[i]-=cookies[n];
//         }
//     }
    
       
//     int distributeCookies(vector<int>& cookies, int k) {
      
//         vector<int> vec(10,0);
//           explore(cookies,0,k,vec); 
//         return maxi;
        
//     }
// };



class Solution {
public:
    int ans=INT_MAX;
    void backtrack(vector<int>&cookies, int i, vector<int>&bags){
        int z=0;
        for (int j=0;j<bags.size();j++)
            if (bags[j]==0)
                z++;
        if (z>cookies.size()-i)
            return;
        if (i==cookies.size()){
            int m=0;
            for (int j=0;j<bags.size();j++)
                m=max(m,bags[j]);
            ans=min(ans,m);
            return;
        }
        for (int j=0;j<bags.size();j++){
            bags[j]+=cookies[i];
            backtrack(cookies,i+1,bags);
            bags[j]-=cookies[i];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> bags(k,0);
        backtrack(cookies,0,bags);
        return ans;
    }
};
